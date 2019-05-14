#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void 우리기(char* 커피, char* 머그잔)
{
	printf(" %s를 %s에 넣어 우립니다.\n", 커피, 머그잔);
	strcpy(머그잔, "우린 커피");
	printf(" %s가 준비되었습니다!\n", 머그잔);
	printf("***커피 매개 변수 크기 : %d\n", sizeof(커피));
	printf("***머그잔 매개 변수 크기 : %d\n", sizeof(머그잔));
}

void 거품내기(char* 우유, char* 거품기)
{
	printf(" %s를 %s로 거품을 냅니다.\n", 우유, 거품기);
	strcpy(거품기, "거품 우유");
	printf(" %s가 준비되었습니다!\n", 거품기);
}

void 더하기(char* 머그잔, char* 거품기)
{
	printf(" %s를 %s에 더해줍니다.\n", 거품기, 머그잔);
	strcpy(머그잔, "우유 커피");
	printf(" %s가 준비되었습니다!\n", 머그잔);
}

void 젓기(char* 머그잔, char* 설탕)
{
	printf(" %s를 %s으로 저어줍니다.\n", 머그잔, 설탕);
	strcpy(머그잔, "카페라떼");
	printf(" %s가 준비되었습니다!\n", 머그잔);
}

void 카페라떼_만들기() {
	printf(" 카페라떼를 만들고 있습니다~\n");

	/*char 커피[16] = "커피 가루";
	char 우유[8] = "우유";
	char 설탕[8] = "설탕";
	char 머그잔[32] = "뜨거운 물이 담긴 머그잔";
	char 거품기[16] = "거품기";*/

	/*FILE * 카페라떼재료 = fopen("카페라떼재료.txt","w");

	fprintf(카페라떼재료, "%s\n","커피 가루");
	fprintf(카페라떼재료, "%s\n","우유");
	fprintf(카페라떼재료, "%s\n","설탕");
	fprintf(카페라떼재료, "%s\n","뜨거운 물이 담긴 머그잔");
	fprintf(카페라떼재료, "%s\n","거품기");

	fclose(카페라떼재료);*/

	FILE* 카페라떼재료 = fopen("카페라떼재료.txt", "r");

	char* 커피 = (char*)malloc(sizeof(char) * 16);
	fscanf(카페라떼재료, "%s", 커피);

	char* 우유 = (char*)malloc(sizeof(char) * 8);
	fscanf(카페라떼재료, "%s", 우유);

	char* 설탕 = (char*)malloc(sizeof(char) * 8);
	fscanf(카페라떼재료, "%s", 설탕);

	char* 머그잔 = (char*)malloc(sizeof(char) * 32);
	fscanf(카페라떼재료, "%s", 머그잔);

	char* 거품기 = (char*)malloc(sizeof(char) * 16);
	fscanf(카페라떼재료, "%s", 거품기);

	fclose(카페라떼재료);
	/*char *커피 = (char *)malloc(sizeof(char)*16);
	strcpy(커피, "커피 가루");

	char *우유 = (char *)malloc(sizeof(char)*8);
	strcpy(우유, "우유");

	char *설탕 = (char *)malloc(sizeof(char)*8);
	strcpy(설탕, "설탕");

	char *머그잔 = (char *)malloc(sizeof(char)*32);
	strcpy(머그잔,"뜨거운 물이 담긴 머그잔");

	char *거품기 = (char *)malloc(sizeof(char)*16);
	strcpy(거품기,"거품기");*/

	printf("**커피 매개 변수 크기 : %d\n", sizeof(커피));
	printf("**머그잔 매개 변수 크기 : %d\n", sizeof(머그잔));

	printf("커피 주소 변수 값 : %#p\n", 커피);
	printf("우유 주소 변수 값 : %#p\n", 우유);
	printf("설탕 주소 변수 값 : %#p\n", 설탕);
	printf("머그잔 주소 변수 값 : %#p\n", 머그잔);
	printf("거품기 주소 변수 값 : %#p\n", 거품기);


	우리기(커피, 머그잔);
	거품내기(우유, 거품기);
	더하기(머그잔, 거품기);
	젓기(머그잔, 설탕);

	free(커피);
	free(우유);
	free(설탕);
	free(머그잔);
	free(거품기);

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