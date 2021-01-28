#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

class Computer
{
private:
	string m_strName, m_strSt, m_strGp, m_strCpu, m_strMm;
public:
	Computer();
	void Menu();
	void Status();
	void Program();
};

