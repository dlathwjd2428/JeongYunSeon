#include "Computer.h"

Computer::Computer()
{
	m_strName = "Atents";
	m_strSt = "OFF";
	m_strGp = "GTX990";
	m_strCpu = "i7";
	m_strMm = "8G";
}
void Computer::Menu()
{
	int imenu;
	cout << "최정호 컴퓨터 on" << endl;
	Sleep(1000);
	m_strSt = "ON";
	while (1)
	{
		system("cls");
		cout << "===== 환 영 합 니 다 =====" << endl;
		cout << "1. 컴퓨터 상태" << endl;
		cout << "2. 기 능" << endl;
		cout << "3. off" << endl;
		cout << "입력 >>>> ";
		cin >> imenu;
		switch (imenu)
		{
		case 1:
			Status();
			break;
		case 2:
			Program();
			break;
		case 3:
			for (int i = 0; i < 5; i++)
			{
				cout << "off " << 5-i << "초 전" << endl;
				Sleep(1000);
			}
			return;
		}
	}
}
void Computer::Status()
{
	system("cls");
	cout << "제품명: " << m_strName << endl;
	cout << "현재 상태: " << m_strSt << endl;
	cout << "그래픽카드: " << m_strGp << endl;
	cout << "CPU: " << m_strCpu << endl;
	cout << "메모리: " << m_strMm << endl;
	system("pause");
}
void Computer::Program()
{
	int imenu;
	while (1)
	{
		system("cls");
		cout << "1. 계산기" << endl;
		cout << "2. 메모장" << endl;
		cout << "3. 그림판" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "선택 >>>> ";
		cin >> imenu;
		switch (imenu)
		{
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		case 4:
			return;
		}
		system("pause");
		system("cls");
	}
}