#include "Computer.h"

Computer::Computer()
{
	m_strName = "Attents";
	m_strSt = "Off";
	m_strGp = "GTX1060Ti";
	m_strCpu = "i7";
	m_strMm = "16G";
}
void Computer::Menu(list<member>::iterator iter)
{
	int iMenu;
	cout << "컴퓨터 on" << endl;
	Sleep(1000);
	m_strSt = "On";
	while (1)
	{
		system("cls");
		cout << "===== 환 영 합 니 다 =====" << endl;
		cout << "1. 컴퓨터 상태" << endl;
		cout << "2. 기능" << endl;
		cout << "3. 회원 정보" << endl;
		cout << "4. 회원 정보 변경" << endl;
		cout << "5. off" << endl;
		cout << "입력 >>";
		cin >> iMenu;
		switch (iMenu)
		{
		case COM_STATUS:
			Status();
			break;
		case COM_PROGRAM:
			Program();
			break;
		case COM_INFO:
			Info(iter);
			break;
		case COM_CHANGE:
			SettingMenu(iter);
			break;
		case COM_OFF:
			for (int i = 0; i < 5; i++)
			{
				cout << "off" << 5 - i << "초 전" << endl;
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
	int iMenu;
	while (1)
	{
		system("cls");
		cout << "1. 계산기" << endl;
		cout << "2. 메모장" << endl;
		cout << "3. 그림판" << endl;
		cout << "4. 돌아가기" << endl;
		cout << "선택 >>>> ";
		cin >> iMenu;
		switch (iMenu)
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
void Computer::Info(list<member>::iterator iter)
{
	system("cls");
	cout << "============회원 정보============" << endl;
	cout << "ID: " << iter->id << "\t닉네임: " << iter->nickname << "" << endl;
	cout << "나이: " << iter->age << "\t휴대폰 번호: " << iter->phonenum << "" << endl;
	cout << "마일리지: " << iter->mileage << "" << endl;
}
void Computer::SettingMenu(list<member>::iterator iter)
{
	int menu;
	member tmp;
	while (1)
	{
		Info(iter);
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