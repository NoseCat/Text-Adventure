#include <iostream>
#include "func2.h"

void randEvent()
{
	switch (rand() % 20)
	{
	case 0: printprint("\"Мой король народ голодает!\"", 15); break;
	case 1: printprint("\"Мой король народ в нищете!\"", 15); break;
	case 2: printprint("Ваш министр финансов прдлагает увеличить налог на хлеб.", 15); break;
	case 3: printprint("Ваш министр финансов прдлагает уменьшить налог на хлеб.", 15); break;
	case 4: printprint("Приехал посол из соседнего леса. Они хотят войны.", 15); break;
	case 5: printprint("Приехал посол из соседнего леса. Они преподносят дары.", 15); break;
	case 6: printprint("Миниcтр внутренних дел обнаружил что против вас готовиться заговор.\nЧто сделать с заговоршиками?", 15); break;
	case 7: printprint("На фабрике в столице бунт! Они требуют хлеба. Что сделать с бунтовшиками?", 15);  break;
	case 8: printprint("К вам прибежал запыхавшийся министр обороны. Он в панике пытается что-то обьяснить.\nВы не поняли ни слова.", 15);  break;
	case 9: printprint("Кто-то нарисовал с вами политическую карикатуру.", 15);  break;
	case 10: printprint("На фабрике взрывоопасных штук произошел взрыв!", 15);  break;
	case 11: printprint("В стране острая нехватка перца чили!", 15);  break;
	case 12: printprint("Ничего не случилось.", 15); break;
	case 13: printprint("Умер известный поэт. Народ в трауре.", 15); break;
	case 14: printprint("Обнаружилось, что кто-то сломал муравейник.", 15); break;
	case 15: printprint("Вы бросили 20-и гранник. Вам выпало 21.", 15); break;
	case 16: printprint("Вам пришло письмо от министра финансов. \nПохоже соседнее государство ввело санкции на что-то но никто не знает на что.", 15); break;
	case 17: printprint("Сегодня национальный празник.", 15); break;
	case 18: printprint("В столице вспыхнула эпидемия чумы.", 15); break;
	case 19: printprint("В городе цирк. В коде у Однобурцева тоже.", 15); break;
	}
}

void randAction()
{
	switch (rand() % 14)
	{
	case 0: printprint("Сьесть", 15); break;
	case 1: printprint("Выразить уважение", 15); break;
	case 2: printprint("Выразить соболезнования", 15); break;
	case 3: printprint("Вмешаться", 15); break;
	case 4: printprint("Расстрелять", 15); break;
	case 5: printprint("Наградить", 15); break;
	case 6: printprint("Ввести армию", 15); break;
	case 7: printprint("Дать денег", 15); break;
	case 8: printprint("Дать хлеба", 15); break;
	case 9: printprint("Согласиться", 15); break;
	case 10: printprint("Не согласиться", 15); break;
	case 11: printprint("Ничего не делать", 15); break;
	case 12: printprint("Забить", 15); break;
	case 13: printprint("Ловко пошутить", 15); break;
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
	printprint("Вы берете на себя роль управления государством.\n", 15);
	printprint("Ваша задача не дать экономике опуститься до 0.\nВ то же время, если ваша репутация опуститься до 0 вас свергнут.\n", 15);
	printprint("Вам будет предложено 2 варианта реакции на события.\nВыбирайте с умом: последствия выбора могут быть непредсказуемыми(а могут быть предсказуемыми)\nПродержитесь 15 дней\n", 15);
	printprint("Удачи!\n", 15);
	system("pause");

	for (int i = 1; i <= 15; i++)
	{
		system("cls");
		printf("День %d: Экономика - %d, Репутация - %d\n\n", i, money, reputation);
		randEvent();
		printf("\n1) "); randAction(); printf(" (Экономика "); money1 = randGain(); printf(", Репутация "); rep1 = randGain(); printf(")");
		printf("\n2) "); randAction(); printf(" (Экономика "); money2 = randGain(); printf(", Репутация "); rep2 = randGain(); printf(")");
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
			printprint("Казна пуста. Страна в разрухе.\n", 15);
			system("pause");
			return -1;
		}
		if (reputation <= 0)
		{
			printprint("Ваш диктаторский режим ненавидят. Востание идет полным ходом.\n", 15);
			system("pause");
			return -2;
		}
	}
	return 1;
}

