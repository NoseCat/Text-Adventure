#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "func2.h"
#include "func3.h"
#include "NecroGame.h"
#include "fight.h"
#include "text2_1.h"
#include "text2_2.h"
#include "text2_3.h"

const int NAME_SIZE = 50;
#pragma region CLASSES
Player Necromancer;
Player Berserk;
Player Mage;
Player Clown;
Player Palladin;
Player Thief;

void Classes()
{
	Necromancer.max_health = 80;
	Necromancer.health = 80;
	Necromancer.strength = 15;
	Necromancer.defense = 5;
	strcpy(Necromancer.p_class_stamina, "����");
	Necromancer.max_stamina = 100;
	Necromancer.stamina = 100;
	Necromancer.intelligence = 100;
	Necromancer.luck = 0;
	Necromancer.money = 0;
	Necromancer.kind_evil = -10;
	Necromancer.charisma = -15;
	strcpy(Necromancer.p_class, "���������");
	strcpy(Necromancer.p_weapon, "������������");

	Berserk.max_health = 80;
	Berserk.health = 80;
	Berserk.strength = 40;
	Berserk.defense = 15;
	strcpy(Berserk.p_class_stamina, "������");
	Berserk.max_stamina = 100;
	Berserk.stamina = 100;
	Berserk.intelligence = 80;
	Berserk.luck = 5;
	Berserk.money = 0;
	Berserk.kind_evil = 0;
	Berserk.charisma = -50;
	strcpy(Berserk.p_class, "�������");
	strcpy(Berserk.p_weapon, "JavaScript ��� ����������: ����� 1");

	Mage.max_health = 50;
	Mage.health = 50;
	Mage.strength = 5;
	Mage.defense = 0;
	strcpy(Mage.p_class_stamina, "����");
	Mage.max_stamina = 120;
	Mage.stamina = 120;
	Mage.intelligence = 102;
	Mage.luck = 0;
	Mage.money = 5;
	Mage.kind_evil = 0;
	Mage.charisma = 3;
	strcpy(Mage.p_class, "���");
	strcpy(Mage.p_weapon, "����������� �� Dungeons & Dragons");

	Clown.max_health = 80;
	Clown.health = 80;
	Clown.strength = 10;
	Clown.defense = 15;
	strcpy(Clown.p_class_stamina, "����");
	Clown.max_stamina = 100;
	Clown.stamina = 100;
	Clown.intelligence = 180;
	Clown.luck = 15;
	Clown.money = 10;
	Clown.kind_evil = 0;
	Clown.charisma = 10;
	strcpy(Clown.p_class, "�����");
	strcpy(Clown.p_weapon, "������� ���������");

	Palladin.max_health = 150;
	Palladin.health = 150;
	Palladin.strength = 20;
	Palladin.defense = 30;
	strcpy(Palladin.p_class_stamina, "����");
	Palladin.max_stamina = 100;
	Palladin.stamina = 100;
	Palladin.intelligence = 80;
	Palladin.luck = 0;
	Palladin.money = 0;
	Palladin.kind_evil = 10;
	Palladin.charisma = 5;
	strcpy(Palladin.p_class, "��������");
	strcpy(Palladin.p_weapon, "����� �����");

	Thief.max_health = 80;
	Thief.health = 80;
	Thief.strength = 10;
	Thief.defense = 15;
	strcpy(Thief.p_class_stamina, "��������� �������");
	Thief.max_stamina = 100;
	Thief.stamina = 100;
	Thief.intelligence = 100;
	Thief.luck = 20;
	Thief.money = 10;
	Thief.kind_evil = -5;
	Thief.charisma = 0;
	strcpy(Thief.p_class, "���");
	strcpy(Thief.p_weapon, "����� ������ ��� ��������");
}
#pragma endregion

void ChooseClass();
void Begining();
void ClassChoice(Player clas);
void Begining();
void forest();
void Necromancy();
bool NecromantMustLearn = false;
void Circus();

Player _player_;

void NameEnter()
{
	Classes();

	printprint("�� ��������� ���� �����������...\n��� ��� ����� ��������?\n", 15);
	char name[NAME_SIZE];
	scanf_s("%s", &name, NAME_SIZE);

	printprint("���� ��� ��������.", 20);
	printf("..\n");
	Sleep(1000);
	ChooseClass();
}

void ClassChoice(Player clas)
{
	system("cls");
	printprint("�� ������� ��� ������ ������� ���� �����?\n1) ��\n2) ���\n\n", 15);
	printstats(clas);
	switch (choice(2))
	{
	case 1:
		fill_player(_player_, clas);
		system("cls");
		Begining();
		break;
	case 2:
		NecromantMustLearn = false;
		ChooseClass();
		break;
	}

}

void ChooseClass()
{
	system("cls");
	printprint("�������� ����� ���������: \n", 15);
	printprint("1) �������\n2) ��������\n3) ���������\n4) ���\n5) �����\n6) ���\n7) ������\n8) ���������\n", 15);
	printprint("9) �������\n10) ������������\n11) �����������\n12) ��������\n13) ���-���������\n14) �����\n", 15);
	printprint("15) ��� ������� (��������� ��������������)\n", 15);
	switch (choice(15))
	{
	case 1:
		ClassChoice(Berserk);
		break;
	case 2:
		ClassChoice(Palladin);
		break;
	case 3:
		NecromantMustLearn = true;
		ClassChoice(Necromancer);
		break;
	case 4:
		ClassChoice(Thief);
		break;
	case 5:
		ClassChoice(Clown);
		break;
	case 6:
		ClassChoice(Mage);
		break;
	case 7:
		strcpy(Mage.p_class, "������");
		ClassChoice(Mage);
		break;
	case 8:
		strcpy(Mage.p_class, "���������");
		ClassChoice(Mage);
		break;
	case 9:
		strcpy(Mage.p_class, "�������");
		ClassChoice(Mage);
		break;
	case 10:
		strcpy(Mage.p_class, "������������");
		ClassChoice(Mage);
		break;
	case 11:
		strcpy(Mage.p_class, "�����������");
		ClassChoice(Mage);
		break;
	case 12:
		strcpy(Mage.p_class, "��������");
		ClassChoice(Mage);
		break;
	case 13:
		strcpy(Mage.p_class, "���-���������");
		ClassChoice(Mage);
		break;
	case 14:
		strcpy(Mage.p_class, "�����");
		ClassChoice(Mage);
		break;
	case 15:
		system("cls");
		printprint("���������� ��������������.....\n", 10);
		printprint("��������: 0/0\n", 15);
		Sleep(1000);
		death();
		break;
	}
	
}

void Begining()
{
	//Player enemy;
	//fill_player(enemy, Necromancer);
	//fight(enemy);
	//printstats(_player_);
	printprint("��� ������ ����� �����������. ����� ������:\n\n1) ����� � ���\n2) ��������� �� ����������.\n3) ����� � ����.\n", 15);
	switch (choice(3))
	{
	case 1:
		if (NecromantMustLearn)
		{
			system("cls");
			printprint("�� ���������, �� ������ ������������, � �� �� ����� �������!\n", 10);
			Begining();
		}
		else
			forest();
		break;
	case 2:
		Necromancy();
		break;
	case 3:
		if (NecromantMustLearn)
		{
			system("cls");
			printprint("�� ��� �����? ������ ����������, ��� � ��� �� ����������!\n", 10);
			Begining();
		}
		else;
			Circus();
		break;
	}
}

void forest()
{
	printprint("� ������� �������� � ����������� �� ������� ����� � ���...\n\n", 15);
	system("cls");
	microforest();
}

void Necromancy()
{
	system("cls");
	printprint("�� �������, ��� ����� ����� ������ ��� ����� ������� �������� ����������.\n��� �������� ����������� ����������� �� ����� ������ ������ ����� �����������!\n\n1) ����������\n", 15);
	if (choice(1) == 1)
	{
		system("cls");
		text2_2();
	}
}

void Circus()
{
	opening_of_the_circus_2_3_0();
}
