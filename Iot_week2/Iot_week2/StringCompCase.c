#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char str1[20] , str2[20];
	printf("���ڿ� �Է� 1: ");
	scanf("%s", str1);
	printf("���ڿ� �Է� 2: ");
	scanf("%s", str2);

	if (!strcmp(str1, str2)) puts("�� ���ڿ��� �Ϻ��� ����");
	else {
		puts("�� ���ڿ��� �������� ����");
		if(!strncmp(str1,str2,3)) puts("�׷��� �� �� ���ڴ� ����");
	}

}