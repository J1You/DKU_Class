#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	for (int i = 2; i <= 20; i++)
	{
		cout.setf(ios::showpos);
		cout.precision(5);
		cout.width(10);
		cout.right;
		cout << log(i) << " ";
		cout.setf(ios::showpos);
		cout.precision(5);
		cout.width(10);
		cout.right;
		cout << log10(i) << '\n';
	}

	return 0;
}
