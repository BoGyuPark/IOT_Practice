#include<stdio.h>
typedef struct person {
	char name[20], phone[20];
};

int main() {
	person man = { "Tomas","354-00xx" };
	person* pMan = &man;

	printf("name : %s\n", man.name);
	printf("phone : %s\n", man.phone);

	printf("name : %s\n", (*pMan).name);
	printf("phone : %s\n", (*pMan).phone);

	printf("name : %s\n", pMan->name);
	printf("phone : %s\n", pMan->phone);
}