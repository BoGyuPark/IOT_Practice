#include<stdio.h>

typedef struct {
	int mem1, mem2;
	double mem3;
}sbox;

typedef union  {
	int mem1, mem2;
	double mem3;
}ubox;

int main() {
	sbox s;
	ubox u;
	printf("%p %p %p \n", &s.mem1, &s.mem2, &s.mem3);
	printf("%p %p %p \n", &u.mem1, &u.mem2, &u.mem3);
	printf("%d %d \n", sizeof(sbox), sizeof(ubox));

}