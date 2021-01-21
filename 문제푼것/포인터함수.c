#include<stdio.h>
#define SIZE 8

void ConvertToUppercase(char* str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

void MaxNum(int* num1, int* num2, int *max)
{
	if (*num1 >= *num2)
		*max = *num1;
	else
		*max = *num2;
}

void Sum(int* num, int* result)
{
	*result = 0;
	for (int i = 1; i <= *num; i++)
		*result += i;
}

void Ascending(int* arr)
{
	int tmp;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[i] > arr[j])
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
	char string[20];
	printf("1. 문자열을 입력하시오: ");
	scanf("%s", string);
	printf("함수 호출 전 = %s\n", string);
	ConvertToUppercase(string);
	printf("함수 호출 후 = %s\n", string);

	int num1, num2, max;
	printf("2. 두 정수를 입력하시오: ");
	scanf("%d%d", &num1, &num2);
	MaxNum(&num1, &num2, &max);
	printf("%d와(과) %d 중 큰 수는 %d\n", num1, num2, max);

	int num, result;
	printf("3. 정수를 입력하시오: ");
	scanf("%d", &num);
	Sum(&num, &result);
	printf("1 ~ %d의 총합: %d\n", num, result);

	int arr[SIZE];
	printf("4. 오름차순 정렬\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("[%d]번째 정수 입력: ", i);
		scanf("%d", &arr[i]);
	}
	printf(" 정렬 전: ");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
		if (i == SIZE - 1)
			printf("\n");
	}
	Ascending(arr);
	printf("정렬 후: ");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
}