#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	char perID[7], name[10];
	fputs("주민번호 앞 6자리를 입력하세요 : ", stdout);
	fgets(perID, sizeof(perID), stdin);

	fflush(stdin);

	fputs("이름을 입력하세요 :", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민 번호 앞자리 : %s\n", perID);
	printf("이름 : %s\n", name);

	/*char str[10];

	fputs("문자열을 입력 하세요 : ", stdout);
	fgets(str, sizeof(str), stdin);

	fputs("입력된 문자열 : ", stdout);
	fputs(str, stdout);*/


	//fputs("fputs 함수에 의한 출력, ", stdout);
	//fputs("i Love Linux ", stdout);

	//fputs("\n", stdout);

	//puts("puts 함수에 의한 출력,");
	//puts("I Love Linux ");

	/*char ch = 0;
	while (ch != EOF) {
		ch = getchar();
		putchar(ch);
	}
	printf("program 종료 \n");*/
	
	/*char ch = 0;
	while (ch != 'q') {
		ch = getchar();
		putchar(ch);
	}*/


	/*fprintf(stdout, "Hello");*/
	//int ch, i;
	//FILE* fp = fopen("data.txt", "rt");
	//FILE* des = fopen("copy.txt", "wt");

	//if (fp == NULL || des == NULL) {
	//	puts("파일오픈 실패!");
	//	return -1;
	//}
	//while ((ch = fgetc(fp)) != EOF)
	//	fputc(ch, des);

	////char str[30];
	/////*for (i = 0; i < 3; i++) {
	////	ch = fgetc(fp);
	////	printf("%c \n", ch);
	////}*/
	////fgets(str, sizeof(str), fp);
	////printf("%s \n", str);
	//
	//if (feof(fp) != 0) puts("파일복사 완료!");
	//else puts("파일복사 실패!");

	//fclose(fp); fclose(des);
}