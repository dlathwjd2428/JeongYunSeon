#include<stdio.h>
void main()
{
	int num, money;
	printf("구매할 디스켓 갯수를 입력하시오: ");
	scanf("%d", &num);
	printf("디스크 %d개 가격: ", num);
	money = num * 5000;
	if (num >= 10 && num < 100)
	{
		money = 0.9 * money;
		printf("%d원", money);
	}
	else if (num >= 100)
	{
		money = 0.88*money;
		printf("%d원", money);
	}
	else
	{
		printf("%d원", money);
	}
}