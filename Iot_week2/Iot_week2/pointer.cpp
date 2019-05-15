// pointer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
/*
#define COFFEE_POWDER 1
void brew(int coffee) {
	printf("coffee_in:%p\n", &coffee);
	coffee = 2;
}
void make_caffe_latte() {
	int coffee = COFFEE_POWDER;
	printf("coffee:%p\n", &coffee);
	brew(coffee);//int coffee_in = coffee, call by value
	printf("coffee:%d\n", coffee);
}
*/
/*
#define COFFEE_POWDER {1,2,3,4,5}
void brew(int *coffee) {
	printf("coffee_in:%p:%p(%d)\n", 
		&coffee, coffee, sizeof(coffee));
	//coffee[0] = 2;
	*(coffee+0) = 3;//coffee[0]<=>*(coffee+0)
}
void make_caffe_latte() {
	int coffee[16] = COFFEE_POWDER;
	printf("coffee:%p(%d)\n", &coffee, sizeof(coffee));
	//brew(coffee);//int *coffee_in = coffee, call by value
	brew(&coffee[0]);//int *coffee_in = &coffee[0]
	printf("coffee:%d\n", coffee[0]);
}
*/
/*
#define COFFEE_POWDER {{1,2,3,4,5}, {6,7,8,9}}
void brew(int (* coffee)[16]) {//int (* coffee)(int)
	printf("coffee_in:%p:%p(%d)\n", 
		&coffee, coffee, sizeof(coffee));
	//coffee[1][0] = 2;
	*(*(coffee+1)+0) = 3;//coffee[1][0]<=>*(*(coffee+1)+0)
}
void make_caffe_latte() {
	int coffee[2][16] = COFFEE_POWDER;
	printf("coffee:%p(%d)\n", &coffee, sizeof(coffee));
	brew(coffee);//int *coffee_in = coffee, call by value
	//brew(&coffee[0]);//int *coffee_in = &coffee[0]
	printf("coffee:%d\n", coffee[1][0]);
}
*/
/*
void brew(int **coffee) {//int (* coffee)(int)
	printf("coffee_in:%p:%p(%d)\n", 
		&coffee, coffee, sizeof(coffee));
	//coffee[1][0] = 2;
	*(*(coffee+1)+0) = 3;//coffee[1][0]<=>*(*(coffee+1)+0)
}
void make_caffe_latte() {
	int cof[16] = {1,2,3,4,5};
	int fee[16] = {6,7,8,9};
	int * coffee[2] = {cof, fee};//{&cof[0], &fee[0]}
	printf("coffee:%p(%d)\n", &coffee, sizeof(coffee));
	brew(coffee);//int *coffee_in = coffee, call by value
	//brew(&coffee[0]);//int *coffee_in = &coffee[0]
	printf("coffee:%d\n", fee[0]);
}
// int a[3] <=> int *p
// int aa[2][3] <=> int (* ap)[3]
// int * pa[2] <=> int ** pp
*/
/*
#define COFFEE_POWDER 1
int brew() {
	int coffee = COFFEE_POWDER;
	return coffee;
}
void make_caffe_latte() {
	int coffee_out;	
	coffee_out = brew();
	printf("coffee:%d\n", coffee_out);
}
*/
/*
#define COFFEE_POWDER {1,2,3}
int * brew() {
	static int coffee[16] = COFFEE_POWDER;
	return coffee;//&coffee[0]
}
void make_caffe_latte() {
	int * coffee_out;	
	coffee_out = brew();
	printf("coffee:%d\n", coffee_out[1]);
}
//int a[3]<=>int *p<=>int *f()
*/
/*
#define COFFEE_POWDER {{1,2,3},{4,5,6}}
int (* brew())[16] {
	static int coffee[2][16] = COFFEE_POWDER;
	return coffee;//&coffee[0]
}
void make_caffe_latte() {
	int (* coffee_out)[16];
	coffee_out = brew();
	printf("coffee:%d\n", coffee_out[1][2]);
}
//int aa[2][3]<=>int (*pa)[3]<=>int (*paf())[3]
*/
#define COFFEE_POWDER {{1,2,3},{4,5,6}}
int **brew() {
	static int cof[16] = {1,2,3};
	static int fee[16] = {4,5,6};
	static int * coffee[2] = {cof, fee};
	return coffee;//&coffee[0]
}
void make_caffe_latte() {
	int **coffee_out;//;
	coffee_out = brew();
	printf("coffee:%d\n", coffee_out[1][2]);
}
//int a[3]<=>int *p<=>int *f()
//int aa[2][3]<=>int (*pa)[3]<=>int (*paf())[3]
//int * pa[2] <=> int ** pp <=> int ** ppf()
int _tmain(int argc, _TCHAR* argv[])
{
	make_caffe_latte();
	return 0;
}

