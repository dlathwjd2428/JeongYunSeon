#include "Login.h"

Login::Login()
{
	m_EngCheck = true;
	m_SameCheck = true;
	m_IDCheck = false;
	m_PWCheck = false;
	m_LoginCheck = false;
}
void Login::LoginMenu()
{
	int menu;
	while (1)
	{
		system("cls");
		cout << "=====Login=====(회원수[" << m_Member.size() << "명])" << endl;
		cout << "  1. 회원 가입" << endl;
		cout << "  2. 로그인" << endl;
		cout << "  3. 종료" << endl;
		cout << "입력: ";
		cin >> menu;
		switch (menu)
		{
		case MENU_JOIN:
			Join();
			break;
		case MENU_LOGIN:
			LoginInput();
			break;
		case MENU_EXIT:
			return;
		}
	}
}
void Login::Join()
{
	member tmp;
	while (1)
	{
		system("cls");
		cout << "아이디 입력([3글자↑] AND [한글X]):";
		cin >> tmp.id;
		for (int i = 0; i < tmp.id.length(); i++)
		{
			if (WordCheck('a', 'z', tmp.id[i]) == false && WordCheck('A', 'Z', tmp.id[i]) == false
				&& WordCheck('0', '9', tmp.id[i]) == false)
			{
				m_EngCheck = false;
				break;
			}
		}
		for (auto iter = m_Member.begin(); iter != m_Member.end(); iter++)
		{
			if (tmp.id == iter->id)
				m_SameCheck = false;
		}
		if (m_EngCheck == true && m_SameCheck == true && tmp.id.length() >= IDMIN)
			break;
		if (m_EngCheck == false)
			cout << "ID가 영문이 아닙니다." << endl;
		if (m_SameCheck == false)
			cout << "동일한 ID가 존재합니다." << endl;
		if (tmp.id.length() < IDMIN)
			cout << "ID가 3글자 이하입니다." << endl;
		system("pause");
	}
	while (1)
	{
		int countnum = 0;
		m_EngCheck = true;
		string samepw;
		system("cls");
		cout << "비밀번호 입력([8글자↑] AND [영문] AND [숫자 포함]): ";
		cin >> tmp.password;
		for (int i = 0; i < tmp.password.length(); i++)
		{
			if (WordCheck('a', 'z', tmp.password[i]) == false && WordCheck('A', 'Z', tmp.password[i]) == false)
			{
				if (WordCheck('0', '9', tmp.password[i]) == true)
					countnum++;
				else
					m_EngCheck = false;
			}
		}
		cout << "비밀번호 확인: ";
		cin >> samepw;
		if (tmp.password.length() >= PWMIN && m_EngCheck == true && countnum != 0 && samepw == tmp.password)
			break;
		if (tmp.password.length() < PWMIN)
			cout << "비밀번호가 8글자 이하입니다." << endl;
		if (m_EngCheck == false)
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
	m_Member.push_back(tmp);
	system("pause");
}
bool Login::WordCheck(char start, char end, char word)
{
	if (word >= start && word <= end)
		return true;
	else
		return false;
}
void Login::LoginInput()
{
	string id_login, pw_login;
	while (1)
	{
		system("cls");
		cout << "아이디 입력: ";
		cin >> id_login;
		cout << "비밀번호 입력: ";
		cin >> pw_login;
		for (auto iter = m_Member.begin(); iter != m_Member.end(); iter++)
		{
			if (iter->id == id_login)
			{
				m_IDCheck = true;
				if (iter->password == pw_login)
				{
					m_PWCheck = true;
					m_LoginCheck = true;
					//Menu(iter);
				}
			}
		}
		if (m_LoginCheck == false)
		{
			if (m_IDCheck == false)
				cout << "해당 아이디가 없습니다." << endl;
			if (m_PWCheck == false)
				cout << "비밀번호가 틀렸습니다." << endl;
			system("pause");
			continue;
		}
		break;
	}
}