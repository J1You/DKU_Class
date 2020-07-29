#include <stdio.h>
#include <string.h>
int main()
{
	char str[7][8] = { "seoul","daejeon","daegu", "kwangju","inchon","jeju","busan" }; //이차원 배열 선언
	char temp[8];

	printf("=== 정렬하기 전 ===\n");
	for (int i = 0; i < 7; i++) {
		printf("%s  ", str[i]); // 정렬 전 문자열 배열 출력
	}
	printf("\n\n");

	for (int i = 0; i < 6; i++) {
		int index = i;  // 가장 작은 문자의 위치를 저장하는index 를 i로 초기화

		for (int j = i + 1; j < 7; j++) {
			if (strcmp(str[index], str[j]) > 0) {

				index = j;  // str[j]가 str[index]보다 작으면 index에 j를 저장 
			}
		}
		strcpy(temp, str[i]);
		strcpy(str[i], str[index]);
		strcpy(str[index], temp);

	} // 선택 정렬을 이용하여 문자열을 오름차순으로 정렬

	printf("=== 정렬한 다음 ===\n");
	for (int i = 0; i < 7; i++) {
		printf("%s  ", str[i]); // 정렬 후 문자열 배열 출력
	}
	return 0;
}
