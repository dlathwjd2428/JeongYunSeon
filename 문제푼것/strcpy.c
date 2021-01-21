#include<stdio.h>
#include<string.h>

void copy(char Copy[], char Original[])
{
	int i = 0;
	while (Original[i] != NULL)
	{
		Copy[i] = Original[i];
		i++;
	}
	Copy[i] = NULL;
}
void main()
{
	char Name[10];
	char My_Name[10] = "JungHo";

	copy(Name, My_Name);
	printf("Name: %s\n", Name);
	printf("My_Name: %s\n", My_Name);
}