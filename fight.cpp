#include <iostream>
#include <Windows.h>
#include "func2.h"
#include "func3.h"
#include "Opening.h"

extern Player _player_;

void FightStateOutput(int enemy_chardg, Player _player_, Player enemy)
{
	system("cls");
	printf("ты:                                 %s:\n", enemy.p_class);
	printstat(_player_, health);
	printf("             ");
	printstat(enemy, health);
	printf("\n");

	printstat(_player_, strength);
	printf("                            ");
	printstat(enemy, strength);
	printf("\n");

	printstat(_player_, defense);
	printf("                          ");
	printstat(enemy, defense);
	printf("\n");

	printstat(_player_, stamina);
	printf("\n                                    Действие: ");
	switch (enemy_chardg)
	{
	case 0:
	case 1:
		printf("Заряжает атаку...");
		break;
	case 2:
		printf("Почти зарядил...");
		break;
	case 3:
		printf("Атакует!");
		break;
	}
	printf("\n\n1) атаковать \n2) защищаться \n3) пропустить ход (%s востановиться быстрее)\n", _player_.p_class_stamina);

}

void fight(Player enemy)
{
	int enemy_chardg = 0;
	bool endfight = false;
	int block = 0;

	do
	{
		enemy_chardg++;

		FightStateOutput(enemy_chardg, _player_, enemy);
		switch(choice(3))
		{
		case 1:
			block = 0;
			_player_.stamina -= _player_.strength / 2;
			if (_player_.stamina < _player_.strength / 2)
			{
				printf("Вам не хватает %s чтобы ударить (нужно: % d).\n",_player_.p_class_stamina, _player_.strength / 2);
				Sleep(1000);
			}
			else
			{
				if (_player_.strength > enemy.defense)
				{
					enemy.health -= _player_.strength;
					printf("Вы нанесли %d урона использовав %s.\n", _player_.strength, _player_.p_weapon);
					Sleep(1000);
				}
				else
				{
					enemy.defense -= 1;
					printf("Защита не пробита.\n");
					Sleep(1000);
				}

				if (enemy.health <= 0)
					endfight = true;
			}
			break;
		case 2: 
			printf("Вы защитились.\n");
			Sleep(1000);
			block = _player_.defense; 
			if (_player_.stamina + _player_.max_stamina / 4 > _player_.max_stamina)
				_player_.stamina = _player_.max_stamina;
			else
				_player_.stamina += _player_.max_stamina / 4;
			break;
		case 3:
			block = 0;
			printf("Вы отдыхаете...\n");
			Sleep(1000);
			if (_player_.stamina + _player_.max_stamina / 2 > _player_.max_stamina)
				_player_.stamina = _player_.max_stamina;
			else
				_player_.stamina += _player_.max_stamina / 2;
			break;
		};

		if (enemy_chardg >= 3)
		{
			enemy_chardg = 0;
			if (enemy.strength <= block)
			{
				printf("Блокировано.\n");
				Sleep(1000);
			}
			else
			{
				_player_.health -= (enemy.strength - block);
				printf("Вам нанесено %d урона.\n", (enemy.strength - block));
				Sleep(1000);
			}
		}
		if (_player_.health <= 0)
		{
			death();
		}
	} while(!endfight);

	_player_.stamina = _player_.max_stamina;
	printf("Победа!\n");
	system("pause");
	system("cls");
}

