#pragma once
#include"Macro.h"

enum COM
{
	COM_STATUS = 1,
	COM_PROGRAM,
	COM_INFO,
	COM_CHANGE,
	COM_OFF
};
class Computer
{
private:
	string m_strName;
	string m_strSt;
	string m_strGp;
	string m_strCpu;
	string m_strMm;
	
public:
	Computer();
	void Menu(list<member>::iterator iter);
	void Status();
	void Program();
	void Info(list<member>::iterator iter);
	void SettingMenu(list<member>::iterator iter);
};
