#include <iostream>
using namespace std;

class coord {
private:
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int& i, int& j) { i = x; j = y; }
	friend coord operator- (coord op1, coord op2); // -연산자중복
	friend coord operator/ (coord op, coord op2); // /연산자중복
};

coord operator-(coord op1, coord op2)
{
	coord temp;
	temp.x = op1.x - op2.x;
	temp.y = op1.y - op2.y;
	return temp;
} // - 중복연산자 정의

coord operator/(coord op1, coord op2)
{
	coord temp;
	temp.x = op1.x / op2.x;
	temp.y = op1.y / op2.y;
	return temp;
} // /중복연산자 정의

int main()
{
	coord a(6, 8), b(3, 2), c; // 3개 객체 생성
	int xx, yy;
	c = a - b;
	c.get_xy(xx, yy); // 뺀 결과 저장
	cout << "-의 결과(x,y): " << xx << ',' << yy << endl; // 뺀 결과 출력
	c = a / b;
	c.get_xy(xx, yy); // 나눈 결과 저장
	cout << "/의 결과(x,y): " << xx << ',' << yy << endl; // 나눈 결과 출력
	return 0;
}