#include<stdio.h>
int i = 10;	

static void func() {
	printf("func()\n");
}

void gfunc() {
	func();
}