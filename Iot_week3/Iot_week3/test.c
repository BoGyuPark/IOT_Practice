#include<stdio.h>
typedef union shared_data {
	int var;
	char arr[4];
}SharedData;

int main() {
	int i;
	SharedData sd;
	sd.var = 0x12345678;
	for (i = 0; i < 4; i++) printf("%#x ", sd.arr[i]);
	printf("\n");
	
	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12 } };
	int(*ptr)[4] = arr;
	printf("%p \n", ptr);		// ptr+0 0> &ptr[0]
	printf("%p \n", ptr+1);		// &ptr[1]
	printf("%p \n", *ptr);		// *(ptr+0) -> ptr[0] -> &ptr[0][0]
	printf("%d \n", **ptr);		//**(ptr+0) -> *ptr[0] -> *(ptr[0] + 0)
								//-> ptr[0][0]
	printf("%p \n", *ptr+1);		// &ptr[0][1]

	printf("%d \n", *(ptr[1]+1));		// *(ptr[1]+1) ->ptr[1][1]
	printf("%d \n", *(*ptr + 1));		//*(*ptr+1) -> *(*(ptr+0) +1)
										//-> ptr[0][1]
	printf("%p \n", ptr[2]+1);		//	&ptr[3][0]
	printf("%d \n", *ptr[1]);		// ptr[1][0]
	
	printf("\n");

	printf("%p \n", &arr);		//arr 배열 전체 +1 (없음)
	printf("%p \n", &arr + 1);		//arr 배열 전체 +1 (없음)
}