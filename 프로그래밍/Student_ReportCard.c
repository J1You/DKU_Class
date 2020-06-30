#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int std_mid[30] = { 60,11,36,42,31,72,19,50,44,23,40,66,41,40,39,68,70,52,65,31,28,30,45,59,53,34,64,41,63,59 };
	int std_fin[30] = { 32,35,19,15,32,50,13,32,20,19,26,59,41,21,45,63,82,69,84,25,28,31,90,59,50,36,40,33,45,69 };
	char std_name[30][7] = { "강덕호", "고기태","곽호철","이도현","박동균","최동민","한명수","김승호","김은미","김태성",
	"김준형","김민","박태수","박병채","민현우","서인수","신인규","성재훈","심동현","윤승한","김재박","임기현","이수복",
	"이원호","석주명","이범석","전호진","정광민","조영민","홍정모" };
	int i, j, k, l, temp;
	int order[30] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int sum[30] = { 0, };
	char std_grade[30][3] = { 0, };
	char tempstr[9];

	printf("==============================================\n");
	printf("학생의 이름\t중간고사 점수\t기말고사 점수\n");
	printf("==============================================\n");
	printf("\n");
	for (i = 0; i <= 29; i++) {
		printf("%s\t\t%d\t\t%d\n", std_name[i], std_mid[i], std_fin[i]);
	}
	printf("==============================================\n");
	printf("\n");

	for (j = 0; j <= 29; j++) {
		sum[j] = std_mid[j] + std_fin[j];
	}

	for (k = 0; k <= 29; k++) {
		for (l = 0; l <= 29; l++) {
			if (sum[k] < sum[l]) {
				order[k]++;
			}
		}
	}
	for (i = 0; i <= 29; i++) {
		if (order[i] <= 3) {
			strcpy(std_grade[i], "A+");
		}
		else if (order[i] <= 6) {
			strcpy(std_grade[i], "A ");
		}
		else if (order[i] <= 12) {
			strcpy(std_grade[i], "B+");
		}
		else if (order[i] <= 18) {
			strcpy(std_grade[i], "B ");
		}
		else if (order[i] <= 21) {
			strcpy(std_grade[i], "C+");
		}
		else if (order[i] <= 24) {
			strcpy(std_grade[i], "C ");
		}
		else if (order[i] <= 25.5) {
			strcpy(std_grade[i], "D+");
		}
		else if (order[i] <= 27) {
			strcpy(std_grade[i], "D ");
		}
		else {
			strcpy(std_grade[i], "F ");
		}
	}
	printf("=====================================================================\n");
	printf("학생의 이름\t중간고사 점수\t기말고사 점수\t 석차\t 최종성적\n");
	printf("=====================================================================\n");
	printf("\n");
	for (i = 0; i <= 29; i++) {
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%s\n", std_name[i], std_mid[i], std_fin[i], order[i], std_grade[i]);
	}
	printf("=====================================================================\n");
	printf("\n");

	for (i = 0; i <= 29; i++) {
		for (j = 0; j <= 28; j++) {
			if (order[j] > order[j + 1]) {
				temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;

				temp = std_mid[j];
				std_mid[j] = std_mid[j + 1];
				std_mid[j + 1] = temp;

				temp = std_fin[j];
				std_fin[j] = std_fin[j + 1];
				std_fin[j + 1] = temp;

				strcpy(tempstr, std_name[j]);
				strcpy(std_name[j], std_name[j + 1]);
				strcpy(std_name[j + 1], tempstr);

				strcpy(tempstr, std_grade[j]);
				strcpy(std_grade[j], std_grade[j + 1]);
				strcpy(std_grade[j + 1], tempstr);
			}
		}
	}
	printf("=====================================================================\n");
	printf("학생의 이름\t중간고사 점수\t기말고사 점수\t 석차\t 최종성적\n");
	printf("=====================================================================\n");
	printf("\n");
	for (j = 0; j <= 29; j++) {
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%s\n", std_name[j], std_mid[j], std_fin[j], order[j], std_grade[j]);
	}
	printf("=====================================================================\n");
	printf("\n");
	system("pause");

	return 0;
}