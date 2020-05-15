#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int n, random;
	int min = 100, max = 1; // 변수 min 에 최댓값을, 변수 max에 최솟값을 저장
	printf("하나의 수를 입력하세요: "); 
	scanf_s("%d", &n); // 하나의 수 입력

	srand(time(NULL)); // 씨드를 시간으로 설정
	for (int i = 0; i < n; i++) {
		random = rand() % 100 + 1; // 난수 생성
		printf("랜덤으로 생성된 수: %d\n", random); // 난수 출력
		if (random > max) {
			max = random; // 발생한 난수가 max값 보다 크면 max에 난수 값 저장
		}
		if (random < min) {
			min = random; // 발생한 난수가 min값 보다 작으면 min에 난수 값 저장
		}

	}
	printf("가장 큰 수: %d\n", max); // 가장 큰 수 max 출력
	printf("가장 작은 수: %d\n", min); // 가장 작은 수 min 출력
	return 0;
}