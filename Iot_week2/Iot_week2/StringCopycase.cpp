#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char str1[20] = "1234567890", str2[20] = { 0, }, str3[5] = { 0, };

	strcpy(str2, str1);
	puts(str2);

	/*strncpy(str3, str1, sizeof(str1));
	puts(str3);*/

	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0;
	puts(str3);

}