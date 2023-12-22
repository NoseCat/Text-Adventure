#pragma region krest
#include <iostream>

using namespace std;

int mass[3][3];
int  won;

void hod_player()
{
	int vert, goriz;
	bool mesto = false;
	cout << endl << "ваш ход (вертикаль, горизонталь (без пробелов))" << endl;
	do {
		if (mesto == true)
			cout << endl << "это место занято" << endl;
		mesto = false;
		scanf_s("%d", &goriz);
		if (goriz > 9 and goriz < 100)
		{
			vert = goriz % 10; goriz = goriz / 10;
		}
		else
			scanf_s("%d", &vert);
		if (goriz > 0 and goriz <= 3 and vert > 0 and vert <= 3)
			if (mass[vert - 1][goriz - 1] != 0)
				mesto = true;

	} while (!(goriz > 0 and goriz <= 3 and vert > 0 and vert <= 3) or mesto);
	mass[vert - 1][goriz - 1] = 1;

}
void print_pole()
{
	system("cls");
	cout << "     1   2   3" << endl;
	cout << "______________" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " " << i + 1 << " | ";
		for (int j = 0; j < 3; j++)
		{
			if (mass[i][j] == 0)
				cout << " ";
			else if (mass[i][j] == 1)
				cout << "X";
			else if (mass[i][j] == 3)
				cout << "O";
			if (j < 2)
				cout << " | ";
		}
		if (i < 2)
			cout << endl << "   |———————————" << endl;
	}

}
void proverka()
{
	int count = 0;
	if (mass[0][0] == mass[0][1] and mass[0][0] == mass[0][2])
		won = mass[0][0];
	else if (mass[0][0] == mass[1][0] and mass[0][0] == mass[2][0])
		won = mass[0][0];
	else if (mass[1][0] == mass[1][1] and mass[1][0] == mass[1][2])
		won = mass[1][1];
	else if (mass[0][1] == mass[1][1] and mass[0][1] == mass[2][1])
		won = mass[1][1];
	else if (mass[2][0] == mass[2][1] and mass[2][0] == mass[2][2])
		won = mass[2][2];
	else if (mass[0][2] == mass[1][2] and mass[0][2] == mass[2][2])
		won = mass[2][2];
	else if (mass[0][0] == mass[1][1] and mass[0][0] == mass[2][2])
		won = mass[1][1];
	else if (mass[2][0] == mass[1][1] and mass[0][2] == mass[2][0])
		won = mass[1][1];
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (mass[i][j] != 0)
					count++;
		}
		if (count == 9)
			won = 5;
	}
}
void hod_enemy()
{
	int i;
	int j;
	bool nothing;
	do {
		nothing = true;
		i = rand() % 3;
		j = rand() % 3;
		if (mass[i][j] != 0)
			nothing = false;
	} while (!nothing);
	mass[i][j] = 3;
}
int krestiki()
{
	mass[3][3] = {};
	won = 0;
	print_pole();
	do
	{
		hod_player();
		proverka();
		if (won == 0)
		{
			hod_enemy();
		}
		print_pole();
		proverka();
	} while (won == 0);
	if (won == 1)
		cout << endl << "Победа!";
	if (won == 3)
		cout << endl << "Поражение...";
	if (won == 5)
		cout << endl << "Ничья";
	return won;
}
/*
//  0 1   2   3  4
0
1   0 | 0 | 0
—————————
2   0 | 0 | 0
—————————
3   0 | 0 | 0
4*/
#pragma endregion