//좌표 사이 거리
#include <iostream>
#include <math.h>
using namespace std;

class point {
private:
	int x, y;
public:
	point(int i, int j)
	{ 
	double two_distance(point a);
	friend double distance2(point a, point b);
};
double point::two_distance(point a)
{
	return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}
double distance2(point a, point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
	point p1(3, 4), p2(-1, -5);
	cout << "p1, p2 사이거리= " << p1.two_distance(p2) << endl;
	cout << "p1, p2 사이거리= " << distance2(p1, p2) << endl;
	return 0;
}
