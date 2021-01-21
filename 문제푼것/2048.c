#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>

#define TRUE 1
#define SIZE 4
#define MAX 10000

void DrawMap(int* score, int board[][4])
{
	system("cls");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
				printf("    .");
			else
				printf("%5d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Score: %d", *score);
}

void NewNum(int board[][4])
{
	int count = 0;
	int* p[16] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 0)
			{
				p[count] = &board[i][j];
				count++;
			}
	}
	if (count != 0)
		*p[rand() % count] = (rand() % 100 < 80) ? 2 : 4;
}
void CheckGameover(int board[][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 0)
				return;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1])
				return;
	for (int i = 0; i < 3; i++)
		if (board[i][3] == board[i + 1][3])
			return;
	for (int j = 0; j < 3; j++)
		if (board[3][j] == board[3][j + 1])
			return;

	printf("\nGame Over!");
	exit(0);
}

void main()
{
	int board[SIZE][SIZE] = {
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,0,0 } };

	char key;
	int act = 0;
	int score = 0;

	srand((unsigned)time(NULL));
	NewNum(board);
	NewNum(board);
	DrawMap(&score, board);

	while (TRUE)
	{
		key = getch();
		if (key == 'a' || key == 'A')
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					for (int r = j; r > 0; r--)
					{
						if (board[i][r] == 0 || board[i][r] > MAX)
							break;
						if (board[i][r - 1] != 0 && board[i][r - 1] != board[i][r])
							break;
						if (board[i][r - 1] == 0)
							board[i][r - 1] = board[i][r];
						else if (board[i][r - 1] == board[i][r])
						{
							board[i][r - 1] *= 2;
							board[i][r - 1] += MAX;
							score += 2 * (board[i][r]);
						}
						board[i][r] = 0;
						act++;
					}
				}
			}
		}

		if (key == 'd' || key == 'D')
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 2; j >= 0; j--)
				{
					for (int r = j; r < 3; r++)
					{
						if (board[i][r] == 0 || board[i][r] > MAX)
							break;
						if (board[i][r + 1] != 0 && board[i][r + 1] != board[i][r])
							break;
						if (board[i][r + 1] == 0)
							board[i][r + 1] = board[i][r];
						else if (board[i][r + 1] == board[i][r])
						{
							board[i][r + 1] *= 2;
							board[i][r + 1] += MAX;
							score += 2 * (board[i][r]);
						}
						board[i][r] = 0;
						act++;
					}
				}
			}
		}

		if (key == 'w' || key == 'W')
		{
			for (int j = 0; j < 4; j++)
			{
				for (int i = 1; i <= 3; i++)
				{
					for (int r = i; r > 0; r--)
					{
						if (board[r][j] == 0 || board[r][j] > MAX)
							break;
						if (board[r - 1][j] != 0 && board[r - 1][j] != board[r][j])
							break;
						if (board[r - 1][j] == 0)
							board[r - 1][j] = board[r][j];
						else if (board[r - 1][j] == board[r][j])
						{
							board[r - 1][j] *= 2;
							board[r - 1][j] += MAX;
							score += 2 * (board[r][j]);
						}
						board[r][j] = 0;
						act++;
					}
				}
			}
		}

		if (key == 's' || key == 'S')
		{
			for (int j = 0; j < 4; j++)
			{
				for (int i = 2; i >= 0; i--)
				{
					for (int r = i; r < 3; r++)
					{
						if (board[r][j] == 0 || board[r][j] > MAX)
							break;
						if (board[r + 1][j] != 0 && board[r + 1][j] != board[r][j])
							break;
						if (board[r + 1][j] == 0)
							board[r + 1][j] = board[r][j];
						else if (board[r + 1][j] == board[r][j])
						{
							board[r + 1][j] *= 2;
							board[r + 1][j] += MAX;
							score += 2 * (board[r][j]);
						}
						board[r][j] = 0;
						act++;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i][j] > MAX)
					board[i][j] -= MAX;
			}
		}

		if (act > 0)
		{
			NewNum(board);
			DrawMap(&score, board);
			CheckGameover(board);
		}
	}
}