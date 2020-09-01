/*#include <iostream>
using namespace std;

class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int& i, int& j) { i = x; j = y; }
	coord operator--(); // --중복연산자 (접두사)
	coord operator--(int notused); // --중복연산자 (접미사)
};

coord coord::operator--()
{
	x--; y--;
	return *this;
} // 접두사 --중복연산자 정의

coord coord::operator--(int notused)
{
	coord temp;
	temp = *this;
	x--; y--;
	return temp;
} // 접미사 --중복연산자 정의

int main()
{
	coord a(3, 4), b;
	int xx, yy;
	b = --a; //전치--
	a.get_xy(xx, yy);
	cout << "(접두사--) a: " << xx << ',' << yy << endl; // 전치-- 후 a결과 출력
	b.get_xy(xx, yy);
	cout << "(접두사--) b: " << xx << ',' << yy << endl; // 전치-- 후 b결과 출력
	b = a--; // 후치--
	a.get_xy(xx, yy);
	cout << "(접미사--) a: " << xx << ',' << yy << endl; // 후치-- 후 a결과 출력
	b.get_xy(xx, yy);
	cout << "(접미사--) b: " << xx << ',' << yy << endl; // 후치-- 후 b결과 출력
	return 0;
}*/