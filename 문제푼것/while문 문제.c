#include<stdio.h>
#define TRUE 1

void main()
{
	int i = 0, j = 0, sum = 0;
	while (TRUE)
	{
		printf("1. 10~20 사이 수 입력: ");
		scanf("%d", &i);
		if (i >= 10 && i <= 20)
			break;
		printf("잘못 입력\n");
	}
	while (j <= i)
	{
		sum += j;
		j++;
	}
	printf("1~%d 누적합계: %d\n", i, sum);

	int num = 1;
	printf("2. Hello 출력\n");
	while (num <= 5)
	{
	printf("Hello\n");
	num++;
	}

	int num2 = 1, sum2 = 0;
	printf("3. 정수 반복 입력(0 입력 시 종료)\n");
	while (num2)
	{
		printf("정수 입력: ");
		scanf("%d", &num2);
		sum2 += num2;
	}
	printf("최종 합계: %d\n", sum2);

	int num3, num4 = 2;
	printf("4. 소수 판별\n");
	printf("정수 입력:");
	scanf("%d", &num3);
	if (num3 == 1)
		printf("%d는 소수가 아닙니다.\n", num3);
	while (TRUE)
	{
		if (num3 > num4)
		{
			if (num3 % num4 == 0)
			{
				printf("%d는(은) 소수가 아닙니다.\n", num3);
				break;
			}
			else
				num4++;
		}
		else
		{
			printf("%d는(은) 소수입니다.\n", num3);
			break;
		}
	}

	int num5;
	printf("5. 입력된 정수 거꾸로 출력\n");
	printf("정수 입력: ");
	scanf("%d", &num5);
	while (num5)
	{
		printf("%d", num5 % 10);
		num5 /= 10;
	}

	int num6, sum3 = 0;
	printf("\n6. 입력된 정수의 각자리수 합계\n");
	printf("정수 입력: ");
	scanf("%d", &num6);
	while (num6)
	{
		sum3 += num6 % 10;
		num6 /= 10;
	}
	printf("%d", sum3);
}