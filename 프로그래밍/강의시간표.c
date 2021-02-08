#define _CRT_SECURE_NO_WARNINGS   
#include<stdio.h>
#include <string.h>
char scadule[15][5][20] = { "\0\0", "\0\0" ,"\0\0" ,"\0\0" ,"\0\0" };
struct info {

	char** day;
	int* stime, * etime;
	char subject[20], Pname[20];
	int class, grade, freq;
};

void show(char start_d[], char end_d[], int start, int end) { //기본프레임 함수
	int s, e;
	char day[5][3] = { "월","화","수","목","금" };

	for (int i = 0; i < 5; i++) {

		if (strcmp(start_d, day[i]) == 0)
			s = i;
		if (strcmp(end_d, day[i]) == 0)
			e = i;
	}
	printf("----------------------------------------\n");
	for (int i = s; i <= e; i++) {
		printf(" \t%s", day[i]);
	}
	printf("\n");
	printf("----------------------------------------\n");
	for (int i = start; i <= end; i++) {
		printf("%d\n", i);
		printf("----------------------------------------\n");
	}
}

void show2(char start_d[], char end_d[], int start, int end, struct info p) { //과목입력

	char day[5][3] = { "월","화","수","목","금" };
	int s, e;
	for (int i = 0; i < 5; i++) {
		if (strcmp(start_d, day[i]) == 0)
			s = i;
		if (strcmp(end_d, day[i]) == 0)
			e = i;
	}
	printf("----------------------------------------\n");
	for (int i = s; i <= e; i++) {
		printf("\t %s", day[i]);
	}
	printf("\n");
	printf("----------------------------------------\n");

	int f = 0;
	for (int i = start; i <= end; i++) {
		for (int j = 0; j < p.freq; j++) {
			int ttime = p.stime[j] + p.etime[j] - 1;
			if (p.stime[j] <= i && i <= ttime) {
				for (int k = 0; k < 5; k++) {
					if (strcmp(p.day[j], day[k]) == 0)
						strcpy(scadule[f][k], p.subject);
				}
			}
		}
		printf("%d", i);
		for (int j = s; j <= e; j++) {
			printf("\t%c%c%c%c", scadule[f][j][0], scadule[f][j][1], scadule[f][j][2], scadule[f][j][3]);
		}

		printf("\n");
		printf("----------------------------------------\n");

		f++;
	}

}

void drop(char start_d[], char end_d[], int start, int end, struct info p) //과목삭제
{
	char day[5][3] = { "월","화","수","목","금" };
	int s, e;
	for (int i = 0; i < 5; i++) {
		if (strcmp(start_d, day[i]) == 0)
			s = i;
		if (strcmp(end_d, day[i]) == 0)
			e = i;
	}
	printf("----------------------------------------\n");
	for (int i = s; i <= e; i++) {
		printf("\t %s", day[i]);
	}
	printf("\n");
	printf("----------------------------------------\n");

	int f = 0;

	for (int i = start; i <= end; i++) {
		for (int j = 0; j < p.freq; j++) {
			int ttime = p.stime[j] + p.etime[j] - 1;
			if (p.stime[j] <= i && i <= ttime) {
				for (int k = 0; k < 5; k++) {
					if (strcmp(p.day[j], day[k]) == 0)
						strcpy(scadule[f][k], "    ");
				}
			}
		}

		printf("%d", i);
		for (int j = s; j <= e; j++) {
			printf("\t%c%c%c%c", scadule[f][j][0], scadule[f][j][1], scadule[f][j][2], scadule[f][j][3]);
		}

		printf("\n");
		printf("----------------------------------------\n");

		f++;
	}
}


int main() {

	int st, et;
	char sd[3], ed[3];
	printf("input your Startday, Endday : ");
	scanf("%s", sd);
	scanf("%s", ed);
	printf("input your Starttime, Endtime : ");
	scanf("%d %d", &st, &et);
	show(sd, ed, st, et);
	struct info inp[8];
	int i = 0, n;
	char c[2];
	while (1)
	{
		printf("[시간표] 1. 과목입력  2. 과목삭제  0. 종료\n");
		scanf("%d", &n);
		if (n == 1) {
			gets(c);
			printf("과목명 : ");
			gets(inp[i].subject);
			printf("교수명 : ");
			gets(inp[i].Pname);
			printf("강의실 : ");
			scanf("%d", &inp[i].class);
			printf("학점 : ");
			scanf("%d", &inp[i].class);
			printf("주당강의횟수 : ");
			scanf("%d", &inp[i].freq);
			inp[i].day = (char*)malloc(sizeof(char) * inp[i].freq);
			for (int j = 0; j < inp[i].freq; j++)
				inp[i].day[j] = (char*)malloc(sizeof(char) * 3);
			inp[i].stime = (int*)malloc(sizeof(char) * inp[i].freq);
			inp[i].etime = (int*)malloc(sizeof(char) * inp[i].freq);

			for (int k = 0; k < inp[i].freq; k++) {
				gets(c);
				printf("<강의%d>\n", k + 1);
				printf("강의요일 : ");
				gets(inp[i].day[k]);
				printf("시작시간 : ");
				scanf_s("%d", &inp[i].stime[k]);
				printf("강의시간 : ");
				scanf_s("%d", &inp[i].etime[k]);
			}

			show2(sd, ed, st, et, inp[i]);
			i++;
		}
		if (n == 2) {
			char sn[20];
			gets(c);
			printf("과목명: ");
			gets(sn);
			for (int j = 0; j < i; j++) {

				if (strcmp(inp[j].subject, sn) == 0) {

					drop(sd, ed, st, et, inp[j]);
					for (int k = j; k < i - 1; k++)
						inp[k] = inp[k + 1];
					break;
				}
			}
			i--;
		}
		if (n == 0) {
			printf("프로그램 종료합니다.");
			return 0;
		}
	}
}