#include<stdio.h>
#include<string.h>

char *Strcat(char* Original, char* Copy)
{
	int i = 0, j = 0;
	while (Original[i] != 0)
		i++;
	while (Copy[j] != 0)
	{
		Original[i] = Copy[j];
		i++;
		j++;
	}
	Original[i] = 0;
	return Original;
}
void main()
{
	char str[20] = "Hello";
	char str1[20] = "^^";
	printf("%s\n", str);
	printf("%s\n", Strcat(str, str1));
}