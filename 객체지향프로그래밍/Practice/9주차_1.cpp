/*
//원점 거리 계산

#include <iostream>
#include <math.h>
using namespace std;

class point {
private:
	int x, y;
public:
	point(int i, int j)
	{
		x = i, y = j;
	}
	double origin_distance();
};

double point :: origin_distance()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
int main()
{
	point p1(3, 4), p2(-1, -5);
	cout << "p1의 원점거리= " << p1.origin_distance() << endl;
	cout << "p2의 원점거리= " << p2.origin_distance() << endl;
	return 0;
}
*/