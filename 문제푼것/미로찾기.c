#include<stdio.h>
#include<conio.h>
#include<Windows.h>
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//»ö»ó ÁöÁ¤
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define POTAL_MAX 2//Æ÷Å» °¹¼ö
#define ENTRY_START 10
#define EXIT_START 20
#define HEART 3
#define BOMB 4
#define CLEAR 5
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 10
#define HEIGHT 10
#define HP_MAX 100
int map[HEIGHT][WIDTH] = {
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
  { 2,	0,	1,	0,	0,	1,	0,	1,	3,	1 },
  { 1,	0,	10,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	1,	1,	1,	0,	21,	1,	1,	0,	1 },
  { 1,	0,	0,	1,	1,	1,	0,	1,	0,	1 },
  { 1,	0,20,	4,	0,	1,	3,	1, 4,	1 },
  { 1,	0,	1,	1,	4,	1,	0,	0,	0,	1 },
  { 1,	4,	0,	0,	0,	1,	1,	0,	0,	1 },
  { 1,	0,	0,	1,	4,11,	0,	1,	0,	5 },
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1 } };
int character[2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];
int LastObjectIndex = NULL;
int eat_num = 0;
int HP = HP_MAX;
int stop = 0;
void Init()
{
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 1;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x;
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y;
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
		}
	}
}
void eat()
{
	if (map[character[Y]][character[X]] == HEART)
	{
		if (HP < HP_MAX)
			HP += 25;
		map[character[Y]][character[X]] = NULL;
	}
}
void bomb()
{
	if (map[character[Y]][character[X]] == BOMB)
	{
		HP -= 25;
		if (HP > 0)
		{
			map[character[Y]][character[X]] = NULL;
		}
		else
		{
			system("cls");
			printf("GAME OVER");
			system("pause");
		}
	}
}
void end()
{
	if (map[character[Y]][character[X]] == CLEAR)
	{
		system("cls");
		printf("GAME CLEAR");
		system("pause");
		stop++;
	}
}
void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("¢Ì");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("¢¿");
				ORIGINAL
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				BLUE
					printf("¡Ý");
				ORIGINAL
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				YELLOW
					printf("¡Ü");
				ORIGINAL
			}
			else if (map[y][x] == HEART)
			{
				PLUM
					printf("¢¾");
				ORIGINAL
			}
			else if (map[y][x] == BOMB)
			{
				BLOOD
					printf("¢Â");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n");
	}
	printf("HP: %d", HP);
}

void MoveCheck()
{
	int index = map[character[Y]][character[X]];
	if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
	{
		character[X] = Exit_Potal[index - ENTRY_START][X];
		character[Y] = Exit_Potal[index - ENTRY_START][Y];
	}
}

void Move()
{
	char ch;
	ch = getch();
	system("cls");
	map[character[Y]][character[X]] = LastObjectIndex;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL)
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL)
			character[Y]--;
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)
			character[Y]++;
		break;
	}
	MoveCheck();
	eat();
	bomb();
	end();
	LastObjectIndex = map[character[Y]][character[X]];
	map[character[Y]][character[X]] = CHARACTER;
}
void main()
{
	Init();
	while (HP > 0 && stop == 0)
	{
		MapDraw();
		Move();
	}
}
