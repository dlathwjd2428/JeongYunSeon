#include<stdio.h>

void main()
{
	int num[10];
	for (int i = 0; i < 10; i++)
	{
		printf("[%d]번째 정수 입력: ", i+1);
		scanf("%d", &num[i]);
	}

	int sum = 0;
	int max = num[0];

	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
			max = num[i];
		sum += num[i];
	}

	float avg = sum / 10.0;
	printf("최대값 = %d  총합 = %d  평균:%.3f", max, sum, avg);
}