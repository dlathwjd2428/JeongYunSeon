#pragma once
#include"Macro.h"
#include"Computer.h"

#define IDMIN 3
#define PWMIN 8

enum MENU
{
	MENU_JOIN = 1,
	MENU_LOGIN,
	MENU_EXIT
};
struct member
{
	string id;
	string password;
	string nickname;
	int age;
	string phonenum;
	int mileage;
};

class Login
{
private:
	list <member> m_Member;
	bool m_SameCheck;
	bool m_EngCheck;
	bool m_IDCheck;
	bool m_PWCheck;
	bool m_LoginCheck;

public:
	Login();
	void LoginMenu();
	void Join();
	bool WordCheck(char start, char end, char word);
	void LoginInput();
};

