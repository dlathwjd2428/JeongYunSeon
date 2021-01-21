#include<iostream>
#include<Windows.h>
using namespace std;

#define MAX 5

void Ascending(int* num[])
{
	int tmp;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (*num[i] > *num[j])
			{
				tmp = *num[i];
				*num[i] = *num[j];
				*num[j] = tmp;
			}
		}
	}
}
void show(int i, int *num[])
{
	cout << "==================" << endl;
	for (int i = 0; i < MAX; i++)
		cout << i + 1 << "번째 정수: " << *num[i] << endl;
	cout << "==================" << endl;
}
void main()
{
	int i = 0;
	int* num[MAX];
	for (int i = 0; i < MAX; i++)
	{
		num[i] = new int;
		cout << i + 1 << "번째 정수: ";
		cin >> *num[i];
	}
	cout << "오름차순 정렬전" << endl;
	show(i, num);
	cout << "오름차순 정렬후" << endl;
	Ascending(num);
	show(i, num);
}