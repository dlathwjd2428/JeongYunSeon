#include<stdio.h>

void main()
{
	printf("2번 문제\n");
	int sum = 1;
	for (int money = 1, day = 2; day <= 30; day++)
	{
		money *= 2;
		sum += money;
	}
	printf("30일 동안 저축한 금액: %d\n", sum);

	printf("3번 문제\n");
	int sum2 = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
			{
				sum2 += i;
			}
			continue;
		}
		sum2 += i;
	}
	printf("1~1000 사이의 합: %d\n", sum2);

	printf("4번 문제. 10000을 넘기 직전의 수\n");
	int i4, sum4 = 0;
	for (i4 = 1; sum4 < 10000; i4 += 2)
	{	
		sum4 += i4;
		if (sum4 >= 10000)
		{
			sum4 -= i4;
			break;
		}
	}
	printf("i: %d      sum: %d", i4, sum4);
}