#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	char perID[7], name[10];
	fputs("�ֹι�ȣ �� 6�ڸ��� �Է��ϼ��� : ", stdout);
	fgets(perID, sizeof(perID), stdin);

	fflush(stdin);

	fputs("�̸��� �Է��ϼ��� :", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹ� ��ȣ ���ڸ� : %s\n", perID);
	printf("�̸� : %s\n", name);

	/*char str[10];

	fputs("���ڿ��� �Է� �ϼ��� : ", stdout);
	fgets(str, sizeof(str), stdin);

	fputs("�Էµ� ���ڿ� : ", stdout);
	fputs(str, stdout);*/


	//fputs("fputs �Լ��� ���� ���, ", stdout);
	//fputs("i Love Linux ", stdout);

	//fputs("\n", stdout);

	//puts("puts �Լ��� ���� ���,");
	//puts("I Love Linux ");

	/*char ch = 0;
	while (ch != EOF) {
		ch = getchar();
		putchar(ch);
	}
	printf("program ���� \n");*/
	
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
	//	puts("���Ͽ��� ����!");
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
	//if (feof(fp) != 0) puts("���Ϻ��� �Ϸ�!");
	//else puts("���Ϻ��� ����!");

	//fclose(fp); fclose(des);
}