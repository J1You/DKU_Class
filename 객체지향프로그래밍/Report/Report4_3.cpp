#include<iostream>
using namespace std;
template <class X> int find(X object, X* list, int size) // 템플리트 함수
{
	int t = -1; // t를 -1로 초기화
	for (int i = 0; i < size; i++)
	{
		if (list[i] == object) // list[i]와 object가 같다면
			t = i; 
	}
	return t; // t반환
}
int main()
{
	int _size, * a, find_int; 
	float* b, find_float;
	char* c, find_char;

	cout << "size 입력: ";
	cin >> _size; // size 입력
	a = new int[_size]; // 정수형 동적할당생성
	cout << "정수입력: ";
	for (int i = 0; i < _size; i++)
	{
		cin >> a[i]; // _size만큼 정수 입력
	}
	cout << "탐색할값: ";
	cin >> find_int; // 탐색할 값 입력
	cout << "첨자: " << find(find_int, a, _size) << endl; // 출력

	cout << "size 입력: ";
	cin >> _size;
	b = new float[_size]; // 실수형 동적할당생성
	cout << "실수입력: ";
	for (int i = 0; i < _size; i++)
	{
		cin >> b[i]; //_size만큼 실수 입력
	}
	cout << "탐색할값: ";
	cin >> find_float; // 탐색할 값 입력
	cout << "첨자: " << find(find_float, b, _size) << endl; // 출력

	cout << "size 입력: ";
	cin >> _size;
	c = new char[_size]; // 문자형 동적할당생성
	cout << "문자입력: ";
	for (int i = 0; i < _size; i++)
	{
		cin >> c[i]; // _size만큼 문자 입력
	}
	cout << "탐색할값: ";
	cin >> find_char; // 탐색할 값 입력
	cout << "첨자: " << find(find_char, c, _size) << endl; // 출력
	delete[]a; delete[]b; delete[]c; //동적할당 모두 해제
	return 0;
}
