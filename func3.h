#pragma once
#ifndef FUNC2_3_H
#define FUNC2_3_H

/*
Структура с характеристиками игрока(1f.health, 2f.max_health, 3i.strength, 4i.defense, 5i.stamina, 6i.max_stamina,
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

/* enum для player(): health = 1, p_weapon = 15
в соответствии со структурными переменными Player
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

// Вывод текущих характеристик игрока в консоль
void printstats(Player name);

// Вывод выбранной вторым аргументом характеристики игрока в консоль
void printstat(Player name, stats n);

// Первый аргумент куда сохранить характеристики, второй - откуда.
void fill_player(Player& name, Player clas);

/*
player(Player ,stats, skillpoints)
player(имя структуры Player, название характеристики, см. по пунктам далее);
1f.health: добавляет к health point и проверяет не превысело ли max_hp
2f.max_health: добавляет к max_health
3i.strength: добавляет к strength
4i.defense: добавляет к defense
5i.stamina: добавляет к stamina
6i.max_stamina: добавляет к max_stamina и проверяет не превысело ли max_stamina
7i.intelligence: добавляет к intelligence
8i.luck: добавляет к luck
9i.money: добавляет к money
10i.kind_evil: добавляет к kind_evil
11i.charisma: добавляет к charisma
12s.p_class: заменяет содержимое p_class на point
13s.p_class_stamina: заменяет содержимое p_class_stamina на point
14s.p_weapon: заменяет содержимое p_weapon на point
*/
void player(Player& name, stats stat, skillpoints point);

// ВАЖНО: в начале main единожды прописать srand(time(0)) при подключённой библиотеке time.h
int enchantment(Player& name);

#endif