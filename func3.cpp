#include <iostream>
#include <windows.h>
#include "func2.h"
// Размер массивов символов в характеристиках игрока (название класса, название стамины, название оружия)
const int SIZEOF_NAME = 50;
const int SIZEOF_KINDEVIL = 6;
bool enchant = 0;


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
	char p_class[SIZEOF_NAME], p_class_stamina[SIZEOF_NAME], p_weapon[SIZEOF_NAME];
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
	char s[SIZEOF_NAME];
};

// Вывод текущих характеристик игрока в консоль
void printstats(Player name)
{
	char kind_or_evil[SIZEOF_KINDEVIL];
	if (name.kind_evil < 0)
		strcpy_s(kind_or_evil, "Зло");
	else strcpy_s(kind_or_evil, "Добро");
	name.kind_evil = abs(name.kind_evil);

	printf("\n%s\nЗдоровье: %.0f/%.0f\nСила: %d\nЗащита: %d\n%s: %d/%d\nIQ: %d\nУдача: %d\nДеньги: %d\n%s: %d\nХаризма: %d\nОружие: %s\n",
		name.p_class, name.health, name.max_health, name.strength, name.defense, name.p_class_stamina, name.stamina, name.max_stamina, name.intelligence,
		name.luck, name.money, kind_or_evil, name.kind_evil, name.charisma, name.p_weapon);

}

void printstat(Player name, stats n)
{
	switch (n)
	{
	case health:
		printf("Текущее здоровье: %.0f/%.0f", name.health, name.max_health);
		break;

	case max_health:
		printf("Максимальное здоровье: %.0f", name.max_health);
		break;

	case strength:
		printf("Сила: %d", name.strength);
		break;

	case defense:
		printf("Защита: %d", name.defense);
		break;

	case p_class_stamina:
		printf("Вы используете %s для достижения своих целей.", name.p_class_stamina);
		break;

	case stamina:
		printf("%s: %d/%d", name.p_class_stamina, name.stamina, name.max_stamina);
		break;

	case max_stamina:
		printf("Макс. %s: %d", name.p_class_stamina, name.max_stamina);
		break;

	case intelligence:
		printf("IQ: %d", name.intelligence);
		break;

	case luck:
		printf("Удача: %d", name.luck);
		break;

	case money:
		printf("Деньги: %d", name.money);
		break;

	case kind_evil:
		char kind_or_evil[SIZEOF_KINDEVIL];
		if (name.kind_evil < 0)
			strcpy_s(kind_or_evil, "Зло");
		else strcpy_s(kind_or_evil, "Добро");
		name.kind_evil = abs(name.kind_evil);
		printf("%s: %d", kind_or_evil, name.kind_evil);
		break;

	case charisma:
		printf("Харизма: %d", name.charisma);
		break;

	case p_weapon:
		printf("Оружие: %s", name.p_weapon);
		break;

	case p_class:
		printf("Вы %s, этим всё сказано.", name.p_class);
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

// ВАЖНО: в начале main единожды прописать srand(time(0)) при подключённой библиотеке time.h.
// принимает переменную типа Player, возвращает бонусный урон, тот же, что выводит в конце
int enchantment(Player& name) //_________________________________________________________________________________________________________rework
{
	system("cls");
	printprint("\nВы решили заточить ", 15);
	printf("%s\n", name.p_weapon);
	printprint("Вы знаете как должно выглядеть заточеное оружие, но как его заточить?\n", 15);
	printprint("Вам известна середина между двумя точками для ударов молотом (молот шершавый поэтому заточка). \nВаша задача найти эти точки.\n", 15);
	printprint("Так нужно сделать 6 раз.\n", 15);
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
		printf("Пара ударов %d\nЦентр: %.1f\n", i, center);
		// printprint("А в другое ухо кричит: T\bt\bTR\br\bRY\by\bY I\bi\bIS\bs\bS ", 7); printf("%d%d\n", a, b); // читы
		printprint("Введите две точки (от 0 до 9), в которые вы ударите:\n", 15);
		scanf_s("%d%d", &player_a, &player_b);
		
		if ((player_a == a and player_b == b) or (player_a == b and player_b == a))
		{
			printprint("Успех!", 15);
			success++;
		}
		else
			printprint("Неудача...", 15);
		Sleep(2000);

	}
	system("cls");
	switch (success)
	{
	case 0:
		printprint("Вы старались...", 10);
		break;
	case 1:
	case 2:
		printf("Качество: Удовлетворительно. Вы слегка заточили %s.\n(Сила: + %d)\n", name.p_weapon, success);
		name.strength += success;
		break;
	case 3:
	case 4:
	case 5:
		printf("Качество: Хорошо. %s теперь значительно острей!\n(Сила: + %d, +10 к \"%s\", +1 к удаче))\n", name.p_weapon, success, name.p_class_stamina);
		name.strength += success;
		name.max_stamina += 10;
		name.luck += 1;
		break;
	case 6:
		printf("Качество: Идеально! %s теперь может резать даже камень!\n(+%d к силе, + 20 к \"%s\", +2 к удаче)\n", name.p_weapon, success, name.p_class_stamina);
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