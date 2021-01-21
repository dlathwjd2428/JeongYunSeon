#include<stdio.h>

void main()
{
	int num1;
	printf("1. 정수를 입력하시오: ");
	scanf("%d", &num1);
	(num1 % 5 == 0) ? printf("%d는(은) 5의 배수입니다.\n", num1) : printf("%d는(은) 5의 배수가 아닙니다.\n", num1);

	int korean, english, math;
	printf("2. 세 과목의 점수를 입력하시오.\n");
	printf("국어 점수: ");
	scanf("%d", &korean);
	printf("영어 점수: ");
	scanf("%d", &english);
	printf("수학 점수: ");
	scanf("%d", &math);
	int sum = korean + english + math;
	float avg = sum / 3.0;
	(avg >= 60) ? printf("평균 %.2f점 합격\n", avg) : printf("평균 %.2f점 불합격\n", avg);

	int num2, num3;
	printf("3. 두 정수를 입력하시오: ");
	scanf("%d%d", &num2, &num3);
	(num2 > num3) ? printf("큰 수: %d\n", num2) : printf("큰 수: %d\n", num3);

	int num4;
	printf("4. 정수를 입력하시오: ");
	scanf("%d", &num4);
	(num4 % 3 == 0) && (num4 % 2 == 0) ? printf("%d는(은) 짝수이며 3의 배수입니다.\n", num4) : printf("조건 실패\n");

	int num5;
	printf("5. 정수를 입력하시오: ");
	scanf("%d", &num5);
	(num5 % 5 == 0) || (num5 % 7 == 0) ? printf("%d는(은) 5의 배수거나 7의 배수입니다.\n", num5) : printf("조건 실패\n");
}