#include<iostream>
using namespace std;

class TimesTable
{
private:
	int Start;
	int End;

public:
	void SetTT();
	void ShowTT();
};
void TimesTable::SetTT()
{
	while (1)
	{
		cout << "시작 단 입력: ";
		cin >> Start;
		cout << "끝 단 입력: ";
		cin >> End;
		if (Start < 2 || Start > 9)
			cout << "시작 단이 2보다 작거나 9보다 큽니다." << endl;
		else if (End < 2 || End >9)
			cout << "끝 단이 2보다 작거나 9보다 큽니다." << endl;
		else if (Start > End)
			cout << "시작 단이 끝 단보다 큽니다." << endl;
		else
			break;
	}
}
void TimesTable::ShowTT()
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = Start; j <= End; j++)
		{
			if (i == 0)
				cout << "========" << j << "단========\t";
			else
				cout << "\t" << j << " x " << i << " = " << j * i << "\t";
		}
		cout << endl;
	}

}
void main()
{
	TimesTable T;
	T.SetTT();
	T.ShowTT();
}