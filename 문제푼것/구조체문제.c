#include<stdio.h>
#include <windows.h>
#define SIZE 5

typedef struct people
{
	char name[10];
	int age;
	float height;
}People;

void Descending(People P[5])
{
	People tmp1, tmp2;

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (P[i].age < P[j].age)
			{
				tmp1 = P[j];
				P[j] = P[i];
				P[i] = tmp1;
			}
			else if (P[i].age == P[j].age)
			{
				if (P[i].height < P[j].height)
				{
					tmp2 = P[j];
					P[j] = P[i];
					P[i] = tmp2;
				}
			}
		}
	}
}
void main()
{
	People list[5];
	for (int i = 0; i < SIZE; i++)
	{
		printf("======%d======\n", i + 1);
		printf("이름 입력: ");
		scanf("%s", list[i].name);
		printf("나이 입력: ");
		scanf("%d", &list[i].age);
		printf("키 입력: ");
		scanf("%f", &list[i].height);
		printf("==============\n");
	}

	system("cls");
	printf("정렬 전 정보\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("======%d======\n", i + 1);
		printf("이름: %s\n", list[i].name);
		printf("나이: %d\n", list[i].age);
		printf("키: %.2f\n", list[i].height);
		printf("==============\n");
	}
	Descending(list);
	printf("\n정렬 후 정보\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("======%d======\n", i + 1);
		printf("이름: %s\n", list[i].name);
		printf("나이: %d\n", list[i].age);
		printf("키: %.2f\n", list[i].height);
		printf("==============\n");
	}
}