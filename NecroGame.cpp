#include <iostream>
#include <windows.h>

const int GlobalRows = 4;
const int GlobalColomns = 4;

void BoardPrint(bool Board[GlobalColomns][GlobalRows])
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("Вы - очень неопытный некромант, поэтому не можете воскресить нежить по щелчку пальцев.\nВам нужно ");
	printf("сначала воскресить все органы трупа. \nОднако, так как все органы любого существа взаимосвязаны, когда вы ");
	printf("воскрешаете орган - начинают работать и все соседние.\nКроме того, если применить воскрешение на уже живой");
	printf(" орган, он умирает.\nВыбрать цель заклининия можно указав без пробела сначала колонку, потом строку в таблице.\n");
	printf("\n   ");
	for (int i = 0; i < GlobalColomns; i++)
		printf("%i  ", i + 1);
	for (int i = 0; i < GlobalRows; i++)
	{
		printf("\n%i  ", i + 1);
		for (int j = 0; j < GlobalColomns; j++)
		{
			if(Board[j][i])
				SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("%i  ", (int)Board[j][i]);
		}
		SetConsoleTextAttribute(hwnd, 7);
	}
	printf("\n\n1) Сбросить\n2) Сдаться\n\n");
}

int ChooseTile()
{
	int input, row, colomn;
	do
	{
		scanf_s("%i", &input);
		if (input == 1)
			return input;
		if (input == 2)
			return input;
		row = input % 10;
		colomn = input / 10;
	} while(row > GlobalRows || row <= 0 || colomn > GlobalColomns || colomn <= 0);
	return input;
}

void ApplyChoice(int input, bool Board[GlobalColomns][GlobalRows])
{
	int row = input%10 - 1;
	int colomn = input/10 - 1;
	//check for safety of this was already in ChooseTile()
	Board[colomn][row] = !Board[colomn][row];

	if (colomn + 1 <= GlobalColomns - 1)
		Board[colomn + 1][row] = !Board[colomn + 1][row];
	if (colomn - 1 >= 0)
		Board[colomn - 1][row] = !Board[colomn - 1][row];
	if (row + 1 <= GlobalRows - 1)
		Board[colomn][row + 1] = !Board[colomn][row + 1];
	if (row - 1 >= 0)
		Board[colomn][row - 1] = !Board[colomn][row - 1];
}

bool WinCheck(bool Board[GlobalColomns][GlobalRows])
{
	for (int i = 0; i < GlobalColomns; i++)
		for (int j = 0; j < GlobalRows; j++)
			if (!Board[i][j])
				return false;
	return true;
}

void ClearBoard(bool Board[GlobalColomns][GlobalRows])
{
	for (int i = 0; i < GlobalColomns; i++)
		for (int j = 0; j < GlobalRows; j++)
			Board[i][j] = false;
}

int NecroGame()
{
	bool Board[GlobalColomns][GlobalRows] = {};
	int Tile;
	while (!WinCheck(Board))
	{
		system("cls");
		BoardPrint(Board);
		Tile = ChooseTile();
		switch (Tile)
		{
		case 1:
			ClearBoard(Board);
			break;
		case 2:
			return 0;
			break;
		default:
			ApplyChoice(Tile, Board);
		}		
	}

	system("cls");
	BoardPrint(Board);
	return 1;

}