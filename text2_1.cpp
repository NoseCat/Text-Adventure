#include <iostream>
#include <Windows.h>
#include "func2.h"
#include "func3.h"
#include "Opening.h"
#include "Krestiki.h"
#include "Reighn.h"
#include "fight.h"
#include "text2_2.h"
extern Player _player_;
extern bool WasAcademy;
bool excalibur = false;
bool info_exc = false;
bool namefalse = false;
bool mission = false;
bool king = false;
bool destroy = false;
int choice_on_village = 0;
//int intelect = 10;
int socialreit = 0;
//int evil = 0;
struct enemy
{
	int healht;
	int armor;
	int attack;
	int time_hod;
	int chardg;
}ant_colonies{ 20000000,500,1,1,0 };


//����� �������� ������� ����� �������� ����� ���� �����
void text_find_village();
void text_Excalibur();
void text_ant_anthill();
void text_Excalibur_vor();
void text_Excalibur_diolog();
void text_Excalibur_hero();
void text_Excalibur_vor_kill();
void text_Excalibur_vor_save();
void text_find_village();
void text_festival();
void destroy_village();
void end_microforest();
void text_jail();
void pinok();
/*
1 ������� ��������
2 ���� �� ������
3 ������� � �����
4 ��������� ����
5 �� 4 ����� � ���

*/
void gamescissors()
{

	printprint("1) ������� �������\n", 15);
	printprint("2) ������� ������\n", 15);
	printprint("3) ������� ������\n", 15);
	for (int i = 1; i <= 3; i++)
	{
		switch (choice(3))
		{
		case 1:
			printf("�� ������� ������� - ��������� ������ �� ��������� %i:0 \n", i); break;
		case 2:
			printf("�� ������� ������ - ��������� ������ �� ��������� %i:0 \n", i); break;
		case 3:
			printf("�� ������� ������ - ��������� ������� �� ��������� %i:0 \n", i); break;
		}
	}
	if(!destroy)
		printprint("�� ���������.����� ������������\n �� ����� ������ -1 �����\n", 15);
	system("pause");
	_player_.strength -= 1;

}
void fight_ant_anthill()
{
	if (mission == true)
		printprint("������ ��� �� ����� �������\n", 15);
	bool endfight = false;
	bool palka = true;
	do {
		printf("��: %.0f hp\n", _player_.health);
		printf("�������: %d ���-��\n", ant_colonies.healht);
		int block = 0;
		int vibor;
		
		printf("���� ��������:\n1)��������� \n2)������������ \n3)���������� ��� \n4)����������\n5)�������\n");
		do { scanf_s("%d", &vibor); } while (vibor < 1 or vibor>5);system("cls");
		if (vibor == 1)
		{
			_player_.stamina -= _player_.strength;
			if (_player_.stamina < 0)
			{
				printf("��� �� ������� ��� �������\n");
				_player_.stamina = 0;
			}
			else
			{
				if (_player_.strength > ant_colonies.armor)
					ant_colonies.healht -= _player_.strength;
				else
					ant_colonies.healht--;
				if (ant_colonies.healht <= 0)
					endfight = true;
			}
			
		}
		if (vibor == 2)
		{
			printf("������������:\n");
			printf("1) �������� ����\n");
			printf("2) ����� \n");
			int vibor2;
			
			do { scanf_s("%d", &vibor2); } while (vibor2 < 1 or vibor2>2);
			if (palka)
			{
				if (vibor2 == 1)
				{
					printf("�� �������� �������� ����� ���� ��������, ������� ������ ������� \n");
					ant_colonies.healht -= 30000 + rand();
				}
				if (vibor2 == 2)
				{
					printf("�� ������� � ���������� ������, ������� ����� � ������ �� ������ � ������� ��� ����� \n");
					ant_colonies.attack += _player_.defense;
					palka = false;
				}
			}
			else
			{
				if (vibor2 == 1)
				{
					printf("�� �������� �������� ����� ���� ��������, ��� ��� ������� \n");
					ant_colonies.healht = 0;
					endfight = false;
				}
				if (vibor2 == 2)
					printf("�� ������� � ���������� ������, ������ ��� ��� �������� ������������ (������ �� ��������) \n");
			}
		}
		if (vibor == 3)
			_player_.stamina += _player_.max_stamina / 2;
		if (vibor == 4)
			printf("�� ��������� ���������� �� �������, �� ��� �������� ��� ����� � ���������� ��� ���� \n");
		if (vibor == 5)
			endfight = true;
		if (ant_colonies.healht > 0)
		{
			ant_colonies.chardg++;
			if (ant_colonies.chardg >= ant_colonies.time_hod)
			{
				if (palka)
					printf("���� ���� ��������� ������, ��� ������� �� ����� � ��������� -0 hp\n ");
				else
				{
					_player_.health -= (ant_colonies.attack - _player_.defense);
					printf("��� �� �� ��������� -%d hp\n ", (ant_colonies.attack - _player_.defense));
					if (_player_.health <= 0)
					{
						printf("�� ������ �� ��������, ��������� ����� ��������� ������.\n ");
						exit(0);
					}
				}
			}
		}
		
	} while (!endfight);
	system("cls");
	printprint("�� ����������� ����� ��������, � �������, ��� �� ����� ����� ����, ����� �������� ������ � ������� �� ������ \n", 15);
	if (mission)
	{
		printprint("1) ��������� �����\n", 15);
		printprint("2) ��������� � �������\n", 15);
		switch (choice(2))
		{
		case 1:
			
			system("cls");
			printprint("�� ������������� � �������� ��������� ������. ����������. \n", 15);
			exit(0);
			break;
		case 2:
			system("cls");
			printprint("��-�� ��� ��� ������� ���������, � ����� ����� �������� ������������ \n", 15);
			king = true;
			text_festival();
			break;
		}
	}
	else
	{
		printprint("�� ������������� � �������� ��������� ������. ����������. \n", 15);
	
		exit(0);
	}
}
void microforest()
{
	printprint("�� ������ � ���������� ���, �� ��������� ��������� �� ������\n\n", 15);
	printprint("1) ������ ������\n", 15);
	printprint("2) ��������� �� ��� ������\n", 15);
	printprint("3) ���������� �� ���� ������� ����\n", 15);
	switch (choice(3))
	{
	case 1:
		choice_on_village = 1;
		system("cls");
		text_find_village();
		break;
	case 2:
		system("cls");
		text_Excalibur();
		break;
	case 3:
		//intelect -= 20;
		_player_.intelligence -= 20;
		system("cls");
		text_ant_anthill();
		break;
	default:
		printf("\ndefault. microforest()");
	}
}

void text_ant_anthill()
{
	printprint("�� ����� ������� �� ������� ��������� �� ����� ������� ���� \n �������� �� �� ���� ���� ������������� ��� ����� \n ������ ���������� �� �� �� ������, ��� �� ���� �������� ������� \n\n", 15);
	printprint("1) ��������� � ���\n", 15);
	printprint("2) �������\n", 15);
	switch (choice(2))
	{
	case 1:
		//intelect -= 10;
		_player_.intelligence -= 10;
		system("cls");
		fight_ant_anthill();
		break;
	case 2:
		system("cls");
		if (WasAcademy)
		{
			printprint("�� �������� ��������� ������, ��������� ��� ��������\n � ���� ��� ��� �� ����� � �� ������������ ������� ����������� ������\n ����� �� ������� ���� ������� ���� \n\n", 15);
			exit(0);
		}
		else
		{
			printprint("�� �������� ��������� ������, ��������� ��� ��������\n ��� ������ �� ������ ������������� � �������� ��� ���������\n �� ����� �������� �� ���� � ������ �� ������ �� ����������� \n\n", 15);
			text2_2();
		}
		break;
	}
}

void text_Excalibur()
{
	printprint("�� ������ ����������, ��� ����� �� �����,\n ����������� ����� �������� � ������, ��� ��������� ������� � ������� ����������� ������ �� ����� \n\n", 15);
	printprint("1) ������� ���� ��� ������\n", 15);
	printprint("2) ��������, ��� �� ������\n", 15);
	printprint("3) ������ �������� �\n", 15);
	switch (choice(3))
	{
	case 1:
		//evil += 5;
		_player_.kind_evil -= 5;
		excalibur = true;
		system("cls");
		text_Excalibur_vor();
		break;
	case 2:
		system("cls");
		text_Excalibur_diolog();
		break;
	case 3:
		socialreit += 5;
		system("cls");
		text_Excalibur_hero();
		break;
	}
}
void text_Excalibur_vor()
{
	printprint("������� ���� �����, �� ���������� ������, � ������� � ��� ���� �������  \n\n", 15);
	printprint("1) ������� ��� �� ������\n", 15);
	printprint("2) ����� � ��������� �� �����\n", 15);
	switch (choice(2))
	{
	case 1:
		//evil += 5;
		_player_.kind_evil -= 5;
		choice_on_village = 2;
		system("cls");
		text_Excalibur_vor_kill();
		break;
	case 2:
		socialreit -= 5;
		choice_on_village = 3;
		system("cls");
		text_Excalibur_vor_save();
		break;
	}
}
void text_Excalibur_vor_kill()
{
	printprint("�� ������ �� ����� � ����������� � ������. ����� �� �������� �������� \n\n", 15);
	printprint("1) ������ �� ��������, ���� ���������� ������� ����� \n", 15);
	switch (choice(1))
	{
	case 1:
		system("cls");
		text_find_village();
		break;
	}
}
void text_Excalibur_vor_save()
{
	printprint("�� ��������� ��� �� ����� � ������� �� ���� �����-�� ���� ������� �� ���������.\n� ��� � �� ����� �������� ������\n\n", 15);
	printprint("1) ������ �� ��������, ���� ���������� ������� ����� \n", 15);
	switch (choice(1))
	{
	case 1:
		system("cls");
		text_find_village();
		break;
	}
}
void text_Excalibur_diolog()
{
	printprint("�� ���������, ��� ��� ����������� ��� - ���������.\n ��� ����� �������� ������ ������� �������.\n\n", 15);
	printprint("1) �������� � ������� ���� ��� � ���������� ���-�� �� �������\n", 15);
	printprint("2) \"�����, ��� ��������� ����\"\n", 15);
	switch (choice(2))
	{
	case 1:
		excalibur = true;
		choice_on_village = 4;
		system("cls");
		text_find_village();
		break;
	case 2:
		choice_on_village = 5;
		text_find_village();
		break; 
	}
}
void text_Excalibur_hero()
{
	printprint("�� ����������� ������ � ������ � �������.\n�� ������ ��� ����� � ��� � �������, ����� ��� ������������� \n\n", 15);
	printprint("1) ����� � ���\n", 15);
	switch (choice(1))
	{
	case 1:
		system("cls");
		choice_on_village = 5;
		text_find_village();
		break;

	}
}
void text_find_village()
{
	printprint("�� ����������� � ��������� �������, ����� ������� ��� ��� �� ������. �� ����� ��� ����� ���", 15);
	switch (choice_on_village)
	{
	case 1:
		printprint("\n� ��� �������� ��� � ������� \"���������, �� ����� �� ������� �� ����� � �� ����� � ����� ���������\"\n ��� ���� �����: ������ ������� ��� ������ ����. \n", 15);
		printprint("1) ����\n", 15);
		printprint("2) ������ �������\n", 15);
		printprint("3) ���������� �������\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("��� �� ����������� � ���� ���� �� ��� ������� ��� ��� ���\n", 15);
			exit(0);
			_player_.kind_evil += 2;
			//text_jail();
			break;
		case 2:
			system("cls");
			printprint("\n��� ���� �������, ����������� �������, ������� �� ��� ������ ����� �������������  \n", 15);
			mission = true;
			text_ant_anthill();
			break;
		case 3:
			system("cls");
			printprint("\n  �� ������� ���������� �������, ��� �� ������� ��� �� �������� \n", 15);
			mission = true;
			destroy_village();
			break;
			
		}
	case 2:
		printprint("\n\"������ ��� ���� ������� ������� \".\n � ��� �������� ��� � ����������, �� ���������� �� �� �� ����-������ \n", 15);
		printprint("1) �������\n", 15);
		printprint("2) ������� ������\n", 15);
		switch (choice(2))
		{
		case 1:
			//evil += 20;
			_player_.kind_evil -= 20;
			system("cls");
			printprint("\n�� ��������, ��� ������ �� ������. �� ������ ������� �������� ������, ��� ����� ��� � �������\n������, �� ����� ���������, �� ��� ������, � ����� ����� ������� ������� ��� \n", 15);
			king = true;
			text_festival();
			break;
		case 2:
			//evil -= 2;
			_player_.kind_evil += 2;
			//intelect -= 10;
			_player_.intelligence -= 10;
			text_jail();
			break;
		}

	case 3:
		printprint("\n � ������ � ��� ��� ������. ��� �������� � ��� � �������\n\"�� ������ ���� �������� � ��������� ������������� ���������� ������� ������� \n �� ��������� ����� ��� ��� ������\"\n \n", 15);
		printprint("1) ����� � ����� \n", 15);
		printprint("2) ������� ���-������, ����� �����������\n", 15);
		switch (choice(2))
		{
		case 1:
			//evil -= 2;
			system("cls");
			_player_.kind_evil += 2;
			text_jail();
			break;
		case 2:
			printprint("\n��� ���� �������, ����������� �������, ������� �� ��� ������ ����� �������������  \n", 15);
			mission = true;
			text_ant_anthill();
			break;
			
			
		}
		break;
	case 4:
		namefalse = true;
		printprint(",�� ������� � � ��� � �������\"��� ��� �����?\"\n(�� ������ �������� ���� ���, ������ ��� �������� ��� ���. ������� �� ���������<3)  \n", 15);
		char f[40];
		scanf_s("%s", f, 40);
		system("cls");
		printprint("\n������, �� ����� ���������, �� ��� ������, � ����� ����� ������� ������� ��� \n", 15);
		king = true;
		text_festival();
		break;
	case 5:
		printprint("\n������ ��������� � ���� � ������ ���-�� ���, ��� �������������� � ��� � �������\n ��������� ���� �� ����� ������, � ����� ����� ������� ������� ��� \n", 15);
		text_festival();
		break;
	}
}
void text_festival()
{
	printprint("\n���������� ������������ �� ������ ������\n", 15);
	if (choice_on_village == 5)
		printprint("\n��� �������� �������� �������� �������� �� ������\n", 15);
	else
		printprint("\n��� �������� ����� ������� ������� �� ����� �������� � �������\n", 15);
	printprint("\n� ��� �������� ���� � �������, ��� �� ������ ����� � ������ ������� ������\n\n", 15);
	printprint("1) ���������� �������  � ������ ������� ������\n", 15);
	printprint("2) ���������� �������  � ��������-������\n", 15);
	switch (choice(2))
	{
	case 1:
		//intelect -= 3;
		_player_.intelligence -= 3;
		system("cls");
		printprint("�� �� ��������, ����  ������ ������� ������, �� ������ ������, ������� �� ����������� \n", 15);
		system("pause");
		gamescissors();
		break;
	case 2:
		//evil += 1;
		_player_.kind_evil -= 1;
		system("cls");
		printprint("�� ������� ���, ��� ������� � ����� ������� ����� ������ � ����� ����, �������\n �� � ������ ������������� ������� � ��������� \n", 15);
		system("pause");
		if (krestiki() == 1) //?
		{
			printprint("\n����� �� �������, �������� �����, ������� ����� � ������ ���. �� ������� �������!\n �� ����� ������� +1 ����� \n", 15);
			_player_.strength += 1;
		}
		else {
			printprint("\n�� ������ ��������� �����, ������� ����� ��� ���� �������. �� ������� �������! \n �� ����� ������� +3 ����� \n", 15);
			//evil -= 3;
			_player_.strength += 3;
			_player_.kind_evil += 3;
		}
		break;
	}

	if (king == true)
	{
		int reighnResuly = Reighn();
		if(reighnResuly==-2)
			printprint("�� ���� ������ ������, ����� � ��� ������������� � �����\n", 15);
		if (reighnResuly == -1)
			printprint("�� ������� ������ ���������� ������(������ ���������)\n ���� ��� �� ���� ��� � ��� ������", 15);
		printprint("\n1)������\n", 15);
		printprint("2)������\n", 15);
		printprint("\n�����\n", 5);
		if (reighnResuly == 1)
			printprint("�� ���� �������� ������� ��� ������� ����������, �� �� ������ � ������ ��-�� ��������� ������\n", 15);
		if(choice_on_village == 4)
			printprint("\n(������ �� ������ ����������� ��� ������� � ��� ����� �� ����� �������)\n", 15);
	}
	else
	{
		printprint("\n� ��� �������� ���������� � ������ �� 1 ������: ���������� �������� �������� ���������� �� ���������\n", 15);
		printprint("1) � ������� ����� � �� ���� ��������\n", 15);
		printprint("2) � ���������� ����� � �� ���� ��������\n", 15);
		printprint("3) � ������������� ����� � �� ���� ��������\n", 15);
		choice(3);
		system("cls");
		printprint("����� ������� ���������� ������� ��� �������� ��� ������ ����� ������� ����\n", 15);
		system("pause");
		enchantment(_player_);
		printf("\n");
		printstat(_player_, strength);
		printf("\n");
		Player rat;
		rat.max_health = 250;
		rat.health = 250;
		rat.defense = 20;
		rat.strength = 30;
		strcpy_s(rat.p_class, "�����");
		printprint("�� ������ � ������ ����� ����� ��� ���� ��������� �����\n", 15);
		system("pause");
		fight(rat);
		printprint("������� �� ������� ����� ����� ����, � ������ ����� ��������� �������\n", 15);
	}
	exit(0);
	//-2: ��� ����� �������� �� ��������� ����� -1: ����� �������� 1: �� ������������ 15 ����. 
}
void text_jail()
{
	system("cls");
	printprint("�� ������������ � ������, �� ������ �������, ���� � ������� �� ���� ����� �������� �����\n", 15);
	printprint("1) ���������� ������ � ������\n", 15);
	printprint("2) �������� ��������\n", 15);
	printprint("3) ���� �����\n\n", 15);
	switch (choice(3))
	{
	case 1:
		system("cls");
		printprint("�� ����������� ������ � ������ ��� ��������� ����. �� ������ ����\n", 15);
		printprint("1) ���������� ������ � ������\n", 15);
		printprint("2) �������� ��������\n", 15);
		printprint("3) ���� �����\n\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("�� ������ � ������ �������� �����. �� �������� � ������\n", 15);
			printprint("1) ���������� ������ � ������\n", 15);
			printprint("2) �������� ��������\n", 15);
			printprint("3) ���� �����\n\n", 15);
			switch (choice(3)) //����������������������� �������� ���
			{
			case 1:
				system("cls");
				printprint("�� ������ � ������\n", 15);
				exit(0);
				break;
			case 2:
				system("cls");
				printprint("\n��� ���� �������, ����������� �������, ������� �� ��� ������ ����� �������������  \n", 15);
				mission = true;
				text_ant_anthill();

				break;
			case 3:
				end_microforest();
				break;
			}
		case 2:
			system("cls");
			printprint("\n��� ���� �������, ����������� �������, ������� �� ��� ������ ����� �������������  \n", 15);
			mission = true;
			text_ant_anthill();
			break;
		case 3:
			end_microforest();
			break;
		}

	case 2:
		system("cls");
		printprint("\n��� ���� �������, ����������� �������, ������� �� ��� ������ ����� �������������  \n", 15);
		mission = true;
		text_ant_anthill();
		break;
	case 3:
		end_microforest();
		break;
		//case 3 ������� ����� �� ��� � ����� ���� ������ ��� ������ �� ������ 
	}
	// � �� ���� ���� ��� �������� �������� ������ ��� ����� ���� ����
		/*case 2:
			system("cls");
			printprint("\n��� ���� �������, ����������� �������, ������� �� ��� ������ ����� �������������  \n", 15);
			mission = true;
			text_ant_anthill();
			break;
		case 3:
			end_microforest();
		break;*/
}
void destroy_village()
{
	destroy = true;
	_player_.kind_evil -= 100;
	printprint("\n�� ������ ��������� ���� � ������������ ���� ���������� ���������� � ������������ ������ ������\n�� ������������, ����� ������� �����������, �� ��������� ������� � ������ ������� ������\n ���� �������� �� �� �� �������� �������, ����� ��� ������� �����������\n", 15);
	printprint("1) ������� � ������ ������� ������\n", 15);
	printprint("2) ����� ���\n", 15);
	switch (choice(2))
	{
	case 1:
	
		system("cls");
		gamescissors();
		system("cls");
		printprint("�� ������������ � �������� �����������\n", 15);
		printprint("1) �������, ��� �� ��������������\n", 15);
		printprint("2) ������ � �������� � ����� ���\n", 15);
		switch (choice(2))
		{
		case 1:
		
			end_microforest();
		case 2:
			pinok();
			break;
		}
		break;
	case 2:
		pinok();
		break;
	}
}
void pinok()
{
	system("cls");
	printprint("�� ������� ���, ��� ���������� �����, �� ������� �� ��������\n", 15);
	printprint("������ ����� �� ����� ��� ����������, ��������� ��������� ������� �� �� �������� ������ ������� \n", 15);
	end_microforest();
	//break;
}
void end_microforest()
{
	if(destroy)
		printprint("�� ��� ������������� �����, �� �����������, ��� �� ���������� ���� ����������, �� ������� ��� ��������\n", 15);
	else
		printprint("�� ������������� �����, c ������� ������\n", 15);
}
/*
1 ������� ��������
2 ���� �� ������
3 ������� � �����
4 ��������� ����
5 �� 4 ����� � ���

*/