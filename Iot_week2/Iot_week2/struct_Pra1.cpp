#include<stdio.h>
typedef struct perinfo {
	char addr[30], tel[20];
};

typedef struct person {
	char name[30], pID[20];
	perinfo* info;
};

int main() {

	perinfo pinfo = { "Korea Seoul","333-4444" };
	person man = { "Mr. Lee","820204-xxxx512" };
	man.info = &pinfo;

	printf("name : %s\n", man.name);
	printf("pID : %s\n", man.pID);
	printf("addr : %s\n", man.info->addr);
	printf("tel : %s\n", man.info->tel);
	
}