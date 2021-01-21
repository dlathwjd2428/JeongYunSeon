#include<stdio.h>

void main()
{
	int num, fee;
	printf("구매할 도시락 갯수를 입력하시오: ");
	scanf("%d", &num);
	printf("도시락 %d개 가격: ", num);
	if (num <= 10)
	{
		fee = 2500 * num;
		printf("%d원", fee);
	}
	else
	{
		fee = 25000 + 2400 * (num-10);
		printf("%d원", fee);
	}
}