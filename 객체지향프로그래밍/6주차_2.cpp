#include <iostream>
using namespace std;

class box {
private:
	double x, y, z;
	double volume;
public:
	void setbox(double a, double b, double c);
	void calcvolume();
	int vol();
};

void box::setbox(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void box::calcvolume()
{
	volume = x * y * z;
}

int box::vol()
{
	return volume;
}

int main()
{
	double a, b, c;
	box mybox;
	cin >> a >> b >> c;
	mybox.setbox(a, b, c);
	mybox.calcvolume();
	cout << "ºÎÇÇ: " << mybox.vol();
	return 0;
}