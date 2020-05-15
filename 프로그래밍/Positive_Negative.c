#include <stdio.h>
int main()
{
	int a[10]; // 배열선언
	int negative=0, positive=0, zero=0; // 음수,양수,0 의 개수 초기화
	
	printf("10개의 원소를 입력하세요:\n");
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
	} //배열 입력

	for (int i = 0; i < 10; i++) {
		if (a[i] < 0) {
			negative++; // 배열의 값이 0보다 작으면 음수개수 +1
		}
		else if (a[i] > 0) {
			positive++; // 배열의 값이 0보다 크면 양수개수 +1
		}
		else {
			zero++; // 배열의 값이 0이면 0의개수 +1
		}
	} 

	printf("입력된 배열: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]); // 입력된 배열 출력
	}
	printf("\n");
	printf("양수=%d개, 음수=%d개, 0=%d개\n",positive, negative, zero); // 양수, 음수, 0의 개수 출력
	return 0;
}