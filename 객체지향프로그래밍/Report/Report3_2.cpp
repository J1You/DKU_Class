/*#include <iostream>
using namespace std;

class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int& i, int& j) { i = x; j = y; }
	bool operator== (coord op); // ==중복연산자
	bool operator&& (coord op); // &&중복연산자
	
};

bool coord::operator==(coord op) 
{
	if ((x == op.x) && (y == op.y))
		return true;
	else
		return false;
} // x와 op.x 그리고 y와 op.y가 일치하면 true, 그렇지 않으면 false 반환

bool coord::operator&&(coord op)
{
	return ((x && op.x) && (y && op.y));
} // 모두 참이면 참, 하나라도 거짓이면 거짓 반환

int main()
{
	coord a(3, 3), b(4, 4); // 2개 객체 생성
	cout << "==연산결과: " << (a == b) << endl; //== 결과(참/거짓) 출력
	cout << "&&연산결과: " << (a && b) << endl; // && 결과(참/거짓) 출력
	return 0;
}*/