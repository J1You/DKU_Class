
#include <stdio.h>

int fibonacci(int a)
{
	if (a == 0) {
		return 0;
	}
	else if (a == 1) {
		return 1;
	}
	else {
		return fibonacci(a - 1) + fibonacci(a - 2);
	}
}

int main()
{
	int i=0;
	for (;;) {
		fibonacci(i);
		if (fibonacci(i) >= 1000) {
			break;
		}
		i++;
	}
	printf("%d", fibonacci(i-1));
	return 0;
}

