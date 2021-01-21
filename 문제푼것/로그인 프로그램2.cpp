#include<iostream>
#include<string>
#include<Windows.h>
#include<list>
using namespace std;

#define IDMIN 3
#define PWMIN 8
#define MAX 10

struct member
{
	string id;
	string password;
	string nickname;
	int age;
	string phonenum;
	int mileage;
};

void menu(list<member>::iterator iter);
void settingmenu(list<member>::iterator iter);

bool wordcheck(char start, char end, char word)
{
	if (word >= start && word <= end)
		return true;
	else
		return false;
}
void join(list<member>*mem)
{
	member tmp;
	bool engcheck, samecheck;
	while (1)
	{
		engcheck = true;
		samecheck = true;
		system("cls");
		cout << "아이디 입력([3글자↑] AND [한글X]): ";
		cin >> tmp.id;
		for (int i = 0; i < tmp.id.length(); i++)
		{
			if (wordcheck('a', 'z', tmp.id[i]) == false && wordcheck('A', 'Z', tmp.id[i]) == false && wordcheck('0', '9', tmp.id[i]) == false)
			{
				engcheck = false;
				break;
			}
		}
		for (auto iter = mem->begin(); iter != mem->end(); iter++)
		{
			if (tmp.id == iter->id)
				samecheck = false;
		}
		if (engcheck == true && samecheck == true && tmp.id.length() >= IDMIN)
			break;
		if (engcheck == false)
			cout << "ID가 영문이 아닙니다." << endl;
		if (samecheck == false)
			cout << "동일한 ID가 존재합니다." << endl;
		if (tmp.id.length() < IDMIN)
			cout << "ID가 3글자 이하입니다." << endl;
		system("pause");
	}
	while (1)
	{
		int countnum = 0;
		engcheck = true;
		string samepw;
		system("cls");
		cout << "비밀번호 입력([8글자↑] AND [영문] AND [숫자 포함]): ";
		cin >> tmp.password;
		for (int i = 0; i < tmp.password.length(); i++)
		{
			if (wordcheck('a', 'z', tmp.password[i]) == false && wordcheck('A', 'Z', tmp.password[i]) == false)
			{
				if (wordcheck('0', '9', tmp.password[i]) == true)
					countnum++;
				else
					engcheck = false;
			}
		}
		cout << "비밀번호 확인: ";
		cin >> samepw;
		if (tmp.password.length() >= PWMIN && engcheck == true && countnum != 0 && samepw == tmp.password)
			break;
		if (tmp.password.length() < PWMIN)
			cout << "비밀번호가 8글자 이하입니다." << endl;
		if (engcheck == false)
			cout << "비밀번호가 영문이 아닙니다." << endl;
		if (countnum == 0)
			cout << "숫자가 포함되어 있지 않습니다." << endl;
		if (samepw != tmp.password)
			cout << "비밀번호가 일치하지 않습니다." << endl;
		system("pause");
	}
	system("cls");
	cout << "닉네임 입력: ";
	cin >> tmp.nickname;
	cout << "나이 입력: ";
	cin >> tmp.age;
	cout << "휴대폰 번호 입력: ";
	cin >> tmp.phonenum;
	cout << "회원가입 성공!! 마일리지 1000원 등록" << endl;
	tmp.mileage = 1000;
	mem->push_back(tmp);
	system("pause");
}
list<member> login(list<member>mem)
{
	string id_login, pw_login;
	bool id_check, pw_check, logincheck;
	while (1)
	{
		id_check = false;
		pw_check = false;
		logincheck = false;
		system("cls");
		cout << "아이디 입력: ";
		cin >> id_login;
		cout << "비밀번호 입력: ";
		cin >> pw_login;
		for (auto iter = mem.begin(); iter != mem.end(); iter++)
		{
			if (iter->id == id_login)
			{
				id_check = true;
				if (iter->password == pw_login)
				{
					pw_check = true;
					logincheck = true;
					menu(iter);
					return mem;
				}
			}
		}
		if (logincheck == false)
		{
			if (id_check == false)
				cout << "해당 아이디가 없습니다." << endl;
			if (pw_check == false)
				cout << "비밀번호가 틀렸습니다." << endl;
			system("pause");
			continue;
		}
		break;
	}
}
void show(list<member>::iterator iter)
{
	system("cls");
	cout << "============회원 정보============" << endl;
	cout << "ID: " << iter->id << "\t닉네임: " << iter->nickname << "" << endl;
	cout << "나이: " << iter->age << "\t휴대폰 번호: " << iter->phonenum << "" << endl;
	cout << "마일리지: " << iter->mileage << "" << endl;
}
void menu(list<member>::iterator iter)
{
	int menu;
	while (1)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "1. 회원 정보" << endl;
		cout << "2. 회원 정보 변경" << endl;
		cout << "3. 로그아웃" << endl;
		cout << "입력: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			show(iter);
			system("pause");
			break;
		case 2:
			settingmenu(iter);
			break;
		case 3:
			return;
		}
	}
}
void settingmenu(list<member>::iterator iter)
{
	int menu;
	member tmp;
	while (1)
	{
		show(iter);
		cout << "====================" << endl;
		cout << "1. 닉네임 변경" << endl;
		cout << "2. 나이 변경" << endl;
		cout << "3. 휴대폰 번호 변경" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "입력: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "현재 닉네임: " << iter->nickname << "" << endl;
			cout << "변경할 닉네임 입력: ";
			cin >> tmp.nickname;
			cout << "" << iter->nickname << " -> " << tmp.nickname << "" << endl;
			iter->nickname = tmp.nickname;
			system("pause");
			break;
		case 2:
			cout << "현재 나이: " << iter->age << "" << endl;
			cout << "변경할 나이 입력: ";
			cin >> tmp.age;
			cout << "" << iter->age << " -> " << tmp.age << "" << endl;
			iter->age = tmp.age;
			system("pause");
			break;
		case 3:
			cout << "현재 휴대폰 번호: " << iter->phonenum << "" << endl;
			cout << "변경할 휴대폰 번호 입력: ";
			cin >> tmp.phonenum;
			cout << "" << iter->phonenum << " -> " << tmp.phonenum << "" << endl;
			iter->phonenum = tmp.phonenum;
			system("pause");
			break;
		case 4:
			return;
		}
	}
}
void main()
{
	list<member> mem;
	int menu;
	while (1)
	{
		system("cls");
		cout << "=====Login=====(회원수[" << mem.size() << "명])" << endl;
		cout << "1. 회원 가입" << endl;
		cout << "2. 로그인" << endl;
		cout << "3. 종료" << endl;
		cout << "입력: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (mem.size() >= MAX)
			{
				cout << "더 이상 회원을 등록할 수 없습니다." << endl;
				system("pause");
				break;
			}
			join(&mem);
			break;
		case 2:
			mem = login(mem);
			break;
		case 3:
			return;
		}
	}

}