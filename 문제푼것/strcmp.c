#include<stdio.h>
#include<string.h>

void main()
{
	FILE* f = fopen("Alice.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		fread(buf, sizeof(buf), 1, f);
		printf("%s\n", buf);
	}
	fclose(f);
}