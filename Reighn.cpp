#include <iostream>
#include "func2.h"

void randEvent()
{
	switch (rand() % 20)
	{
	case 0: printprint("\"��� ������ ����� ��������!\"", 15); break;
	case 1: printprint("\"��� ������ ����� � ������!\"", 15); break;
	case 2: printprint("��� ������� �������� ��������� ��������� ����� �� ����.", 15); break;
	case 3: printprint("��� ������� �������� ��������� ��������� ����� �� ����.", 15); break;
	case 4: printprint("������� ����� �� ��������� ����. ��� ����� �����.", 15); break;
	case 5: printprint("������� ����� �� ��������� ����. ��� ����������� ����.", 15); break;
	case 6: printprint("����c�� ���������� ��� ��������� ��� ������ ��� ���������� �������.\n��� ������� � �������������?", 15); break;
	case 7: printprint("�� ������� � ������� ����! ��� ������� �����. ��� ������� � ������������?", 15);  break;
	case 8: printprint("� ��� �������� ������������ ������� �������. �� � ������ �������� ���-�� ���������.\n�� �� ������ �� �����.", 15);  break;
	case 9: printprint("���-�� ��������� � ���� ������������ ����������.", 15);  break;
	case 10: printprint("�� ������� ������������� ���� ��������� �����!", 15);  break;
	case 11: printprint("� ������ ������ �������� ����� ����!", 15);  break;
	case 12: printprint("������ �� ���������.", 15); break;
	case 13: printprint("���� ��������� ����. ����� � ������.", 15); break;
	case 14: printprint("������������, ��� ���-�� ������ ����������.", 15); break;
	case 15: printprint("�� ������� 20-� �������. ��� ������ 21.", 15); break;
	case 16: printprint("��� ������ ������ �� �������� ��������. \n������ �������� ����������� ����� ������� �� ���-�� �� ����� �� ����� �� ���.", 15); break;
	case 17: printprint("������� ������������ �������.", 15); break;
	case 18: printprint("� ������� ��������� �������� ����.", 15); break;
	case 19: printprint("� ������ ����. � ���� � ����������� ����.", 15); break;
	}
}

void randAction()
{
	switch (rand() % 14)
	{
	case 0: printprint("������", 15); break;
	case 1: printprint("�������� ��������", 15); break;
	case 2: printprint("�������� ��������������", 15); break;
	case 3: printprint("���������", 15); break;
	case 4: printprint("�����������", 15); break;
	case 5: printprint("���������", 15); break;
	case 6: printprint("������ �����", 15); break;
	case 7: printprint("���� �����", 15); break;
	case 8: printprint("���� �����", 15); break;
	case 9: printprint("�����������", 15); break;
	case 10: printprint("�� �����������", 15); break;
	case 11: printprint("������ �� ������", 15); break;
	case 12: printprint("������", 15); break;
	case 13: printprint("����� ��������", 15); break;
	}
}

int randGain()
{
	int Gain = rand()%4 * 10;
	if (rand() % 2 == 0)
		Gain = -Gain;
	if (rand() % 2 == 0)
		printf("+?");
	else
		printf("%d", Gain);
	return Gain;
}

int Reighn()
{
	int reputation = 50;
	int money = 50;

	int money1, money2;
	int rep1, rep2;

	system("cls");
	printprint("�� ������ �� ���� ���� ���������� ������������.\n", 15);
	printprint("���� ������ �� ���� ��������� ���������� �� 0.\n� �� �� �����, ���� ���� ��������� ���������� �� 0 ��� ��������.\n", 15);
	printprint("��� ����� ���������� 2 �������� ������� �� �������.\n��������� � ����: ����������� ������ ����� ���� ����������������(� ����� ���� ��������������)\n������������ 15 ����\n", 15);
	printprint("�����!\n", 15);
	system("pause");

	for (int i = 1; i <= 15; i++)
	{
		system("cls");
		printf("���� %d: ��������� - %d, ��������� - %d\n\n", i, money, reputation);
		randEvent();
		printf("\n1) "); randAction(); printf(" (��������� "); money1 = randGain(); printf(", ��������� "); rep1 = randGain(); printf(")");
		printf("\n2) "); randAction(); printf(" (��������� "); money2 = randGain(); printf(", ��������� "); rep2 = randGain(); printf(")");
		printf("\n");

		switch (choice(2))
		{
		case 1:
			money += money1;
			reputation += rep1;
			break;
		case 2:
			money += money2;
			reputation += rep2;
			break;
		}
		if (money > 100)
			money = 100;
		if (reputation > 100)
			reputation = 100;
		if (money <= 0)
		{
			printprint("����� �����. ������ � �������.\n", 15);
			system("pause");
			return -1;
		}
		if (reputation <= 0)
		{
			printprint("��� ������������ ����� ���������. �������� ���� ������ �����.\n", 15);
			system("pause");
			return -2;
		}
	}
	return 1;
}

