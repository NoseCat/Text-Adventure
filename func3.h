#pragma once
#ifndef FUNC2_3_H
#define FUNC2_3_H

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
	char p_class[50], p_class_stamina[50], p_weapon[50];
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
	char s[50];
};

// ����� ������� ������������� ������ � �������
void printstats(Player name);

// ����� ��������� ������ ���������� �������������� ������ � �������
void printstat(Player name, stats n);

// ������ �������� ���� ��������� ��������������, ������ - ������.
void fill_player(Player& name, Player clas);

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
void player(Player& name, stats stat, skillpoints point);

// �����: � ������ main �������� ��������� srand(time(0)) ��� ������������ ���������� time.h
int enchantment(Player& name);

#endif