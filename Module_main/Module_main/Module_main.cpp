// Module_main.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include <stdio.h>
#include <stdlib.h>
// TODO: 라이브러리 함수의 예제입니다.
void fnModulemain()
{
}


extern char 커피[3][19];
extern void(*커피_만들기[3])();

void 메뉴_보여주기() {
	int 커피번호;
	printf("==<< 메뉴 >>==\n");
	for (커피번호 = 0; 커피번호 < sizeof(커피) / sizeof(커피[0]); 커피번호++)
		printf("%s\n", 커피[커피번호]);
}

int 주문_받기() {
	printf("무엇을 주문하시겠어요?(0: 종료) ");
	int 주문;
	scanf("%d", &주문);
	if (주문 == 0)
	{
		printf("가게문을 닫습니다~ 안녕~\n");
		exit(0);
	}
	printf("%d 주문하셨습니다.\n", 주문);
	return 주문;
}

void 주문_처리하기(int 주문) {
	if (1 <= 주문 && 주문 <= sizeof(커피_만들기) / sizeof(커피_만들기[0]))
		커피_만들기[주문 - 1]();
	else
		printf(" 다시 주문해주세요~\n");
}

int main()
{
	printf("스타벅스에 오신걸 환영합니다~\n");
	while (1) {
		printf("저는 일하고 있습니다~\n");
		//메뉴 보여주기
		메뉴_보여주기();
		//주문 받기
		int 주문 = 주문_받기();
		//주문 처리하기
		주문_처리하기(주문);
	}
	return 0;
}