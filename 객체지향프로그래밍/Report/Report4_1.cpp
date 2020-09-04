/*#include <iostream>
#include <math.h>
using namespace std;

class Distance {
private:
	double x, y;
public:
	Distance() { x = 0; y = 0; } // 생성자
	Distance(double a, double b) { x = a; y = b; }
	virtual double trav_time() {
		double t;
		t = abs(y - x) / 60;
		return t;
	} // mile단위 시간을 계산하는 가상함수
};

class metric :public Distance{ // 파생클래스 metric
private:
	double x, y;
public:
	
	metric(double a, double b) { x = a; y = b; } // 생성자
	double trav_time() {
		double t;
		t = abs(y - x) / 100;
		return t;
	} // km단위 시간을 계산하는 함수 오버라이드
};

int main()
{
	Distance mile(10, 20); // mile로 계산할 클래스 호출
	metric km(10, 20); // km로 계산할 클래스 호출
	cout << "(마일단위)시간: " << mile.trav_time() << endl; // mile단위 시간출력
	cout << "(킬로미터 단위)시간: " << km.trav_time() << endl; // km단위 시간출력
	return 0;
}

*/