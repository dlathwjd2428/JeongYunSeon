#include<stdio.h>
#define SIZE 10

void output(int arr[])
{
	for (int i = 0; i < SIZE; i++)
		printf("%d,", arr[i]);
	printf("\b \n");
}

void parity(int arr[], int i)
{
	if ( i == 1)
	{
		for (int i = 1; i < SIZE; i += 2)
		{
			printf("%d,", arr[i]);
			odd_sum += arr[i];
		}
		return odd_sum;
	}

	if ( i == 0)
	{
		for (int i = 0; i < SIZE; i += 2)
		{
			printf("%d,", arr[i]);
			even_sum += arr[i];
		}
		return even_sum;
	}

}

void ascending(int arr[])
{
	int tmp;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i+1 ; j<SIZE; j++)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}


}
void main()
{
	int arr[SIZE] = { 10, 17, 3, 9, 37, 10, 8, 9, 13, 21 };
	printf("1번 문제\n");
	output(arr);

	int invert_arr[SIZE];
	printf("2번 문제\n");
	printf("Invert_arr: ");
	for (int i = 0; i < SIZE; i++)
	{
		invert_arr[i] = arr[SIZE - i -1];
		printf("%d,", invert_arr[i]);
	}
	printf("\b \n");
	printf("arr: ");
	output(arr);

	printf("3번 문제\n");
	int odd_sum = 0, even_sum = 0;
	printf("홀수 번째 원소: ");
	parity(arr, 1);
	for (int i = 1; i < SIZE; i += 2)
	{
		printf("%d,", arr[i]);
		odd_sum += arr[i];
	}
	printf("\b \n");
	printf("홀수 번째 총합: %d\n", odd_sum);
	printf("짝수 번째 원소: ");
	for (int i = 0; i < SIZE; i += 2)
	{
		printf("%d,", arr[i]);
		even_sum += arr[i];
	}
	printf("\b \n");
	printf("짝수 번째 총합: %d\n", even_sum);

	int sort_arr[SIZE];
	for (int i = 0; i < SIZE; i++)
		sort_arr[i] = arr[i];

	printf("4번 문제\n");
	printf("arr: ");
	output(arr);
	printf("sort_arr: ");
	ascending(sort_arr);
	output(sort_arr);
}