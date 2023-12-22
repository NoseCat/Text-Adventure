#include <iostream>
#include <windows.h>
#include "func2.h"
// ������ �������� �������� � ��������������� ������ (�������� ������, �������� �������, �������� ������)
const int SIZEOF_NAME = 50;
const int SIZEOF_KINDEVIL = 6;
bool enchant = 0;


/*
��������� � ���������������� ������(1f.health, 2f.max_health, 3i.strength, 4i.defense, 5i.stamina, 6i.max_stamina,
7i.intelligence, 8i.luck 9i.money, 10i.kind_evil, 11i.charisma,
12s.p_class, 13s.p_class_stamina, 14s.p_weapon)
i - int, f - float, s - char[SIZEOF_NAME]
*/
struct Player
{
	float health, max_health;
	int strength, defense, stamina, max_stamina, intelligence, luck, money, kind_evil, charisma;
	char p_class[SIZEOF_NAME], p_class_stamina[SIZEOF_NAME], p_weapon[SIZEOF_NAME];
};

/* enum ��� player(): health = 1, p_weapon = 15
� ������������ �� ������������ ����������� Player
*/
enum stats
{
	health = 1, max_health, strength, defense, stamina,
	max_stamina, intelligence, luck, money, kind_evil, charisma,
	p_class, p_class_stamina, p_weapon
};

// .i - int, .f - float, .s - char[SIZEOF_NAME]
union skillpoints
{
	int i;
	float f;
	char s[SIZEOF_NAME];
};

// ����� ������� ������������� ������ � �������
void printstats(Player name)
{
	char kind_or_evil[SIZEOF_KINDEVIL];
	if (name.kind_evil < 0)
		strcpy_s(kind_or_evil, "���");
	else strcpy_s(kind_or_evil, "�����");
	name.kind_evil = abs(name.kind_evil);

	printf("\n%s\n��������: %.0f/%.0f\n����: %d\n������: %d\n%s: %d/%d\nIQ: %d\n�����: %d\n������: %d\n%s: %d\n�������: %d\n������: %s\n",
		name.p_class, name.health, name.max_health, name.strength, name.defense, name.p_class_stamina, name.stamina, name.max_stamina, name.intelligence,
		name.luck, name.money, kind_or_evil, name.kind_evil, name.charisma, name.p_weapon);

}

void printstat(Player name, stats n)
{
	switch (n)
	{
	case health:
		printf("������� ��������: %.0f/%.0f", name.health, name.max_health);
		break;

	case max_health:
		printf("������������ ��������: %.0f", name.max_health);
		break;

	case strength:
		printf("����: %d", name.strength);
		break;

	case defense:
		printf("������: %d", name.defense);
		break;

	case p_class_stamina:
		printf("�� ����������� %s ��� ���������� ����� �����.", name.p_class_stamina);
		break;

	case stamina:
		printf("%s: %d/%d", name.p_class_stamina, name.stamina, name.max_stamina);
		break;

	case max_stamina:
		printf("����. %s: %d", name.p_class_stamina, name.max_stamina);
		break;

	case intelligence:
		printf("IQ: %d", name.intelligence);
		break;

	case luck:
		printf("�����: %d", name.luck);
		break;

	case money:
		printf("������: %d", name.money);
		break;

	case kind_evil:
		char kind_or_evil[SIZEOF_KINDEVIL];
		if (name.kind_evil < 0)
			strcpy_s(kind_or_evil, "���");
		else strcpy_s(kind_or_evil, "�����");
		name.kind_evil = abs(name.kind_evil);
		printf("%s: %d", kind_or_evil, name.kind_evil);
		break;

	case charisma:
		printf("�������: %d", name.charisma);
		break;

	case p_weapon:
		printf("������: %s", name.p_weapon);
		break;

	case p_class:
		printf("�� %s, ���� �� �������.", name.p_class);
		break;

	default:
		printf("\nerror: prinstat()\n");
		break;
	}
}

void fill_player(Player& name, Player clas)
{
	name.health = clas.health;
	name.max_health = clas.max_health;
	name.strength = clas.strength;
	name.defense = clas.defense;
	name.stamina = clas.stamina;
	name.max_stamina = clas.max_stamina;
	name.intelligence = clas.intelligence;
	name.luck = clas.luck;
	name.money = clas.money;
	name.kind_evil = clas.kind_evil;
	name.charisma = clas.charisma;
	strcpy_s(name.p_class, clas.p_class);
	strcpy_s(name.p_class_stamina, clas.p_class_stamina);
	strcpy_s(name.p_weapon, clas.p_weapon);
}

/*
player(Player ,stats, skillpoints)
player(��� ��������� Player, �������� ��������������, ��. �� ������� �����);
1f.health: ��������� � health point � ��������� �� ��������� �� max_hp
2f.max_health: ��������� � max_health
3i.strength: ��������� � strength
4i.defense: ��������� � defense
5i.stamina: ��������� � stamina
6i.max_stamina: ��������� � max_stamina � ��������� �� ��������� �� max_stamina
7i.intelligence: ��������� � intelligence
8i.luck: ��������� � luck
9i.money: ��������� � money
10i.kind_evil: ��������� � kind_evil
11i.charisma: ��������� � charisma
12s.p_class: �������� ���������� p_class �� point
13s.p_class_stamina: �������� ���������� p_class_stamina �� point
14s.p_weapon: �������� ���������� p_weapon �� point
*/
void player(Player& name, stats stat, skillpoints point)
{
	switch (stat)
	{
	case health:
		name.health = name.health + point.f;
		if (name.health > name.max_health)
			name.health = name.max_health;
		break;
	case max_health:
		name.max_health = name.max_health + point.f;
		break;
	case strength:
		name.strength = name.strength + point.i;
		break;
	case defense:
		name.defense = name.defense + point.i;
		break;
	case stamina:
		name.stamina = name.stamina + point.i;
		if (name.stamina > name.max_stamina)
			name.stamina = name.stamina;
		break;
	case max_stamina:
		name.max_stamina = name.max_stamina + point.i;
		break;
	case intelligence:
		name.intelligence = name.intelligence + point.i;
		break;
	case luck:
		name.luck = name.luck + point.i;
		break;
	case money:
		name.money = name.money + point.i;
		break;
	case kind_evil:
		name.kind_evil = name.kind_evil + point.i;
		break;
	case charisma:
		name.charisma = name.charisma + point.i;
		break;
	case p_class:
		strcpy_s(name.p_class, point.s);
		break;
	case p_class_stamina:
		strcpy_s(name.p_class_stamina, point.s);
		break;
	case p_weapon:
		strcpy_s(name.p_weapon, point.s);
		break;
	default: printf("\nerror: player()\n");
		break;
	}
}

// �����: � ������ main �������� ��������� srand(time(0)) ��� ������������ ���������� time.h.
// ��������� ���������� ���� Player, ���������� �������� ����, ��� ��, ��� ������� � �����
int enchantment(Player& name) //_________________________________________________________________________________________________________rework
{
	system("cls");
	printprint("\n�� ������ �������� ", 15);
	printf("%s\n", name.p_weapon);
	printprint("�� ������ ��� ������ ��������� ��������� ������, �� ��� ��� ��������?\n", 15);
	printprint("��� �������� �������� ����� ����� ������� ��� ������ ������� (����� �������� ������� �������). \n���� ������ ����� ��� �����.\n", 15);
	printprint("��� ����� ������� 6 ���.\n", 15);
	system("pause");
	int a, player_a, b, player_b, success = 0;
	float center;
	for (int i = 1; i <= 6; i++)
	{
		do {
			a = rand() % (9 - 0 + 1) + 0;
			b = rand() % (9 - 0 + 1) + 0;
		} while (b == a);

		center = (a + b) / 2.0f;

		system("cls");
		printf("���� ������ %d\n�����: %.1f\n", i, center);
		// printprint("� � ������ ��� ������: T\bt\bTR\br\bRY\by\bY I\bi\bIS\bs\bS ", 7); printf("%d%d\n", a, b); // ����
		printprint("������� ��� ����� (�� 0 �� 9), � ������� �� �������:\n", 15);
		scanf_s("%d%d", &player_a, &player_b);
		
		if ((player_a == a and player_b == b) or (player_a == b and player_b == a))
		{
			printprint("�����!", 15);
			success++;
		}
		else
			printprint("�������...", 15);
		Sleep(2000);

	}
	system("cls");
	switch (success)
	{
	case 0:
		printprint("�� ���������...", 10);
		break;
	case 1:
	case 2:
		printf("��������: �����������������. �� ������ �������� %s.\n(����: + %d)\n", name.p_weapon, success);
		name.strength += success;
		break;
	case 3:
	case 4:
	case 5:
		printf("��������: ������. %s ������ ����������� ������!\n(����: + %d, +10 � \"%s\", +1 � �����))\n", name.p_weapon, success, name.p_class_stamina);
		name.strength += success;
		name.max_stamina += 10;
		name.luck += 1;
		break;
	case 6:
		printf("��������: ��������! %s ������ ����� ������ ���� ������!\n(+%d � ����, + 20 � \"%s\", +2 � �����)\n", name.p_weapon, success, name.p_class_stamina);
		name.strength += success;
		name.max_stamina += 20;
		name.luck += 2;
		break;
	default:
		printprint("\nerror: enchantment()\n", 10);
		break;
		system("pause");
	}
	return success;
}