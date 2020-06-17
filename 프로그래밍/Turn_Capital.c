#include <stdio.h>
int main()
{
	char text[100];
	printf("텍스트를 입력하시오 : ");
	gets(text); // 배열에 문자열 입력

	for (int i = 0; text[i] ; i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			text[i] = text[i] - 32; // 아스키코드 값을 이용해 소문자를 대문자로 변환
		}
	} // 문자열이 끝날 때까지 반복

	printf("대문자 출력: %s",text) // 변환된 문자열 출력
	return 0;

}