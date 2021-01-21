#include<iostream>
using namespace std;

class Rectangle
{
private:
	int Width;
	int Length;

public:
	void SetR();
	void ShowR();
};
void Rectangle::SetR()
{
	while (1)
	{
		cout << "가로 입력: ";
		cin >> Width;
		cout << "세로 입력:";
		cin >> Length;
		if (Width < 1 || Length < 1)
			cout << "가로 또는 세로가 1보다 작습니다." << endl;
		else
			break;
	}
}
void Rectangle::ShowR()
{
	for (int y = 1; y <= Length; y++)
	{
		for (int x = 1; x <= Width; x++)
		{
			if (y == 1 && x == 1)
				cout << "┌";
			else if (y == 1 && x == Width)
				cout << "┐";
			else if (y == Length && x == 1)
				cout << "└";
			else if (y == Length && x == Width)
				cout << "┘";
			else if (y == 1 || y == Length)
				cout << "─";
			else if (x == 1 || x == Width)
				cout << "│";
			else
				cout << "  ";
		}
		cout << endl;
	}
}
void main()
{
	Rectangle R;
	R.SetR();
	R.ShowR();
}