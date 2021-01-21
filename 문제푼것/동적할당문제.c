#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

void ShowStudent(Student* St)
{
	printf("\t========%s학생(%d번)========\n", St->Name, St->Number);
	printf("\t나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("\t===========================\n");
}
void ShowClass(Student* St[], int *StudentCount)
{
	printf("┌─────────1 학년─────────┐\n");
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == 1)
			ShowStudent(St[i]);
	printf("└─────────────────────┘\n");
	printf("┌─────────2 학년─────────┐\n");
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == 2)
			ShowStudent(St[i]);
	printf("└─────────────────────┘\n");
	printf("┌─────────3 학년─────────┐\n");
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == 3)
			ShowStudent(St[i]);
	printf("└─────────────────────┘\n");
}
void SetStudent(Student* St, int *StudentCount)
{
	St->Number = ++(*StudentCount);
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name);
	printf("나이 입력 : ");
	scanf("%d", &St->Age);
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	printf("학년 입력(1~3) : ");
	scanf("%d", &St->Class);
	if (St->Class > 3 || St->Class < 1)
	{
		printf("학년 잘못 입력\n");
		free(St);
		(*StudentCount)--;
		system("pause");
	}
}
void SortClass(Student* St[], int *StudentCount)
{
	Student* tmp;
	for (int i = 0; i < *StudentCount - 1; i++)
	{
		for (int j = i + 1; j < *StudentCount; j++)
		{
			if (St[i]->Class > St[j]->Class)
			{
				tmp = St[i];
				St[i] = St[j];
				St[j] = tmp;
			}
		}
	}
}
void SortNumber(Student* St[], int *StudentCount)
{
	Student *tmp2;
	for (int i = 0; i < *StudentCount - 1; i++)
	{
		for (int j = i + 1; j < *StudentCount; j++)
		{
			if (St[i]->Number > St[j]->Number)
			{
				tmp2 = St[i];
				St[i] = St[j];
				St[j] = tmp2;
			}
		}
	}
}
void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;
	char Sname[10];
	int Sclass;

	while (1)
	{
		system("cls");
		printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
		printf("1.학생 등록\n");
		printf("2.학생 목록(번호순)\n");
		printf("3.학생 목록(학년순)\n");
		printf("4.학년 검색\n");
		printf("5.학생 검색\n");
		printf("6.마지막 학생 삭제\n");
		printf("7.학생 전체 삭제\n");
		printf("8.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount + 1 >= MAX)
			{
				printf("학생정원(50명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;
		case 2:
			system("cls");
			SortNumber(Student_List, &StudentCount);
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:
			system("cls");
			SortClass(Student_List, &StudentCount);
			ShowClass(Student_List, &StudentCount);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("검색할 학년 입력(1~3): ");
			scanf("%d", &Sclass);
			for (int i = 0; i < StudentCount; i++)
				if (Student_List[i]->Class == Sclass)
					ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 5:
			system("cls");
			printf("검색할 이름 입력: ");
			scanf("%s", Sname);
			for (int i = 0; i < StudentCount; i++)
				if (!strcmp(Student_List[i]->Name, Sname))
					ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 6:
			if (StudentCount == 0)
			{
				printf("더 이상 삭제할 학생이 없습니다.\n");
				system("pause");
				continue;
			}
			StudentCount--;
			printf("%s학생 동적할당 해제 완료\n", Student_List[StudentCount]->Name);
			free(Student_List[StudentCount]);
			Student_List[StudentCount] = NULL;
			system("pause");
			break;
		case 7:
			if (StudentCount == 0)
			{
				printf("더 이상 삭제할 학생이 없습니다.\n");
				system("pause");
				continue;
			}
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s학생 동적할당 해제 완료\n", Student_List[i]->Name);
				free(Student_List[i]);
				Student_List[i] = NULL;
			}
			StudentCount = 0;
			system("pause");
			break;
		case 8:
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s학생 동적할당 해제 완료\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}