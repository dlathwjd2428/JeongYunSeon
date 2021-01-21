#include<stdio.h>
#include<map>//레드블랙트리
//이진탐색트리
//B tree, AVL tree, Red Black tree > 왼쪽과 오른쪽의 밸런스를 잡기 위한 트리

typedef struct Student
{
	char Name[256];
	int Age;
	char Major[256];
}Student;

Student CreateStudent()
{
	Student st;
	printf("이름 입력: ");
	scanf("%s", st.Name);
	printf("나이 입력: ");
	scanf("%d", &st.Age);
	printf("학과 입력: ");
	scanf("%s", st.Major);
	return st;
}
void ShowStudent(Student st, int Num)
{
	printf("학번(%d)\n", Num);
	printf("이름: %s\t", st.Name);
	printf("나이: %d\t", st.Age);
	printf("학과: %s\n", st.Major);
}
void main()
{
	std::map<int, Student> mapStudent;
	int StudentNum = 20200001;
	//mapStudent.insert(std::make_pair(20200001, CreateStudent())); 정보를 2020001에 넣음
	//mapStudent[20200002] = CreateStudent(); //위와 같음
	//mapStudent[20200001] = CreateStudent(); //정보 수정(key는 중복이 불가능)
	for (int i = 0; i < 5; i++)
	{
		mapStudent.insert(std::make_pair(StudentNum++, CreateStudent()));
	}
	for (auto iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
	{
		ShowStudent(iter->second, iter->first);
	}
	mapStudent.erase(20200001); //key의 정보를 삭제
	mapStudent.at(20200001); //밑과 같음
	mapStudent[20200001];
	mapStudent.find(20200001); //정보 검색

}