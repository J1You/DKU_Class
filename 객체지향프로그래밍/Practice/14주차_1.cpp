#include <iostream>
using namespace std;

class box {
private:
	double l, w, h;
public:
	box() { l = w = h = 0; }
	box(double a, double b, double c) { l = a; w = b; h = c; }
	void vol() { cout << "ºÎÇÇ: " << l * w * h << "\n";}
	friend box add_box(box o1, box o2);
	box operator*(box o1);
	box operator=(box o2);
};

box add_box(box o1, box o2)
{
	box temp;
	temp.l = o1.l + o2.l;
	temp.w = o1.w + o2.w;
	temp.h = o1.h + o2.h;
	return temp;
}

box box::operator*(box o1)
{
	box temp;
	temp.l = l * o1.l;
	temp.w = o1.w * o1.w;
	temp.h = o1.h * o1.h;
	return temp;
}

box box::operator=(box o2)
{
	l = o2.l;
	w = o2.w;
	h = o2.h;
	return *this;
}

int main()
{
	box x(3.0, 2.0, 1.0), y(1.0, 2.0, 3.0), z;
	z = add_box(x, y); z.vol();
	z = x * y; z.vol();
	return 0;
}
