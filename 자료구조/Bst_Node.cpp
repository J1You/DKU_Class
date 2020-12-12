#include <iostream>
using namespace std;

class BstNode; // 전방선언
class Bst
{
private:
	BstNode* root;
public:
	Bst() { root = 0; }  // 생성자 함수
	BstNode* IterSearch(const int& x);  // 탐색 함수
	bool Insert(const int& x); // 삽입 함수
	bool Delete(const int& x);  // 삭제 함수 
	void Inorder();  // 중위우선순회 함수
	void Inorder(BstNode* currentNode);  // 중위우선순회 함수
};

class BstNode
{
	friend Bst;  // friend 선언
private:
	BstNode* leftChild;
	BstNode* rightChild;
	int data;
public:
	BstNode(int element = 0, BstNode* left = 0, BstNode* right = 0) {  // 생성자 함수
		data = element;
		leftChild = left;
		rightChild = right;
	}
};


BstNode* Bst::IterSearch(const int& x) {  // 탐색 함수
	for (BstNode* t = root; t;) {
		if (x == t->data) return t;  // x값이 이진트리에 존재
		if (x < t->data) t = t->leftChild;
		else t = t->rightChild;
	}
	return 0;
}

bool Bst::Insert(const int& x) {  // 삽입 함수
	BstNode* p = root; BstNode* q = 0;
	while (p) {  // 삽입할 위치의 노드 p, p의 전 노드 q
		q = p;
		if (x == p->data) return false;
		if (x < p->data) p = p->leftChild;
		else p = p->rightChild;
	}  
	p = new BstNode;  // 새로운 노드 생성
	p->leftChild = p->rightChild = 0;
	p->data = x;
	if (!root) root = p; 
	else if (x < q->data) q->leftChild = p;
	else q->rightChild = p;  // 노드 연결을 통한 삽입
	return true;
}

bool Bst::Delete(const int& x) {  // 삭제 함수
	BstNode* p = root; BstNode* q = 0;
	while (p) {  // 삭제할 노드 p, p의 전 노드 q
		if (x == p->data) break;
		q = p;
		if (x < p->data) p = p->leftChild;
		else  p = p->rightChild;
	}  
	if (!p) {  // 삭제할 노드가 없을 경우
		cout << "삭제할 노드가 없습니다." << endl;
		return false;
	}  
	else if (p->leftChild != 0 && p->rightChild != 0) {  // 2개의 자식 노드가 있을 경우
		BstNode* t, * s;
		for (t = p->rightChild, s = p;;) {  // 오른쪽 서브트리에서 가장 작은 노드 t, t의 전 노드 s
			if (!t->leftChild) break;
			s = t;
			t = t->leftChild;
		}  
		t->leftChild = p->leftChild;
		if(p->rightChild!=t) t->rightChild = p->rightChild;
		if (p == root) root = t;
		else if (q->leftChild == p) q->leftChild = t;
		else q->rightChild = t;
		if(p!=s) s->leftChild = 0;  //  p의 위치를 t로 대체하여 이진트리 연결
		delete p;  // 노드 삭제
	}
	else if (p->leftChild == 0 && p->rightChild == 0) {  // 자식 노드가 없는 경우
		if (p == root) root = 0;
		else if (q->leftChild == p) q->leftChild = 0;
		else q->rightChild = 0;  // p 위치를 0으로 대체해여 이진트리 연결
		delete p;  // 노드 삭제
	}
	else {  // 1개의 자식 노드가 있는 경우
		if (p == root) {
			if (p->leftChild) root = p->leftChild;
			else root = p->rightChild;
		}
		else if (q->leftChild == p) {
			if (p->leftChild) q->leftChild = p->leftChild;
			else q->leftChild = p->rightChild;
		}
		else {
			if (p->leftChild) q->rightChild = p->leftChild;
			else q->rightChild = p->rightChild;
		}  // p의 위치를 p의 자식 노드로 대체하여 이진트리 연결
		
		delete p; // 노드 삭제
	}
	return true;
}

void Bst::Inorder()  // 중위우선순회 함수
{
	Inorder(root);
}

void Bst::Inorder(BstNode* currentNode)  // 중위우선순회 함수
{
	if (currentNode) {
		Inorder(currentNode->leftChild);  // 왼쪽 자식으로 이동
		cout << currentNode->data << ' ';  // data 출력
		Inorder(currentNode->rightChild);  // 오른쪽 자식으로 이동
	}
	
}

int main() {
	Bst bst;
	int menu, n, x;
	cout << "---------------------- 이진탐색트리 ----------------------"<<endl;
	cout << "(1) 삽입  (2) 삭제  (3) 탐색  (4) 중위우선순회  (0) 종료" << endl;

	while (1)
	{
		cout << "메뉴입력 >>";
		cin >> menu;
		switch (menu)
		{
		case 1:  // 1 입력 시 삽입 함수 호출
			cout << "입력할 키의 개수 입력 >> ";
			cin >> n;
			cout << "삽입할 값 입력 >> ";
			for (int i = 0; i < n; i++) {
				cin >> x;
				bst.Insert(x);
			}
			break;
		case 2:  // 2 입력 시 삭제 함수 호출
			cout << "삭제할 값 입력 >> ";
			cin >> x;
			bst.Delete(x);
			break;
		case 3:  // 3 입력 시 탐색 함수 호출
			cout << "탐색할 값 입력 >> ";
			cin >> x;
			if (bst.IterSearch(x) == 0) cout << x << " -> 탐색 실패" << endl;
			else cout << x << " -> 탐색 성공" << endl;
			break;
		case 4:  // 4 입력 시 중위우선순회 함수 호출
			cout << "중위우선순회 결과: ";
			bst.Inorder();
			cout << endl;
			break;
		case 0:  // 5 입력 시 프로그램 종료
			return 0;
		}
	}
	return 0;
}