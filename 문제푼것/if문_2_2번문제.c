#include<stdio.h>

void main()
{
	int time, cost;
	printf("승마 이용시간을 입력하시오: ");
	scanf("%d", &time);
	printf("%d분 탑승요금: ", time);
	if (time <= 30)
	{
		cost = 3000;
	}
	else
	{
		if ((time - 30) % 10 == 0)
		{
			cost = 3000 + ((time - 30) / 10) * 500;
		}
		else
		{
			cost = 3000 + ((time - 30) / 10) * 500 + 500;
		}
	}
	printf("%d원", cost);
}