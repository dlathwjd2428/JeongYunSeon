#include<stdio.h>

int Sum(int n)
{
	if (n == 1)
		return 1;
	return n + Sum(n - 1);
}
void Binary(int n)
{
	if (n > 0)
	{
		Binary(n / 2);
		printf("%d", n % 2);
	}
}
void main()
{
	int num1, num2;

	printf("1. 정수 입력: ");
	scanf("%d", &num1);
	printf("1 ~ %d: %d\n", num1, Sum(num1));

	printf("2. 정수 입력: ");
	scanf("%d", &num2);
	printf("%d -> ", num2);
	Binary(num2);
}