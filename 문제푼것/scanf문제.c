#include<stdio.h>

void main()
{
	char str
	int num;

	printf("=====1번문제=====\n");
	printf("단일문자를 입력하시오: ");
	scanf("%c", &str);
	printf("정수를 입력하시오: ");
	scanf("%d", &num);
	printf("%c + %d = %c\n", str, num, num + str);

	float num2;

	printf("=====2번문제=====\n");
	printf("소숫점 수를 입력하시오: ");
	scanf("%f", &num2);
	printf("소숫점수: %.2f\n", num2);

	int korean, math, english;

	printf("=====3번문제=====\n");
	printf("국어 점수를 입력하시오: ");
	scanf("%d", &korean);
	printf("수학 점수를 입력하시오: ");
	scanf("%d", &math);
	printf("영어 점수를 입력하시오: ");
	scanf("%d", &english);
	int sum = korean + math + english;
	float avg = sum / 3.0;
	printf("합계 점수:%d      평균 점수:%.2f\n", sum, avg);

	char name[10];
	int age;

	printf("=====4번문제=====\n");
	printf("이름을 입력하시오: ");
	scanf("%s", name);
	printf("%s님의 나이를 입력하시오: ", name);
	scanf("%d", &age);
	printf("%s님의 나이는 %d세입니다.", name, age);
}