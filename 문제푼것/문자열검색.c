#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100

int filesize(FILE* f)
{
	int size;
	int currpos = ftell(f);
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, currpos, SEEK_SET);
	return size;
}
char *Strstr(char * string, char * search)
{
	char * tmp = search;
	int count = -1;
	while (*string)
	{
		if (*string != *search)
		{
			count = -1;
			search = tmp;
		}
		if (*string == *search)
		{
			search++;
			count++; 
			if (*search == NULL)
				return string - count;
		}
		string++;
		if (*string == NULL)
			return 0;
	}
}
void main()
{
	FILE* f = fopen("Alice.txt", "r");
	int size = filesize(f);
	char word[SIZE];
	int num = 0;
	char* buf = malloc(size + 1);
	memset(buf, 0, size + 1);

	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	printf("검색할 단어 입력: ");
	scanf("%s", word);
	while (!feof(f))
	{
		num++;
		fgets(buf, size, f);
		if (Strstr(buf, word) != NULL)
			printf("%d: %s", num, buf);
	}
	fclose(f);
	free(buf);
}