#include<stdio.h>

void main()
{
	int num1;
	printf("1. 정수를 입력하시오: ");
	scanf("%d", &num1);
	printf("%d는(은) 3의 배수", num1);
	if (num1 % 3 == 0)
	{
		printf("입니다.\n");
	}
	if (num1 % 3 != 0)
	{
		printf("가 아닙니다.\n");
	}

	printf("2. 정수를 입력하시오: ");
	scanf("%d", &num1);
	printf("%d의 절댓값은 ", num1);
	if (num1 < 0)
	{
		printf("%d입니다.\n", -num1);
	}
	if (num1 >= 0)
	{
		printf("%d입니다.\n", num1);
	}

	printf("3. 정수를 입력하시오: ");
	scanf("%d", &num1);
	printf("%d는(은) ", num1);
	if (num1 % 2 == 0)
	{
		printf("짝수입니다.\n");
	}
	if (num1 % 2 != 0)
	{
		printf("홀수입니다.\n");
	}

	int num2;
	printf("4. 정수 두 개를 입력하시오: ");
	scanf("%d%d", &num1, &num2);
	printf("Max=");
	if (num1 >= num2)
	{
		printf("%d\n", num1);
	}
	if (num1 < num2)
	{
		printf("%d\n", num2);
	}

	int num3;
	printf("5. 정수 세 개를 입력하시오: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	printf("Max=");
	if (num1 > num2 && num1 > num3)
	{
		printf("%d\n", num1);
	}
	if (num2 > num3 && num2 > num1)
	{
		printf("%d\n", num2);
	}
	if (num3 > num1 && num3 > num2)
	{
		printf("%d\n", num3);
	}
	if (num1 == num2 == num3)
	{
		printf("%d\n", num1);
	}

	printf("6. 정수 두 개를 입력하시오: ");
	scanf("%d%d", &num1, &num2);
	if (num1 >= num2)
	{
		printf("큰 수는 %d이며 ", num1);
		if (num1 % 2 == 0)
		{
			printf("짝수입니다.\n");
		}
		if (num1 % 2 != 0)
		{
			printf("홀수입니다.\n");
		}
	}

	if(num1 < num2)
	{
		printf("큰 수는 %d이며 ", num2);
		if (num2 % 2 == 0)
		{
			printf("짝수입니다.\n");
		}
		if (num2 % 2 != 0)
		{
			printf("홀수입니다.\n");
		}
	}

	printf("7. 정수 두 개를 입력하시오: ");
	scanf("%d%d", &num1, &num2);
	int sum = num1 + num2;
	if (sum % 2 != 0 && sum % 3 == 0)
	{
		printf("%d와 %d의 합: %d\n", num1, num2, sum);
		printf("홀수이며 3의 배수");
	}
	else
	{
		printf("해당사항이 없습니다.");
	}
}