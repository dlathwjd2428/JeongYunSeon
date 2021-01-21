#include<stdio.h>

void main()
{
    int n;
    int line, blank, star;
    printf("세로 입력: ");
    scanf("%d", &n);

    for (line = 0; line < n; line++)
    {
        for (blank = 0; blank < line; blank++)
            printf("  ");

        for (star = 0; star < 2*(n-line) -1; star++)
            printf("★");
        printf("\n");
    }
}