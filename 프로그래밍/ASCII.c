#include <stdio.h>

int main(void)
{
   char ch1, ch2;

   printf("문자를 입력하세요 : ");
   scanf("%c", &ch1);
   getchar();
   scanf("%c", &ch2);
   printf("%c의 ASCII 코드 값은 %d이고 %c의 ASCII 코드 값은 %d입니다.\n", ch1, ch1, ch2, ch2);

   printf("=====================================================");
   printf("\n");

   rewind(stdin); 

   printf("문자를 입력하세요 : ");
   scanf("%c", &ch1);
   getchar();
   scanf("%c", &ch2);
   printf("%c의 ASCII 코드 값은 %d이고 %c의 ASCII 코드 값은 %d입니다.\n", ch1, ch1, ch2, ch2);

   return 0;
}
