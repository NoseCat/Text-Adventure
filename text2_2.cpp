#include <iostream>
#include <Windows.h>
#include "func2.h"
#include "func3.h"
#include "NecroGame.h"
#include "Opening.h"
#include "fight.h"
#include "Krestiki.h"

extern Player _player_;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
extern Player Necromancer;
extern Player Berserk;
extern bool WasAcademy;

bool textNecroPractise1_2NOTtriedRessurect = true;
bool textNecroPractise1_4FirstTime = true;
bool textNecroPractise1_4FoundSecretDoor = false;
bool wasInPodval = false;
bool Zombie = false;
bool Kovka1 = true;
bool Kovka2 = true;
int AmountOf�offinsChecked = 0;
int Coffin1 = 1;
int Coffin2 = 1;
int Coffin3 = 1;
int Coffin4 = 1;

//����� �������� ������� ����� �������� ����� ���� �����
void text2_2_1();
void text2_2_2();
void textNecroPractise();
void textNecroPractise1();
void textNecroPractise1_double();
void textNecroPractise1_1();
void textNecroPractise1_2();
void textNecroPractise1_2_double();
void textNecroPractise1_3();
void textNecroPractise1_4();
void textNecroPractise1_4_5();
void textNecroPractiseOut();
void tunnel();
void tunnel_2();
void ending2_1();
void textNecroPractise2();
void textNecroPractise3();
void letstryanother();
void aftermath();
void Graduation();

void text2_2()
{
	WasAcademy = true;
	printprint("� ���������� ��������������� ��������������������� ����������� ��������� �������� ����� ���������.\n������ ��� �� ����� ����� � � ������ ������� �����������.\n\n", 15);

	printprint("�� ������ �� ���� �� ����������. ������������� ������������� ��� ����� ������.\n\n",15);
	printprint("1) �����\n",15);
	printprint("2) �������\n",15);

	switch (choice(2))
	{
	case 1:
		text2_2_1();
		break;
	case 2:
		text2_2_2();
		break;
	default:
		printf("\ndefault. check text2_2()");
	}
}

void text2_2_1()
{
	system("cls");
	printprint("�� ������ ������� ����.\n", 15);
	Sleep(1000);
	printprint("��� ����������.\n", 15);
	Sleep(1000);
	printprint("����� ���������� � ���� ����� ����� ����������� �����. ������-�� �� �� �������� ���������.\n", 15);
	death();
}

void text2_2_2()
{
	system("cls");
	printprint("������ ��������� ����� ����������! �� ������� ����� ���������� \"���������� ������\". ������ ������ �� ��������. +5 iq\n", 15);
	_player_.intelligence += 5;
	system("pause");
	textNecroPractise();
}

void textNecroPractise()
{
	system("cls");
	printprint("�������� ������� - �������� �� �����������. � ��������� �� ������ ��� ���� ������� ���� ����.\n\n", 15);
	printprint("1) ���������� � �������� � ����� ������� ������\n", 15);
	printprint("2) ���������� ������ ������ ����� ��������� �� �����\n", 15);
	printprint("3) ����� ���� ������\n", 15);
	switch (choice(3))
	{
	case 1: textNecroPractise1(); break;
	case 2: textNecroPractise2(); break;
	case 3: textNecroPractise3(); break;
	default: printf("\ndefault\ncheck textNecroPractize\n");
	}
}

void textNecroPractise1()
{
	system("cls");
	if (!wasInPodval)
	{
		printprint("�� ���������� � ��������. ����� ����� �����. \n��� ��� �� ������: \n\n\n", 15);
		Sleep(1000);

		printprint("1) ���������\n", 15);
		printprint("2) ������������ ���������� \"���������� ������\"\n", 15);
		printprint("3) ������ �����\n", 15);
		printprint("4) �������� �����������\n", 15);

		switch (choice(4))
		{
		case 1: textNecroPractise1_1(); break;
		case 2: textNecroPractise1_2(); break;
		case 3: textNecroPractise1_3(); break;
		case 4: textNecroPractise1_4(); break;
		default: printf("\ndefault\ncheck textNecroPractise1\n");
		}
	}
	else
	{
		printprint("�� ��� ��� ����.\n\n", 15);
		system("pause");
		textNecroPractise();
	}
	
}
void textNecroPractise1_double()
{
	wasInPodval = true;
	printprint("�� � ��������. ����� ����� �����. \n��� ��� �� ������: \n\n\n", 15);
	Sleep(1000);

	printprint("1) ���������\n", 15);
	printprint("2) ������������ ���������� \"���������� ������\"\n", 15);
	printprint("3) ������ �����\n", 15);
	printprint("4) �������� �����������\n", 15);

	switch (choice(4))
	{
	case 1: textNecroPractise1_1(); break;
	case 2: 
		if (textNecroPractise1_2NOTtriedRessurect)
			textNecroPractise1_2();
		else
			textNecroPractise1_2_double();
		break;
	case 3: textNecroPractise1_3(); break;
	case 4: textNecroPractise1_4(); break;
	default: printf("\ndefault\ncheck textNecroPractise1_double\n");
	}
}

void textNecroPractise1_1()
{
	system("cls");
	printprint("�� ����������� �� ���� ���� � �������. ��� �� ����� � ���������. �� ��������� ��� �� ��� �� ������. ���� ���� �����.\n-5 iq, - 1 hp\n", 15);
	_player_.intelligence -= 5;
	_player_.health -= 1;
	printstat(_player_, health);
	printf("\n");
	if (_player_.health <= 0)
		death();
	textNecroPractise1_double();
}

void textNecroPractise1_2()
{
	system("cls");
	printprint("�� ������������ \"���������� ������\". �� ������� ��� ����������, ��� � ������� ���-�� ������������.\n������ �� ���������.\n", 15);
	textNecroPractise1_2NOTtriedRessurect = false;
	textNecroPractise1_double();
}

void textNecroPractise1_2_double()
{
	system("cls");
	printprint("�� ��� ��� ���������.\n", 15);
	textNecroPractise1_double();
}

void textNecroPractise1_3()
{
	system("cls");
	printprint("�� �� ������ ����� ����������.\n", 15);
	textNecroPractise1_double();
}

int required_int = 95;

void textNecroPractise1_4()
{
	if (textNecroPractise1_4FirstTime)
	{
		system("cls");
		printprint("�� ������ ����� �� ����� ������� ����� ����������� � �������� �� ������ � ����, ����� � ���������\n", 15);
		printprint("�������� �� ���� ����� ������. �������, � ��� ���������� � ������ �������� ���������� � ����������� ������.\n\n", 15);
	}
	textNecroPractise1_4FirstTime = false;
	printprint("�� � ��������. �� ���� ����� ������ �����. � ������� ����� ����� ��������� ����.\n\n", 15);

	printprint("1) ��������� ������ ����\n", 15);
	printprint("2) ��������� ������ ����\n", 15);
	printprint("3) ��������� ������ ����\n", 15);
	printprint("4) ��������� ��������� ����\n", 15);
	printprint("5) ��������� ����\n", 15);
	printprint("6) �����������\n", 15);
	printprint("7) ��������� ����\n", 15);
	printprint("8) ��������� �����\n", 15);
	printprint("9) ��������� ����������\n", 15);

	switch (choice(9))
	{
	case 1:
		system("cls");
		printprint("�� ���������� ������ ������� �����. ������, ������ ������ �����.\n", 15);
		AmountOf�offinsChecked += Coffin1;
		Coffin1 = 0;
		if (AmountOf�offinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 2:
		system("cls");
		printprint("�� ���������� ������ ������� �����. �������, �� ������ ������ �����.\n", 15);
		AmountOf�offinsChecked += Coffin2;
		Coffin2 = 0;
		if (AmountOf�offinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 3:
		system("cls");
		printprint("�� ���������� ������ �������� �����. ������ ���-�� ������������ �����.\n", 15);
		AmountOf�offinsChecked += Coffin3;
		Coffin3 = 0;
		if (AmountOf�offinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 4:
		system("cls");
		printprint("�� ���������� ������ ���������� �����. � ���... ����������... ��� ��... \n�����.\n", 25);
		AmountOf�offinsChecked += Coffin4;
		Coffin4 = 0;
		if (AmountOf�offinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 5: 
		textNecroPractise1_4_5();
		break;
	case 6:
		system("cls");
		printprint("��...\n", 35);
		textNecroPractise1_4();
		break;
	case 7:
		system("cls");
		printprint("�� ������� � ����, ������, � ���-�� �������, ��� � �������� ��������.\n", 15);
		printstats(_player_);
		printf("\n");
		textNecroPractise1_4();
		break;
	case 8:
		system("cls");
		printprint("�� ��������� �����. �� ���� ���� ������� ����� �� ���������� �����, � ����� ��������� ���� ������� ����,\n",15);
		printprint("���������� ��������� ��������. ��������, ����� ���� �������� �����.\n", 15);
		if (!textNecroPractise1_4FoundSecretDoor)
			required_int -= 5;
		textNecroPractise1_4FoundSecretDoor = true;
		textNecroPractise1_4();
		break;
	case 9:
		system("cls");
		if (Kovka1)
		{
			printprint("������?\n\n1) �����\n2) �� ����\n", 15);
			switch (choice(2))
			{
			case 1:
				enchantment(_player_);
				printf("\n");
				printstat(_player_, strength);
				printf("\n");
				Kovka1 = false;
				textNecroPractise1_4();
				break;
			case 2:
				system("cls");
				textNecroPractise1_4();
				break;
			}
		}
		else
		{
			printprint("���������� ���� ��������.\n", 15);
			textNecroPractise1_4();
		}
		break;
	default:
		printf("\ndefault check textNecroPractise1_4()");
	}
}

void textNecroPractise1_4_5()
{
	system("cls");
	printprint("�� ��������� ����. �� ��� ������ ������ ����������� ���������.\n����� ��������� ���������� ���� �� �������� ������ � ��������� ���������.\n��� ��� �� ����������.", 15);
	textNecroPractiseOut();
}

void textNecroPractiseOut()
{
	printprint("\n��������, ������ �� ��� �� �������.\n\n", 15);
	printprint("1) ��������� ������\n", 15);
	if (textNecroPractise1_4FoundSecretDoor)
		printprint("2) ����� ����� ������ ������\n", 15);
	else
		printprint("2) �������� ��������� ����\n", 15);
	printprint("3) ���������� ����������� ��������\n", 15);
	switch (choice(3))
	{
	case 1: 
		textNecroPractise();
		break;
	case 2: 
		if(_player_.intelligence >= required_int)
			tunnel();
		else
		{
			system("cls");
			printprint("����� ��������� �����. � ��� �� ���������� ����� ��������� ������.\n", 15);
			textNecroPractise1_4();
		}
		break;
	case 3:
		system("cls");
		textNecroPractise1_4();
		break;
	default:
		printf("\ndefault\ncheck textNecroPractiseOut\n");
	}
}

void tunnel()
{
	system("cls");
	printprint("�� ���������� �������� �� ��� ������ � ������� � ������ ������ ������ � ������� ������ ��������� �����.\n", 15);
	printprint("��� ��� ������ �������� ��� ���� ������� ������, ��� ����� �� ��������� �� ����� ������� �����.\n����� ����� �� ���� ���������.\n\n", 15);
	printprint("��� �������� ����� ������ �������. ���� ����� (� ������ �� ������ ����� ��� �������� ����) �� �����, \n�� ��� �������� ������ � ���� ������������.\n", 15);
	printprint("����� �� ���� ������� ��������, ������ ���� ����� �� �����.\n\n", 15);
	printprint("�� ������ � ��� ������ �� ����������� �� ������� ������� \n���������� ��������� � �������� �������� - ����������� ���������.\n", 15);
	printprint("�� ��������� ��� ���������, �� � ����� ��������� �� ����� ��� �������. ��� �������� ����...\n\n", 15);
	printprint("1) ���� ������.\n", 15);
	printprint("2) ����������.\n", 15);

	switch (choice(2))
	{
	case 1:
		system("cls");
		printprint("�� ������ �� ���������� ������ 1 ������.\n", 15);
		printprint("�� �������� ����������� ���� �� ���������. -5 iq\n", 15);
		_player_.intelligence -= 5;
		printprint("�� �������� ��������. +5 �����.\n", 15);
		_player_.kind_evil += 5;
		tunnel_2();
		break;
	case 2:
		system("cls");
		printprint("�� ������������ \"���������� ������\"...", 30);
		if (NecroGame() == 1)
		{
			system("cls");
			Zombie = true;
			printprint("�� ���������� ������ 1 ������! ������ �� ���� ������� �����(1).\n", 15);
			printprint("�� ���� �� ��������� � ���������� ���� �����. + 5 iq\n", 15);
			_player_.intelligence += 5;
			printprint("�� ��������� ���������� ��������. -5 �����.\n", 15);
			_player_.kind_evil -= 5;
		}
		else 
		{
			system("cls");
			printprint("�� ������ �� ���������� ������ 1 ������.\n", 15);
			printprint("�� �������� ����������� ���� �� ���������. -5 iq\n", 15);
			_player_.intelligence -= 5;
			printprint("�� �������� ��������. +5 �����.\n", 15);
			_player_.kind_evil += 5;
		}
		tunnel_2();
		break;
	}
}
bool CornerStand = true;
bool CornerWeb = true;
bool Chest = true;

void tunnel_2()
{
	printprint("�� ������������ ������ �� ������� ��� ������ �����������, ���� ������� �� �������� �����.\n", 15);
	printprint("����� ���� ��������� ����� ���������� ���������� �������. � ���� ����� �������. � ������ ���� ����� ������.\n", 15);
	printprint("� ������� ���� ������ ���. � ��������� ���� �������. � ��������� ���� ����� ����������.\n\n", 15);
	
	printprint("1) �������.\n2) ������.\n3) ������ � ����.\n4) ������ �������.\n5) ������.\n", 15);

	switch (choice(5))
	{
	case 1:
		system("cls");
		printprint("1) �����������.\n2) ���������.\n3) ���������.\n", 15);
		switch (choice(3))
		{
		case 1:
			printstats(_player_);
			system("pause");
			system("cls");
			tunnel_2();
			break;
		case 2:
			printprint("������� ������� � �����!\n", 15);
			Player enemy;
			fill_player(enemy, _player_);
			if (Zombie)
			{
				printprint("��� ����� �������� ������� � ������� 15 �����. ����� ��������.\n", 15);
				enemy.health -= 15;
			}
			Sleep(1000);
			fight(enemy);
			ending2_1();
			break;
		case 3:
			tunnel_2();
		}
		break;
	case 2:
		if (Chest)
		{
			printprint("�� ������ ������� ���������� �����. ������ ����� ��� ������� ����� ������ ������� �����������.", 15);
			system("pause");
			if (krestiki() == 1)
			{
				printprint("�����! � ������� ������ ������, ��������� ���������� ������, �� �������. +5 ����\n", 15);
				_player_.strength += 5;
			}
			else
				printprint("� ��� �� ���������� �������� ������.", 15);
			Chest = false;
			tunnel_2();
		}
		else
		{
			printprint("��� ������ ���.\n", 15);
			tunnel_2();
		}
		break;
	case 3:
		system("cls");
		if (CornerStand)
		{
			printprint("�� ������ � ���� ����� �������� ���� �� ��� ���� ���� ��������. +10 �����.\n", 15);
			_player_.kind_evil += 10;
			CornerStand = false;
			tunnel_2();
		}
		else
		{
			system("cls");
			printprint("��� ������ ���.\n", 15);
			tunnel_2();
		}
		break;
	case 4:
		system("cls");
		if (CornerWeb)
		{
			printprint("�� ��������� ����� ������ �������� ������. -10 �����.\n", 15);
			_player_.kind_evil -= 10;
			CornerWeb = false;
			tunnel_2();
		}
		else
		{
			system("cls");
			printprint("��� ������ ���.\n", 15);
			tunnel_2();
		}
		break;
	case 5:
		if (Kovka2)
		{
			printprint("������?\n\n1) �����\n2) �� ����\n", 15);
			switch (choice(2))
			{
			case 1:
				enchantment(_player_);
				printf("\n");
				printstat(_player_, strength);
				printf("\n");
				Kovka2 = false;
				tunnel_2();
				break;
			case 2:
				system("cls");
				tunnel_2();
				break;
			}
		}
		else
		{
			system("cls");
			printprint("���������� ���� ��������.\n", 15);
			tunnel_2();
		}
		break;
	}
}

void ending2_1()
{
	if (_player_.kind_evil > 0)
	{
		printprint("�� �������� ����.\n� ����� �� ���������� ��� �� ������� ��� ������, �� ������ ������ ������ ���� � ��������� ������� �����,\n� ��� � ���� ��������� ���������!\n", 15);
		printprint("\n�����!", 5);
		Sleep(2000);
		exit(0);
	}
	else
	{
		printprint("�� �������� ����.\n�� ��� ������?\n� ������� ��������� � �����, �� ������� � ����� �������� �� ��������� ����������, � �� ���� ��������� ����.\n", 15);
		printprint("��� �������� ������ �������� � ����� �������� � �������� ����������� �����.", 15);
		printprint("\n�����!", 5);
		Sleep(2000);
		exit(0);
	}
}

void textNecroPractise2()
{
	system("cls");
	printprint("�� ����������� � ������, �� ���� �����������: \"���� �� � ������������ ���� ������ �������� ������� �����?\"\n", 15);
	printprint("����� � ������ ����� ���� ������ ����������� �������:\n\n", 15);
	Sleep(1001);
	printprint("� ���� ����� ��� ��������. ������ �� ������ �� ������ ������ ���.\n\n", 15);
	printprint("1) ���������\n2) ���������� ������������\n", 15);

	switch (choice(2))
	{
	case 1:
		Player Narcomant;
		fill_player(Narcomant, Necromancer);
		strcpy_s(Narcomant.p_class, "���������");
		Narcomant.strength += 10;
		fight(Narcomant);
		aftermath();
		break;
	case 2:
		system("cls");
		printprint("�� ���������� ��� ������� ������ ������. ���� �� ��������� �� ����������� ��� ������.\n�� �� �����������, �� ������� ��������.\n", 15);
		system("pause");
		if (krestiki() == 1)
		{
			aftermath();
		}
		else
		{
			printprint("�� ���������, ������ ����������� ��� �� �� ��� ���.\n", 15);
			system("pause");
			letstryanother();
		}
	}
}

void textNecroPractise3()
{
	system("cls");
	printprint("�� �������� ���������� ��������...\n", 10);
	fight(Necromancer);
	system("cls");
	printprint("�� �������� ����������! � ��� �� ����-�� ��������� +1 iq, +1 ����.\n", 15);
	_player_.intelligence += 1;
	_player_.strength += 1;
	printprint("������ ��� �� ������ ���������� ������������ ���������� ��� ��������� �� ��������� �� �������.\n", 15);
	system("pause");
	letstryanother();
}

void letstryanother()
{
	system("cls");
	Begining();
	/*printprint("��� �� ��� ����� ������.\n\n", 15);

	printprint("1) ����� � ���\n", 15);
	printprint("2) ����� � ����\n", 15);

	switch (choice(2))
	{
	case 1:
		forest(); 
		break;
	case 2:
		Circus(); 
		break;
	}*/
}

void aftermath()
{
	system("cls");
	printprint("�� ��������! ������ ���������� � �����������.\n\n", 15);
	printprint("1) ����������\n", 15);
	printprint("2) � ������, ��� �� ��� ������� ���.. � ������� ������ ������ �����.\n", 15);

	switch (choice(2))
	{
	case 1:
		system("cls");
		printprint("�� ������������ \"���������� ������\"...", 30);
		if (NecroGame() == 1)
		{
			system("cls");
			Zombie = true;
			printprint("�� ���������� ������ 1 ������! ������ �� ���� ������� �����(1).\n", 15);
			printprint("�� ���� �� ��������� � ���������� ���� �����. + 5 iq\n", 15);
			_player_.intelligence += 5;
			printprint("�� ��������� ���������� ��������. -5 �����.\n", 15);
			_player_.kind_evil -= 5;
			printprint("�������! ������ ����� ���������� �����.\n", 15);
			system("pause");
			Graduation();
		}
		else
		{
			system("cls");
			printprint("�� ������ �� ���������� ������ 1 ������.\n", 15);
			printprint("�� �������� ����������� ���� �� ���������. -5 iq\n", 15);
			_player_.intelligence -= 5;
			printprint("�� �������� ��������. +5 �����.\n", 15);
			_player_.kind_evil += 5;
			printprint("��� � �� �� ��������� �� �����?\n������ ����������� ��� �� ��� ���...\n", 15);
			system("pause");
			letstryanother();
		}
		break;
	case 2:
		system("cls");
		printprint("������ ����������� ��� �� ��� ���...\n", 10);
		letstryanother();
		break;
	}
}

void Graduation()
{
	system("cls");
	printprint("���� ��������, � � ��� ��� ����! ����� ��� ��� �����������?\n\n1)� ������� (����� ����� �������)\n2) ��������� � ��������� �� ����.\n", 15);
	switch (choice(2))
	{
	case 1:
		printprint("�� ������� ��� ��� � ����� ���, � ������ ����� �������� �� ����� ������� � ������� �� ��������� ��������� - ������ �������...\n\n", 15);
		Player Dragon;
		fill_player(Dragon, Berserk);
		strcpy_s(Dragon.p_class, "������");
		Dragon.max_health = 200;
		Dragon.health = 200;
		Dragon.defense = 20;
		if (Zombie)
		{
			printprint("��� ����� �������� ������� � ������� 15 �����. ����� ��������.\n", 15);
			Dragon.health -= 15;
		}
		fight(Dragon);
		system("cls");
		printprint("�� ��������! ��� ������ ������� ������ ����! ��� ��� �����������, � �� ���� �����������!\n\n", 15);
		printprint("�����!", 5);
		Sleep(2000);
		exit(0);
		break; //������ ����� :(
	case 2:
		printprint("������ � ��������� ���������� �� ��������� �� ����������...\n\n", 15);
		if (_player_.intelligence >= 100)
		{
			printprint("���� ����� ������ ������� � �� ������ ���������� �� ������������������ ��������� � ������� �������� ���������� �����.\n", 15);
			printprint("����� � ���������� ����������� � ��� �� ����������, \n������ �����, ������������ - ��� � ���� ��������� ���������.\n\n", 15);
		}
		else
		{
			printprint("���� ����� ������ ������ � �� ������ ���������� ������ � ��������� �������� �������� ���������� �����.\n", 15);
			printprint("����� ���������� ����������� � ��� �� ���������� � �� �� ����� �� ���������� ����������� �����������, \n������ �����, ������������ - ��� � ���� ��������� ���������.\n\n", 15);
		}
		printprint("�����!", 5);
		Sleep(2000);
		exit(0);
		break;
	}
}