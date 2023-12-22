#include <iostream>
#include <Windows.h>
#include "Opening.h" 

bool WasCirc;
bool WasAcademy;

//�������� ������
int choice(int amountOfChoices)
{
	int choice;
	do
	{
		scanf_s("%i", &choice);
	} while (choice <= 0 || choice > amountOfChoices);

	return choice;
}

//������� ����� �� ������ speed ������� ������ 15
void printprint(const char text[], int speed)
{
	char EndSimbol[] = ".!?";
	for (int i = 0; text[i] != EndSimbol[3]; i++)
	{
		printf("%c", text[i]);
		if (text[i] == EndSimbol[0] || text[i] == EndSimbol[1] || text[i] == EndSimbol[2])
			Sleep(200 * speed/15.0f);
		Sleep(speed);
	}
}

//������ ��� ����� ������ �������� �� ���� ���������� �����������. ��������� ������ ������ ��� ����
void death()
{
	Sleep(500);
	printprint("\n���� ��������.\n\n", 150);
	printprint("1) ������ � ������\n", 15);
	printprint("2) �����\n", 15);
	switch (choice(2))
	{
	case 1:
		system("cls");
		WasCirc = false;
		WasAcademy = false;
		NameEnter();
		break;
	case 2:
		exit(0);
		break;
	default:
		printf("default\ncheck death()\n");
	};
}