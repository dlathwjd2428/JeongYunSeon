#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LOTTO_NUM 6
#define MAX 45

void main()
{
	int flag;
	int Lotto[LOTTO_NUM] = { 0 };
	srand((unsigned)time(NULL));
	while (1)
	{
		system("cls");
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			while (1)
			{
				Lotto[i] = (rand() % MAX) + 1;
				flag = 0;
				for (int j = 0; j < i; j++)
				{
					if (Lotto[i] == Lotto[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
					break;
			}
			printf("%d. %d\n", i + 1, Lotto[i]);
		}
		system("pause");
	}
}