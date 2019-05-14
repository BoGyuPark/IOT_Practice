#include<stdio.h>
//#define string "C++ Compatible C"
//#define cal (3*4)+(12/4)
//#define ONE 1
//#define TWO ONE+ONE
//#define THREE ONE+TWO
//
//#define DEBUG
//#ifdef DEBUG
//#define MUL(x,y) (x)*(y)
//#endif // DEBUG

extern int i;	//어딘가에 정의 되어있다 라고 알려줌
void gfunc();

int main() {
	printf("%d\n", i);
	gfunc();
	/*printf("string : %s \n", string);
	printf("cal : %d \n", cal);
	printf("ONE=%d, TWO =%d, THREE=%d \n", ONE, TWO, THREE);*/
	//#ifdef DEBUG
	//MUL(1, 2);
	//MUL(1 + 2, 3);
	//MUL((1 + 2), 3);
	//MUL(1, 2) / MUL(3, 4);
	//#endif // DEBUG
}