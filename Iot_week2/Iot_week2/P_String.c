#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	////Problem 1
	//char str[100];
	//fgets(str, sizeof(str), stdin);
	//int sum = 0, len = strlen(str);
	//str[len - 1] = 0;
	//for (int i = 0; i < len - 1; i++) {
	//	if (str[i] >= '0' && str[i] <= '9') sum += str[i] - '0';
	//}
	//printf("합은 : %d\n", sum);


	////Problem 2
	//char str1[20], str2[20], str3[20];
	//printf("문자열 입력 1: ");
	//fgets(str1, sizeof(str1), stdin);
	//printf("문자열 입력 2: ");
	//fgets(str2, sizeof(str2), stdin);
	//
	//int len1 = strlen(str1), len2 = strlen(str2);
	//str1[len1 - 1] = 0;	str2[len2 - 1] = 0;

	//strcpy(str3, str1);
	//strcat(str3, str2);
	//puts(str3);


	//Problem3
	char str1[100], str2[100];
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = 0;
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = 0;
	char str1Name[100] = { 0, }, str2Name[100] = { 0, };
	char str1Age[100] = { 0, }, str2Age[100] = { 0, };
	int str1Pivot = 0, str2Pivot = 0;
	for (int i = 0; i < strlen(str1) - 1; i++) {
		if (str1[i] == ' ') {
			str1Pivot = i;
			break;
		}
	}
	for (int i = 0; i < strlen(str2) - 1; i++) {
		if (str2[i] == ' ') {
			str2Pivot = i;
			break;
		}
	}
	strncpy(str1Name, str1, str1Pivot);
	strncpy(str2Name, str2, str2Pivot);

	strcpy(str1Age, str1+str1Pivot); strcpy(str2Age, str2+str2Pivot);

	if (!strcmp(str1Name, str2Name)) puts("이름이 같음");
	else puts("이름이 다름");

	if (!strcmp(str1Age, str2Age)) puts("나이가 같음");
	else puts("나이가 다름");
}