#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
typedef struct Student
{
	char Name[20];
	char Address[20];
	int Korean, English, Math, Sum, Age;
	float Average;
	struct Student* Next;
}Student;
void Menu()
{
	system("cls");
	printf("1. 학생 등록\n");
	printf("2. 학생 검색\n");
	printf("3. 학생 목록\n");
	printf("4. 학생 수정\n");
	printf("5. 학생 삭제\n");
	printf("6. 종료\n");
	printf("선택: ");
}
void ShowSt(Student* St)
{
	printf("%8s\t%8s\t%8s\t\n", "학생 이름", "학생 나이", "학생 주소");
	while (St != NULL)
	{
		printf("%8s\t%8d\t%8s\n", St->Name, St->Age, St->Address);
		St = St->Next;
	}
	printf("학생 개개인의 점수는 검색을 이용하세요!!\n");
}
Student* NewSt()
{
	Student* tmp;
	tmp = (Student*)malloc(sizeof(Student));
	tmp->Next = NULL;
	return tmp;
}
void Insert(Student **Head)
{
	if (*Head == NULL)
	{
		*Head = NewSt();
		printf("학생 이름 입력: ");
		scanf("%s", (*Head)->Name);
		printf("%s 학생 나이 입력: ", (*Head)->Name);
		scanf("%d", &(*Head)->Age);
		printf("%s 학생 주소 입력: ", (*Head)->Name);
		scanf("%s", (*Head)->Address);
		printf("%s 학생 국어 점수: ", (*Head)->Name);
		scanf("%d", &(*Head)->Korean);
		printf("%s 학생 영어 점수: ", (*Head)->Name);
		scanf("%d", &(*Head)->English);
		printf("%s 학생 수학 점수: ", (*Head)->Name);
		scanf("%d", &(*Head)->Math);
		printf("학생 정보 입력 완료\n");
		return;
	}
	Insert(&(*Head)->Next);
}
Student* Search(Student *Head, char *Name)
{
	system("cls");
	if (Head == NULL)
	{
		printf("찾는 학생이 없습니다.\n");
		return 0;
	}
	if (!(strcmp(Head->Name, Name)))
	{
		Head->Sum = (Head->English) + (Head->Korean) + (Head->Math);
		Head->Average = (Head->Sum) / 3.0;
		printf("학생 정보 검색 완료\n");
		printf(" = = = = = Information = = = = =\n");
		printf("학생 이름: %s\n", Head->Name);
		printf("학생 나이: %d세\n", Head->Age);
		printf("학생 주소: %s\n", Head->Address);
		printf("국어 점수: %d점\n", Head->Korean);
		printf("영어 점수: %d점\n", Head->English);
		printf("수학 점수: %d점\n", Head->Math);
		printf("합계 점수: %d점\n", Head->Sum);
		printf("평균 점수: %.2f점\n", Head->Average);
		printf("학생 등급: ");
		if (Head->Average > 90)
			printf("A등급\n");
		else if (Head->Average > 80)
			printf("B등급\n");
		else if (Head->Average > 70)
			printf("C등급\n");
		else if (Head->Average > 60)
			printf("D등급\n");
		else
			printf("F등급\n");
		return Head;
	}
	Search(Head->Next, Name);
}
void Modify(Student *Head, char *Name)
{
	int Menu;
	char add[20];
	Head = Search(Head, Name);
	if (Head != NULL)
	{
		while (1)
		{
			Search(Head, Name);
			printf("\n수정할 항목을 선택하시오\n");
			printf("1. 이름\t2. 나이\t3. 주소\t4. 점수\t5. 수정 종료\n");
			printf("선택: ");
			scanf("%d", &Menu);
			switch (Menu)
			{
			case 1:
				printf("현재 이름: %s\n", Head->Name);
				printf("수정할 이름: ");
				scanf("%s", Name);
				printf("%s -> %s로 이름 수정 완료\n", Head->Name, Name);
				strcpy(Head->Name, Name);
				system("pause");
				break;
			case 2:
				printf("현재 나이: %d세\n", Head->Age);
				printf("수정할 나이: ");
				scanf("%d", &Head->Age);
				printf("나이 수정 완료\n");
				system("pause");
				break;
			case 3:
				printf("현재 주소: %s\n", Head->Address);
				printf("수정할 주소: ");
				scanf("%s", add);
				printf("%s -> %s로 이름 수정 완료\n", Head->Address, add);
				strcpy(Head->Address, add);
				system("pause");
				break;
			case 4:
				printf("현재 점수\n");
				printf("국어: %d\t영어:%d\t수학:%d\n", Head->Korean, Head->English, Head->Math);
				printf("수정할 국어 점수: ");
				scanf("%d", &Head->Korean);
				printf("수정할 영어 점수: ");
				scanf("%d", &Head->English);
				printf("수정할 수학 점수: ");
				scanf("%d", &Head->Math);
				printf("점수 수정 완료\n");
				system("pause");
				break;
			case 5:
				printf("수정을 종료합니다\n");
				return;
			}
		}
	}
}
void Delete(Student **Head, char *Name)
{
	Student *tmp;
	if (*Head == NULL)
	{
		printf("삭제할 사람이 없습니다.\n");
		system("pause");
		return;
	}
	if (!(strcmp((*Head)->Name, Name)))
	{
		tmp = *Head;
		*Head = (*Head)->Next;
		free(tmp);
		printf("삭제 완료\n");
		system("pause");
		return;
	}
	Delete(&(*Head)->Next, Name);
}
void Close(Student *Head)
{
	if (Head == NULL)
		return;
	Close(Head->Next);
	free(Head);
}
void main()
{
	int Select;
	char Name[20];
	Student *Head = NULL;
	while (1)
	{
		Menu();
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			Insert(&Head);
			system("pause");
			break;
		case 2:
			if (Head == NULL)
				continue;
			system("cls");
			printf("검색할 이름 입력: ");
			scanf("%s", Name);
			Search(Head, &Name);
			system("pause");
			break;
		case 3:
			if (Head == NULL)
				continue;
			system("cls");
			ShowSt(Head);
			system("pause");
			break;
		case 4:
			if (Head == NULL)
				continue;
			system("cls");
			printf("수정할 학생 이름은? ");
			scanf("%s", Name);
			Modify(Head, &Name);
			system("pause");
			break;
		case 5:
			if (Head == NULL)
				continue;
			system("cls");
			printf("삭제할 학생 이름: ");
			scanf("%s", Name);
			Delete(&Head, &Name);
			break;
		case 6:
			Close(Head);
			return;
		}
	}
}
