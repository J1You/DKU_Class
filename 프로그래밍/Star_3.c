#include <stdio.h>

int main(void) {

	char blank = ' ';
	char star = '*';
	int i, j, k;

	for (i = 1; i < 5; i++) {
		for (j = 1; j <= 10 - i; j++) {
			printf("%c", blank);
		}
		for (k = 1; k <= i * 2 - 1; k++) {
			printf("%c", star);
		}
		printf("\n");
	}
	for (i = 5; i > 0; i--) {
		for (j = 1; j <= 10 - i; j++) {
			printf("%c", blank);
		}
		for (k = 1; k <= i * 2 - 1; k++) {
			printf("%c", star);
		}
		printf("\n");
	}

	return 0;
}