#include<stdio.h>

void main()
{
	int y, a, b;
	printf("높이를 입력하시오: ");
	scanf("%d", &y);
	for (b = 1; b <= y; b++)
	{
		for (a = 1; a <= y; a++)
		{
			if (b >= a)
				printf("★");

			else
				printf("  ");
		}
		printf("\n");
	}
}