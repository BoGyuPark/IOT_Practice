#include <stdio.h>
#include <stdlib.h>

char Ŀ��[3][19] = {
	"1. �Ƹ޸�ī��",
	"2. ī���",
	"3. ����������"
};

void �Ƹ޸�ī��_�����() {
	printf(" �Ƹ޸�ī�븦 ����� �ֽ��ϴ�~\n");
}

void ī���_�����() {
	printf(" ī��󶼸� ����� �ֽ��ϴ�~\n");
}

void ����������_�����() {
	printf(" ���������Ҹ� ����� �ֽ��ϴ�~\n");
}

void(*Ŀ��_�����[3])() = {
	�Ƹ޸�ī��_�����,
	ī���_�����,
	����������_�����,
};