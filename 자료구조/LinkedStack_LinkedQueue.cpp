#include <iostream>
using namespace std;

class LinkedStack;   // 연결스택 전방선언
class LinkedQueue;   // 연결큐 전방선언

class ChainNode {
	friend class LinkedStack;
	friend class LinkedQueue;
private:
	int data;
	ChainNode* link;
public: 
	ChainNode(int element = 0, ChainNode* next = 0) {   
		data = element; link = next;   // 생성자
	}
};

class LinkedStack {
private:
	ChainNode *top;
public:
	LinkedStack() { top = 0; }   // 생성자
	void Push(const int&);   // 연결스택 삽입함수
	int* Pop(int&);   // 연결스택 삭제함수
	void Show();   // 연결스택 출력함수
};
void LinkedStack::Push(const int& e) {
	top = new ChainNode(e, top);  // 새 노드를 top에 저장 
}
int* LinkedStack::Pop(int& x) {
	if (top == 0) return 0;  // 스택이 비어있을 경우
	ChainNode* delNode = top;
	x = top->data;   // top노드의 데이터를 x에 저장
	top = top->link;   // top을 다음 노드로 이동  
	delete delNode;   // 마지막 노드 삭제
	return &x;
}
void LinkedStack::Show() {
	ChainNode* p;
	if (top == 0) {
		cout << "--빈 스택--" << endl;   // 스택이 비어있을 경우
	}
	else {
		cout << "스택(LIFO 순): ";
		for (p = top; p->link; p = p->link) {   // p가 top부터 다음노드로 이동
			cout << p->data << ' ';   // p의 데이터 출력
		}
		cout << p->data << endl;   // 마지막 노드의 데이터 출력 
	}
}

class LinkedQueue {
private:
	ChainNode *front;
	ChainNode *rear;
public:
	LinkedQueue() { front = rear = 0; }   // 생성자
	void Push(const int&);   // 연결큐 삽입함수
	int* Pop(int&);   // 연결큐 삭제함수
	void Show();   // 연결큐 출력함수
};
void LinkedQueue::Push(const int& e) {
	if (front == 0) front = rear = new ChainNode(e, 0);  // 큐가 비어있을 경우 삽입
	else rear = rear->link = new ChainNode(e, 0);  // 새 노드 삽입하고 rear 지정
}
int* LinkedQueue::Pop(int& x) {
	if (front == 0) return 0;   // 큐가 비어있을 경우
	ChainNode* delNode = front;
	x = front->data;   // 맨 앞 노드의 데이터 x에 저장
	front = front->link;   // front를 다음 노드로 이동
	delete delNode;   // 맨 앞 노드 삭제
	return &x;
}
void LinkedQueue::Show() {
	ChainNode* p;
	if (front == 0) {
		cout << "--빈 큐--" << endl;   // 큐가 비어있을 경우
	}
	else {
		cout << "큐(FIFO 순): ";
		for (p = front; p; p = p->link) {  // p가 front부터 다음노드로 이동
			cout << p->data << ' ';   // p의 데이터 출력
		}
		/*cout << p->data << endl;   // 마지막 노드의 데이터 출력 */
	}
}

void main()
{
	LinkedStack stack;   // 연결스택 객체 생성
	LinkedQueue queue;   // 연결큐 객체 생성
	int menu, s, q;
	cout << "---------------메뉴--------------" << endl;
	cout << "1. 스택에 삽입     2. 큐에 삽입" << endl;
	cout << "3. 스택에서 삭제   4. 큐에서 삭제" << endl;
	cout << "5. 스택 내용 보기  6. 큐 내용 보기" << endl;
	cout << "\n";
	while (1) {
		cout << "입력: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cin >> s;
			stack.Push(s);  // 연결스택에 삽입
			break;
		case 2:
			cin >> q;
			queue.Push(q);  // 연결큐에 삽입
			break;
		case 3:
			stack.Pop(s);  // 연결스택에서 삭제
			break;
		case 4:
			queue.Pop(q);  // 연결큐에서 삭제
			break;
		case 5:
			stack.Show();  // 연결스택 출력
			break;
		case 6:
			queue.Show();  // 연결큐 출력
			break;
		
		}
	}
}
