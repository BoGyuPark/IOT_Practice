#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __커피 {
	char * 내용값;
}커피_t;

typedef struct __우유 {
	char * 내용값;
}우유_t;

typedef struct __설탕 {
	char * 내용값;
}설탕_t;

typedef struct __머그잔 {
	char * 내용값;
}머그잔_t;

typedef struct __거품기 {
	char * 내용값;
}거품기_t;


char 커피[3][16] = {
	"1. 아메리카노",
	"2. 카페라떼",
	"3. 에스프레소"
};

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

void 아메리카노_만들기() {

	printf(" 아메리카노를 만들고 있습니다~\n");

}


void 우리기(커피_t *커피, 머그잔_t *머그잔)
{
	printf(" %s를 %s에 넣어 우립니다.\n", 커피->내용값, 머그잔->내용값);
	strcpy(머그잔->내용값, "우린 커피");
	printf(" %s가 준비되었습니다!\n", 머그잔->내용값);

	////포인터의 크기
	//printf("***커피 매개 변수 크기 : %d\n", sizeof(커피));
	//printf("***머그잔 매개 변수 크기 : %d\n", sizeof(머그잔));

	////포인터의 주소값
	//printf("---커피 매개 변수 위치 값 : %#p\n", &커피);
	//printf("---머그잔 매개 변수 위치 값 : %#p\n", &머그잔);

	////포인터 주소에 있는 값
	//printf("+++커피 매개 변수 값 : %#p\n", 커피);
	//printf("+++머그잔 매개 변수 값 : %#p\n", 머그잔);
}

void 거품내기(우유_t *우유, 거품기_t *거품기)
{
	printf(" %s를 %s로 거품을 냅니다.\n", 우유->내용값, 거품기->내용값);
	strcpy(거품기->내용값, "거품 우유");
	printf(" %s가 준비되었습니다!\n", 거품기->내용값);
}

void 더하기(머그잔_t *머그잔, 거품기_t *거품기)
{
	printf(" %s를 %s에 더해줍니다.\n", 거품기->내용값, 머그잔->내용값);
	strcpy(머그잔->내용값, "우유 커피");
	printf(" %s가 준비되었습니다!\n", 머그잔->내용값);
}

void 젓기(머그잔_t *머그잔, 설탕_t *설탕)
{
	printf(" %s를 %s으로 저어줍니다.\n", 머그잔->내용값, 설탕->내용값);
	strcpy(머그잔->내용값, "카페라떼");
	printf(" %s가 준비되었습니다!\n\n", 머그잔->내용값);
}

void 카페라떼_만들기() {
	printf(" 카페라떼를 만들고 있습니다~\n");

	FILE* 카페라떼재료 = fopen("카페라떼재료.txt", "r");

	커피_t *커피 = (커피_t *)malloc(sizeof(커피_t));
	커피->내용값 = (char *)malloc(sizeof(char) * 16);
	fscanf(카페라떼재료, "%s", 커피->내용값);
	//strcpy(커피->내용값, "커피 가루");

	우유_t *우유 = (우유_t *)malloc(sizeof(우유_t));
	우유->내용값 = (char *)malloc(sizeof(char) * 8);
	fscanf(카페라떼재료, "%s", 우유->내용값);
	//strcpy(우유->내용값, "우유");

	설탕_t *설탕 = (설탕_t *)malloc(sizeof(설탕_t));
	설탕->내용값 = (char *)malloc(sizeof(char) * 8);
	fscanf(카페라떼재료, "%s", 설탕->내용값);
	//strcpy(설탕->내용값, "설탕");

	머그잔_t *머그잔 = (머그잔_t *)malloc(sizeof(머그잔_t));
	머그잔->내용값 = (char *)malloc(sizeof(char) * 32);
	fscanf(카페라떼재료, "%s", 머그잔->내용값);
	//strcpy(머그잔->내용값, "뜨거운 물이 담긴 머그잔");
		
	거품기_t* 거품기 = (거품기_t *)malloc(sizeof(거품기_t));
	거품기->내용값 = (char *)malloc(sizeof(char) * 16);
	fscanf(카페라떼재료, "%s", 거품기->내용값);
	//strcpy(거품기->내용값, "거품기");

	fclose(카페라떼재료);
	

	printf("**커피 매개 변수 크기 : %d\n", sizeof(커피));
	printf("**머그잔 매개 변수 크기 : %d\n", sizeof(머그잔));

	printf("--커피 매개 변수 위치 값 : %#p\n", &커피);
	printf("--머그잔 매개 변수 위치 값 : %#p\n", &머그잔);

	printf("\n");

	/*printf("커피 주소 변수 값 : %#p\n", 커피);
	printf("우유 주소 변수 값 : %#p\n", 우유);
	printf("설탕 주소 변수 값 : %#p\n", 설탕);
	printf("머그잔 주소 변수 값 : %#p\n", 머그잔);
	printf("거품기 주소 변수 값 : %#p\n", 거품기);*/


	우리기(커피, 머그잔);
	거품내기(우유, 거품기);
	더하기(머그잔, 거품기);
	젓기(머그잔, 설탕);

	free(커피->내용값);	free(커피);
	free(우유->내용값);	free(우유);
	free(설탕->내용값);	free(설탕);
	free(머그잔->내용값);		free(머그잔);
	free(거품기->내용값);  free(거품기);

}

void 에스프레소_만들기() {
	printf(" 에스프레소를 만들고 있습니다~\n");
}

//새로운 표현 메모
void(*커피_만들기[3])() = {
	아메리카노_만들기,
	카페라떼_만들기,
	에스프레소_만들기,
};

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