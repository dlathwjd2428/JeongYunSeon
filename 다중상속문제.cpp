#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Person
{
protected:
	string m_strGender;
	int m_iAge;
	string m_strName;
public:
	void InputPerson()
	{
		cout << "���� �Է�: ";
		cin >> m_iAge;
		cout << "�̸� �Է�: ";
		cin >> m_strName;
		cout << "���� �Է�: ";
		cin >> m_strGender;
	}
	void PrintPerson()
	{
		cout << "����: " << m_iAge << endl;
		cout << "�̸�: " << m_strName << endl;
		cout << "����: " << m_strGender << endl;
	}
};
class School
{
protected:
	int m_iGrade;
	int m_iGroup;
	int m_iNum;
public:
	void InputSchool()
	{
		cout << "�г� �Է�: ";
		cin >> m_iGrade;
		cout << "�� �Է�: ";
		cin >> m_iGroup;
		cout << "�л� ��ȣ �Է�: ";
		cin >> m_iNum;
	}
	void PrintSchool()
	{
		cout << m_iGrade << "�г� " << m_iGroup << "�� " << m_iNum << "�� �л�" << endl;
	}
};
class Student : public Person, public School
{
public:
	void Print()
	{
		InputSchool();
		InputPerson();
		system("cls");
		PrintSchool();
		PrintPerson();
	}
};
void main()
{
	Student st;
	st.Print();
}