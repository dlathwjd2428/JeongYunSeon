#include<stdio.h>
#include<string.h>

int length(char str[])
{
	int i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return i;
}
void main()
{
	char str[10] = "Hello";
	printf("%s 문자열의 길이: %d\n", str, length(str));
}