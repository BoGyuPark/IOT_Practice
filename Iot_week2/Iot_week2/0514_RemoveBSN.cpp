#include<stdio.h>
#include<string.h>
void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1] = 0;
}

int main() {
	char str[100];
	printf("���ڿ� �Է�: ");
	fgets(str, sizeof(str), stdin);
	printf("���� : %d, ����: %s \n", strlen(str), str);

	RemoveBSN(str);
	printf("���� : %d, ����: %s \n", strlen(str), str);
	printf("asdf");
	return 0;
}