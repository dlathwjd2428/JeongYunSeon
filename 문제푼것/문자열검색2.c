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
int *Strstr(char * string, char * search)
{
	int num = 0;
	char * tmp = search;
	while (*string)
	{
		if (*string != *search)
			search = tmp;
		else
		{
			search++;
			if (*search == NULL)
				num++;
		}
		string++;
		if (*string == NULL)
			return num;
	}
}
void main()
{
	FILE* f = fopen("Alice.txt", "r");
	int size = filesize(f);
	char word[SIZE];
	int num = 0;
	char* buf = (char*)malloc(size + 1);
	memset(buf, 0, size + 1);

	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	printf("검색할 단어 입력: ");
	scanf("%s", word);
	fread(buf, size + 1, 1, f);
	fclose(f);
	num = Strstr(buf, word);
	if (num)
		printf("%s: %d개", word, num);
	else
		printf("단어를 찾을 수 없습니다.");
	free(buf);
}