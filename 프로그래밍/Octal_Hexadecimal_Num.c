#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x, y;
	printf("8진수와 16진수를 순서대로 입력하세요 :  ");
	scanf_s("%o" "%x", &x, &y);
	printf("\n%o(8) + %x(16) = %d(10)\n", x, y, x + y);

	system("pause");
	return 0;
}