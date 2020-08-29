#include<iostream>
using namespace std;

double divide(double a, double b)
{
	try {
		if (!b)
			throw exception("Cannot divide by zero!");
		else
			cout << "Quotient is " << a / b << "\n";
	}
	catch (exception e) {
		cout << "Cannot divide by zero!" << "\n";
	}

	return a / b;
}

int main()
{
	double a, b;

	cout << "Enter numerator and denominator: ";
	cin >> a >> b;

	divide(a, b);

	return 0;
}
