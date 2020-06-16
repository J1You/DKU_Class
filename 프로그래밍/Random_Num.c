#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int lotto[6];
	srand(time(NULL));

	printf("** 로또 추첨을 시작합니다. **\n\n");
	printf("추첨된 로또 번호 ==> ");

	for (int i = 0; i < 6; i++) {
		lotto[i] = rand() % 45 + 1; // 1~45 난수를 생성하여 배열에 저장

		for (int j = 0; j < i; j++) {
			if (lotto[i] == lotto[j]) {
				i--; // 생성된 난수가 이전에 저장된 난수와 중복될 경우 반복 되돌림.
			}
		}

	}
	for (int i = 0; i < 6; i++) {
		printf("%d ", lotto[i]); // 배열에 저장된 난수 출력
	}
	return 0;
}