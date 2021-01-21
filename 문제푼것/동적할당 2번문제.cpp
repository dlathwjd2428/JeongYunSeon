#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>
using namespace std;

#define MAX 10

struct student
{
	string name;
	int age;
	int year;
	int num;
	int kor;
	int eng;
	int math;
	int sum;
	double avr;
	char grade;
};
vector<student*> regist(vector<student*> st)
{
	student *tmp = new student;
	system("cls");
	tmp->num = st.size() + 1;
	cout << "======" << tmp->num << "번째 학생======" << endl;
	cout << "이름: ";
	cin >> tmp->name;
	cout << "나이: ";
	cin >> tmp->age;
	while (1)
	{
		cout << "학년(1~3): ";
		cin >> tmp->year;
		if (tmp->year >= 1 && tmp->year <= 3)
			break;
		cout << "잘못 입력 다시" << endl;
	}
	cout << "국어 점수: ";
	cin >> tmp->kor;
	cout << "영어 점수: ";
	cin >> tmp->eng;
	cout << "수학 점수: ";
	cin >> tmp->math;
	tmp->sum = tmp->kor + tmp->eng + tmp->math;
	tmp->avr = tmp->sum / 3.0;
	if (tmp->avr >= 90)
		tmp->grade = 'A';
	else if (tmp->avr >= 80)
		tmp->grade = 'B';
	else if (tmp->avr >= 70)
		tmp->grade = 'C';
	else if (tmp->avr >= 60)
		tmp->grade = 'D';
	else
		tmp->grade = 'F';
	st.push_back(tmp);
	system("pause");
	return st;
}
void show(vector<student*>::iterator iter)
{
	cout << "=======" << (*iter)->num << "번째 학생======" << endl;
	cout << "이름: " << (*iter)->name << endl;
	cout << "나이: " << (*iter)->age << "살" << endl;
	cout << "학년: " << (*iter)->year << "학년" << endl;
	cout << "국어 점수: " << (*iter)->kor << endl;
	cout << "영어 점수: " << (*iter)->eng << endl;
	cout << "수학 점수: " << (*iter)->math << endl;
	cout << "합계 점수: " << (*iter)->sum << "\t평균 점수: " << (*iter)->avr << endl;
	cout << "등급: [" << (*iter)->grade << "]" << endl << endl;
}
void search(vector<student*> st)
{
	vector<student*>::iterator iter;
	string tmp_name;
	cout << "이름 입력: ";
	cin >> tmp_name;
	for (iter = st.begin(); iter != st.end(); iter++)
	{
		if (tmp_name == (*iter)->name)
		{
			show(iter);
			return;
		}
	}
	if (iter == st.end())
		cout << "해당 학생이 없습니다." << endl;
}
void release(vector<student*> st)
{
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		cout << (*iter)->num << "번 학생: " << (*iter)->name << endl;
		delete *iter;
		cout << "할당 해제 완료" << endl;
	}
}
void showyear(vector<student*>st, int year)
{
	cout << "┌─────────" << year << "학년─────────┐" << endl;
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		if ((*iter)->year == year)
			show(iter);
	}
	cout << "└─────────────────────┘" << endl;
}
void showgrade(vector<student*> st, char grade)
{
	cout << "┌─────────" << grade << "등급─────────┐" << endl;
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		if ((*iter)->grade == grade)
			show(iter);
	}
	cout << "└─────────────────────┘" << endl;
}
void main()
{
	vector <student*> st;
	int select = 0;
	while (1)
	{
		system("cls");
		cout << "===학생 정보 관리===(학생수: " << st.size() << "명)" << endl;
		cout << "1. 학생 등록" << endl;
		cout << "2. 학생 정보 보기" << endl;
		cout << "3. 학생 검색" << endl;
		cout << "4. 등급별 보기" << endl;
		cout << "5. 학년별 보기" << endl;
		cout << "6. 종료" << endl;
		cout << "입력: ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (st.size() > MAX)
			{
				cout << "학생 정원이 모두 찼습니다." << endl;
				system("pause");
				break;
			}
			st = regist(st);
			break;
		case 2:
			system("cls");
			for (auto iter = st.begin(); iter != st.end(); iter++)
				show(iter);
			system("pause");
			break;
		case 3:
			system("cls");
			search(st);
			system("pause");
			break;
		case 4:
			system("cls");
			showgrade(st, 'A');
			showgrade(st, 'B');
			showgrade(st, 'C');
			showgrade(st, 'D');
			showgrade(st, 'F');
			system("pause");
			break;
		case 5:
			system("cls");
			showyear(st, 1);
			showyear(st, 2);
			showyear(st, 3);
			system("pause");
			break;
		case 6:
			system("cls");
			release(st);
			system("pause");
			return;
		}
	}
}