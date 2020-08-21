/*
// 사각형 면적 
#include <iostream>
#include <math.h>
using namespace std;
class rectangle {
private:
	int x1, x2;
	int y1, y2;
public:
	rectangle(int i1, int j1, int i2, int j2) {
		x1 = i1; x2 = i2;
		y1 = j1; y2 = j2;
	}
	int area();
	int largearea(rectangle rect);
};
int rectangle::area()
{
	return abs(x2 - x1) * abs(y2 - y1);
}
int rectangle::largearea(rectangle rect)
{
	int a = abs(x2 - x1) * abs(y2 - y1);
	int b = abs(rect.x2 - rect.x1) * abs(rect.y2 - rect.y1);
	if (a > b) return a;
	else return b;
}
int main()
{
	rectangle r1(1, 1, 3, 4), r2(-1, -2, 1, -5);
	cout << "사각형1의 면적= " << r1.area() << endl;
	cout << "더 큰 사각형의 면적= " << r1.largearea(r2) << endl;
	return 0;
}
*/
