#include<stdio.h>
#include<Windows.h>
#define LEFT 1
#define RIGHT 2
#define STAR 1
#define STOP 2
#define BLANK 0
#define STAR_NUM 10
#define STAR_SPEED 100

void Draw(int Map[][STAR_NUM])
{
	system("cls");
	for (int y = 0; y < STAR_NUM; y++)
	{
		for (int x = 0; x < STAR_NUM; x++)
		{
			if (Map[y][x] == STAR || Map[y][x]==STOP)
				printf("☆");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("별 멈추기 = d");
}
void Update(int Map[][STAR_NUM])
{
	for (int y = 0; y < STAR_NUM; y++)
	{
		for (int x = 0; x < STAR_NUM; x++)
		{
			if (Map[y][x] == STAR)
			{
				Map[y][x] = BLANK;
				if (x - 1 < 0)
					Map[y][STAR_NUM - 1] = STAR;
				else
					Map[y][x - 1] = STAR;
			}
		}
	}
}
void Update2(int Map[][10])
{
	for (int y = 0; y < STAR_NUM; y++)
	{
		for (int x = STAR_NUM-1 ; x <=0; x--)
		{
			if (Map[y][x] == STAR)
			{
				Map[y][x] = BLANK;
				if (x + 1 > STAR_NUM - 1)
					Map[y][0] = STAR;
				else
					Map[y][x + 1] = STAR;
			}
		}
	}
}
int Direction(int Map[][10], int way)
{
	for (int y = 0; y < STAR_NUM; y++)
	{
		if (Map[y][0] == 1)
			return RIGHT;
		else if (Map[y][STAR_NUM-1] == 1)
			return LEFT;
		else
			return way;
	}
}
void Stop(int Map[][10], int y)
{
	for (int x = 0; x < STAR_NUM; x++)
	{
		if (Map[y][x] == STAR)
		{
			Map[y][x] = STOP;
			return;
		}
	}
}
void main()
{
	int Mapy = STAR_NUM;
	int Map[STAR_NUM][STAR_NUM] = { 0 };
	int way = LEFT;
	char ch;
	for (int y = 0; y < STAR_NUM; y++)
	{
		for (int x = 0; x < STAR_NUM; x++)
		{
			if (x == STAR_NUM - 1)
				Map[y][x] = STAR;
		}
	}
	printf("별을 보시겠습니까??\n");
	system("pause");
	system("cls");
	while (1)
	{
		way = Direction(Map, way);
		if(way == LEFT)
			Update(Map);
		else if (way == RIGHT)
			Update2(Map);
		if (kbhit())
		{
			ch = getch();
			if (ch == 'd' || ch == 'D')
			{
				Mapy--;
				Stop(Map, Mapy);
			}
		}
		Draw(Map);
		Sleep(STAR_SPEED);
	}
}