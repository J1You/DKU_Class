#include <stdio.h>

int main(void) {

	char star = '*';
	char blank = ' ';
	int i, k, j;

	for (i = 1; i < 10; i++) {
		printf("%c", star);
	}
	printf("\n");
	for (k = 1; k < 8; k++) {
		printf("%c", star);
		for (j = 1; j < 8; j++) {
			printf("%c", blank);
		}
		printf("%c", star);
		printf("\n");
	}
	for (i = 1; i < 10; i++) {
		printf("%c", star);
	}

	return 0;
}