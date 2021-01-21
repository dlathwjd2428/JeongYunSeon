#include<stdio.h>

void main()
{
	char str[5];
	for (int i = 0; i < 5; i++)
	{
		printf("%d번째 원소 값 : ", i + 1);
		scanf("%c", &str[i]);
		scanf("%*c");
	}
	for (int i = 0; i < 5; i++)
		printf("%c ", str[i]);
}
