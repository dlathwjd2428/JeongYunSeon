#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define X 1
#define Y 0
#define HEIGHT 20
#define WIDTH 10
#define WALL 1
#define CHARACTER 2
#define STAR 3
#define FALSE 0
#define TRUE 1
#define EASY 20
#define NORMAL 40
#define HARD 60
#define HELL 80

int Menu()
{
	int select;
	system("cls");
	printf("====별똥별 피하기====\n");
	printf("	1. 게임 시작\n");
	printf("	2. 난이도 조절\n");
	printf("	3. 종료\n");
	scanf("%d", &select);
	return select;
}
int Setup()
{
	int select;
	printf("======난이도 조절======\n");
	printf("1.Easy\n");
	printf("2.Normal\n");
	printf("3.Hard\n");
	printf("4.Hell\n");
	printf("5.Return\n");
	printf("입력: ");
	scanf("%d", &select);
	return select;
}
void LevelPrint(int level)
{
	if (level == EASY)
		printf("====EASY====\n");

	else if (level == NORMAL)
		printf("====NORMAL====\n");

	else if (level == HARD)
		printf("====HARD====\n");

	else if (level == HELL)
		printf("====HELL====\n");
}
void Init(int map[][WIDTH], int character[])
{
	character[X] = WIDTH - 5;
	character[Y] = HEIGHT - 1;
}
void WallPrint(int map[][WIDTH])
{
	for (int y = 0; y < HEIGHT; y++)
	{
		map[y][0] = WALL;
		map[y][WIDTH - 1] = WALL;
	}
}
int GameScore(int map[HEIGHT][WIDTH])
{
	int score = 0;
	for (int x = 1; x < WIDTH - 1; x++)
	{
		if (map[HEIGHT - 1][x] == STAR)
			score++;
	}
	return score;
}
void UpdateStar(int map[][WIDTH])
{
	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 1; x < WIDTH - 1; x++)
		{
			if (map[y][x] == STAR)
			{
				map[y][x] = 0;
				if (y + 1 < HEIGHT)
					map[y + 1][x] = STAR;
			}
		}
	}
}
void MapDraw(int map[][WIDTH], int character[])
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("│");
			else if (map[y][x] == STAR)
				printf("☆");
			else if (map[y][x] == 0)
				printf("  ");
			else if (character[Y] == y && character[X] == x)
				printf("옷");
		}
		printf("\n");
	}
}
void Move(int map[][WIDTH], int character[])
{
	char ch;
	if (kbhit())
	{
		map[character[Y]][character[X]] = 0;
		ch = getch();
		if (ch == 'a' || ch == 'A')
			if (map[character[Y]][character[X] - 1] != WALL)
				character[X]--;
		if (ch == 'd' || ch == 'D')
			if (map[character[Y]][character[X] + 1] != WALL)
				character[X]++;
		map[character[Y]][character[X]] = CHARACTER;
	}
}
int main()
{
	int level = EASY;
	int score = 0;
	int character[2] = { 0 };
	int map[HEIGHT][WIDTH] = { 0 };
	while (TRUE)
	{
		switch (Menu())
		{
		case 1:
			Init(map, character);
			WallPrint(map);
			srand((unsigned)time(NULL));
			while (map[character[Y] - 1][character[X]] != STAR)
			{
				UpdateStar(map);
				int x = rand() % 8 + 1;
				int num = rand() % 100;
				if (num < level)
					map[0][x] = STAR;
				system("cls");
				LevelPrint(level);
				MapDraw(map, character);
				Move(map, character);
				score += GameScore(map);
				printf("Score: %d", score);
				Sleep(150);
			}
			printf("\nGame Over");
			system("pause");
			Init(map, character);
			for (int y = 0; y < HEIGHT; y++)
			{
				for (int x = 0; x < WIDTH; x++)
				{
					map[y][x] = 0;
				}
			}
			score = 0;
			continue;

		case 2:
			while (TRUE)
			{
				system("cls");
				LevelPrint(level);
				switch (Setup())
				{
				case 1:
					level = EASY;
					continue;

				case 2:
					level = NORMAL;
					continue;

				case 3:
					level = HARD;
					continue;

				case 4:
					level = HELL;
					continue;

				case 5:
					break;
				}
				break;
			}
			continue;

		case 3:
			return 0;
		}
		return 0;
	}
}