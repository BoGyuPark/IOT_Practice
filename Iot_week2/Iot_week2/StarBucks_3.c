#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __Ŀ�� {
	char * ���밪;
}Ŀ��_t;

typedef struct __���� {
	char * ���밪;
}����_t;

typedef struct __���� {
	char * ���밪;
}����_t;

typedef struct __�ӱ��� {
	char * ���밪;
}�ӱ���_t;

typedef struct __��ǰ�� {
	char * ���밪;
}��ǰ��_t;


char Ŀ��[3][16] = {
	"1. �Ƹ޸�ī��",
	"2. ī���",
	"3. ����������"
};

void �޴�_�����ֱ�() {

	int Ŀ�ǹ�ȣ;
	printf("==<< �޴� >>==\n");

	for (Ŀ�ǹ�ȣ = 0; Ŀ�ǹ�ȣ < sizeof(Ŀ��) / sizeof(Ŀ��[0]); Ŀ�ǹ�ȣ++)
		printf("%s\n", Ŀ��[Ŀ�ǹ�ȣ]);
}

int �ֹ�_�ޱ�() {

	printf("������ �ֹ��Ͻðھ��?(0: ����) ");

	int �ֹ�;

	scanf("%d", &�ֹ�);

	if (�ֹ� == 0)
	{
		printf("���Թ��� �ݽ��ϴ�~ �ȳ�~\n");
		exit(0);
	}

	printf("%d �ֹ��ϼ̽��ϴ�.\n", �ֹ�);

	return �ֹ�;
}

void �Ƹ޸�ī��_�����() {

	printf(" �Ƹ޸�ī�븦 ����� �ֽ��ϴ�~\n");

}


void �츮��(Ŀ��_t *Ŀ��, �ӱ���_t *�ӱ���)
{
	printf(" %s�� %s�� �־� �츳�ϴ�.\n", Ŀ��->���밪, �ӱ���->���밪);
	strcpy(�ӱ���->���밪, "�츰 Ŀ��");
	printf(" %s�� �غ�Ǿ����ϴ�!\n", �ӱ���->���밪);

	////�������� ũ��
	//printf("***Ŀ�� �Ű� ���� ũ�� : %d\n", sizeof(Ŀ��));
	//printf("***�ӱ��� �Ű� ���� ũ�� : %d\n", sizeof(�ӱ���));

	////�������� �ּҰ�
	//printf("---Ŀ�� �Ű� ���� ��ġ �� : %#p\n", &Ŀ��);
	//printf("---�ӱ��� �Ű� ���� ��ġ �� : %#p\n", &�ӱ���);

	////������ �ּҿ� �ִ� ��
	//printf("+++Ŀ�� �Ű� ���� �� : %#p\n", Ŀ��);
	//printf("+++�ӱ��� �Ű� ���� �� : %#p\n", �ӱ���);
}

void ��ǰ����(����_t *����, ��ǰ��_t *��ǰ��)
{
	printf(" %s�� %s�� ��ǰ�� ���ϴ�.\n", ����->���밪, ��ǰ��->���밪);
	strcpy(��ǰ��->���밪, "��ǰ ����");
	printf(" %s�� �غ�Ǿ����ϴ�!\n", ��ǰ��->���밪);
}

void ���ϱ�(�ӱ���_t *�ӱ���, ��ǰ��_t *��ǰ��)
{
	printf(" %s�� %s�� �����ݴϴ�.\n", ��ǰ��->���밪, �ӱ���->���밪);
	strcpy(�ӱ���->���밪, "���� Ŀ��");
	printf(" %s�� �غ�Ǿ����ϴ�!\n", �ӱ���->���밪);
}

void ����(�ӱ���_t *�ӱ���, ����_t *����)
{
	printf(" %s�� %s���� �����ݴϴ�.\n", �ӱ���->���밪, ����->���밪);
	strcpy(�ӱ���->���밪, "ī���");
	printf(" %s�� �غ�Ǿ����ϴ�!\n\n", �ӱ���->���밪);
}

void ī���_�����() {
	printf(" ī��󶼸� ����� �ֽ��ϴ�~\n");

	FILE* ī������ = fopen("ī������.txt", "r");

	Ŀ��_t *Ŀ�� = (Ŀ��_t *)malloc(sizeof(Ŀ��_t));
	Ŀ��->���밪 = (char *)malloc(sizeof(char) * 16);
	fscanf(ī������, "%s", Ŀ��->���밪);
	//strcpy(Ŀ��->���밪, "Ŀ�� ����");

	����_t *���� = (����_t *)malloc(sizeof(����_t));
	����->���밪 = (char *)malloc(sizeof(char) * 8);
	fscanf(ī������, "%s", ����->���밪);
	//strcpy(����->���밪, "����");

	����_t *���� = (����_t *)malloc(sizeof(����_t));
	����->���밪 = (char *)malloc(sizeof(char) * 8);
	fscanf(ī������, "%s", ����->���밪);
	//strcpy(����->���밪, "����");

	�ӱ���_t *�ӱ��� = (�ӱ���_t *)malloc(sizeof(�ӱ���_t));
	�ӱ���->���밪 = (char *)malloc(sizeof(char) * 32);
	fscanf(ī������, "%s", �ӱ���->���밪);
	//strcpy(�ӱ���->���밪, "�߰ſ� ���� ��� �ӱ���");
		
	��ǰ��_t* ��ǰ�� = (��ǰ��_t *)malloc(sizeof(��ǰ��_t));
	��ǰ��->���밪 = (char *)malloc(sizeof(char) * 16);
	fscanf(ī������, "%s", ��ǰ��->���밪);
	//strcpy(��ǰ��->���밪, "��ǰ��");

	fclose(ī������);
	

	printf("**Ŀ�� �Ű� ���� ũ�� : %d\n", sizeof(Ŀ��));
	printf("**�ӱ��� �Ű� ���� ũ�� : %d\n", sizeof(�ӱ���));

	printf("--Ŀ�� �Ű� ���� ��ġ �� : %#p\n", &Ŀ��);
	printf("--�ӱ��� �Ű� ���� ��ġ �� : %#p\n", &�ӱ���);

	printf("\n");

	/*printf("Ŀ�� �ּ� ���� �� : %#p\n", Ŀ��);
	printf("���� �ּ� ���� �� : %#p\n", ����);
	printf("���� �ּ� ���� �� : %#p\n", ����);
	printf("�ӱ��� �ּ� ���� �� : %#p\n", �ӱ���);
	printf("��ǰ�� �ּ� ���� �� : %#p\n", ��ǰ��);*/


	�츮��(Ŀ��, �ӱ���);
	��ǰ����(����, ��ǰ��);
	���ϱ�(�ӱ���, ��ǰ��);
	����(�ӱ���, ����);

	free(Ŀ��->���밪);	free(Ŀ��);
	free(����->���밪);	free(����);
	free(����->���밪);	free(����);
	free(�ӱ���->���밪);		free(�ӱ���);
	free(��ǰ��->���밪);  free(��ǰ��);

}

void ����������_�����() {
	printf(" ���������Ҹ� ����� �ֽ��ϴ�~\n");
}

//���ο� ǥ�� �޸�
void(*Ŀ��_�����[3])() = {
	�Ƹ޸�ī��_�����,
	ī���_�����,
	����������_�����,
};

void �ֹ�_ó���ϱ�(int �ֹ�) {
	if (1 <= �ֹ� && �ֹ� <= sizeof(Ŀ��_�����) / sizeof(Ŀ��_�����[0]))
		Ŀ��_�����[�ֹ� - 1]();
	else
		printf(" �ٽ� �ֹ����ּ���~\n");
}

int main()
{
	printf("��Ÿ������ ���Ű� ȯ���մϴ�~\n");
	while (1) {
		printf("���� ���ϰ� �ֽ��ϴ�~\n");

		//�޴� �����ֱ�
		�޴�_�����ֱ�();

		//�ֹ� �ޱ�
		int �ֹ� = �ֹ�_�ޱ�();

		//�ֹ� ó���ϱ�
		�ֹ�_ó���ϱ�(�ֹ�);
	}
	return 0;
}