#include <iostream>
#include <Windows.h>
#include "func2.h"
#include "Opening.h"
#include "Krestiki.h"
#include "Reighn.h"
extern Player _player_;

bool excalibur = false;
bool info_exc = false;
bool namefalse = false;
bool mission = false;
bool king = false;
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


//чтобы избежать ставить более глубокие ветви выше корня
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
/*
1 попасть случайно
2 убил на либуре
3 оставил в живых
4 забираешь себе
5 не 4 идешь с ним

*/
void gamescissors()
{

	printprint("1) выбрать ножницы\n", 15);
	printprint("2) выбрать камень\n", 15);
	printprint("3) выбрать бумага\n", 15);
	for (int i = 1; i <= 3; i++)
	{
		switch (choice(3))
		{
		case 1:
			printf("ВЫ ставите ножницы - противник камень вы проиграли %i:0 \n", i); break;
		case 2:
			printf("ВЫ ставите камень - противник бумагу вы проиграли %i:0 \n", i); break;
		case 3:
			printf("ВЫ ставите бумагу - противник ножницы вы проиграли %i:0 \n", i); break;
		}
	}
	printprint("вы проиграли.КАКАЯ НЕОЖИДАНОСТЬ\n", 15);
	system("pause");
}
void fight_ant_anthill()
{
	if (mission == true)
		printprint("видимо это та самая колония\n", 15);
	bool endfight = false;
	bool palka = true;
	do {
		printf("ты: %.0f hp\n", _player_.health);
		printf("муравьи: %d кол-во\n", ant_colonies.healht);
		int block = 0;
		int vibor;
		
		printf("ваши действия:\n1)атаковать \n2)использовать \n3)пропустить ход \n4)защищаться\n5)сбежать\n");
		do { scanf_s("%d", &vibor); } while (vibor < 1 or vibor>5);system("cls");
		if (vibor == 1)
		{
			_player_.stamina -= _player_.strength;
			if (_player_.stamina < 0)
			{
				printf("вам не хватает сил ударить\n");
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
			printf("использовать:\n");
			printf("1) ОГРОМНАЯ лупа\n");
			printf("2) палка \n");
			int vibor2;
			
			do { scanf_s("%d", &vibor2); } while (vibor2 < 1 or vibor2>2);
			if (palka)
			{
				if (vibor2 == 1)
				{
					printf("вы сжигаете ОГРОМНОЙ лупой всех муравьёв, которые успели вылести \n");
					ant_colonies.healht -= 30000 + rand();
				}
				if (vibor2 == 2)
				{
					printf("вы тыкаете в муравейник палкой, муравьи впали в ярость от такого и вылезли все сразу \n");
					ant_colonies.attack += _player_.defense;
					palka = false;
				}
			}
			else
			{
				if (vibor2 == 1)
				{
					printf("вы сжигаете ОГРОМНОЙ лупой всех муравьёв, зря они вылезли \n");
					ant_colonies.healht = 0;
					endfight = false;
				}
				if (vibor2 == 2)
					printf("вы тыкаете в муравейник палкой, видимо ВАМ это приносит удовольствие (ничего не меняется) \n");
			}
		}
		if (vibor == 3)
			_player_.stamina += _player_.max_stamina / 2;
		if (vibor == 4)
			printf("вы пытаетесь защититься от мураьев, но они залезают под броню и продолжают вас бить \n");
		if (vibor == 5)
			endfight = true;
		if (ant_colonies.healht > 0)
		{
			ant_colonies.chardg++;
			if (ant_colonies.chardg >= ant_colonies.time_hod)
			{
				if (palka)
					printf("ваша кожа настолько жирная, что муравьи не могут её прокусить -0 hp\n ");
				else
				{
					_player_.health -= (ant_colonies.attack - _player_.defense);
					printf("зря вы их разозлили -%d hp\n ", (ant_colonies.attack - _player_.defense));
					if (_player_.health <= 0)
						endfight = true;
				}
			}
		}
		
	} while (!endfight);
}
void microforest()
{
	printprint("ВЫ попали в карликовый лес, но заветного сокровища не видите\n\n", 15);
	printprint("1) пройти дальше\n", 15);
	printprint("2) осмотреть всё под ногами\n", 15);
	printprint("3) взобраться на саму ВЫСОКУЮ гору\n", 15);
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
	printprint("во время поисков ВЫ решаете забраться на самую ВЫСОКУЮ гору \n наступив на неё ВАША нога проваливается под землю \n быстро отпрыгивая от неё ВЫ видите, как от туда вылезают муравьи \n\n", 15);
	printprint("1) сразиться с ним\n", 15);
	printprint("2) убежать\n", 15);
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
		//допишите меня!!!!
		//destroy_village();
		break;
	}
}

void text_Excalibur()
{
	printprint("ВЫ решили посмотреть, что лежит на земле,\n раздвигаете крону деревьев и видите, как человечек размера с ладошку вытаскивает шпажку из камня \n\n", 15);
	printprint("1) забрать себе эту шпашку\n", 15);
	printprint("2) спросить, что он делает\n", 15);
	printprint("3) помочь вытянуть её\n", 15);
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
	printprint("Чуствуя себя НИЗКО, вы поднимаете шпажку, и всместе с ней того хазбика  \n\n", 15);
	printprint("1) скинуть его со шпажки\n", 15);
	printprint("2) снять и поставить на землю\n", 15);
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
	printprint("Он падает на землю и разбивается в лепёшку. Какой же МЕЛОЧНЫЙ поступок \n\n", 15);
	printprint("1) ничего не поделать, надо продолжать ВЕЛИКИЙ поход \n", 15);
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
	printprint("ВЫ спускаете его на землю и слышите от него какой-то писк похожее на проклятие.\nЯ был о нём более ВЫСОКОГО мнения\n\n", 15);
	printprint("1) ничего не поделать, надо продолжать ВЕЛИКИЙ поход \n", 15);
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
	printprint("он рассказал, что это легендарный меч - МЕГАлибур.\n его может вытащить только ВЕЛИКИЙ человек.\n\n", 15);
	printprint("1) вытащить и забрать себе меч и прокричать что-то на ВЕЛИКОМ\n", 15);
	printprint("2) \"держи, мой МАЛЕНЬКИЙ друг\"\n", 15);
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
	printprint("ВЫ высовываете шпажку и отдаёте её микрочелику.\nон просит вас пойти с ним в деревню, чтобы ВАС отблагодарить \n\n", 15);
	printprint("1) пойти с ним\n", 15);
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
	printprint("ВЫ оказыаетесь в маленькой деревне, самый большой дом ВАМ по колено. на входе был МИКРО дед", 15);
	switch (choice_on_village)
	{
	case 1:
		//допилите меня пожалуйста
		break;
	case 2:
		printprint("\n\"видимо это была деревня хазбика \".\n к ВАМ подходит дед и спрашивает, не натыкались ли ВЫ на кого-нибудь \n", 15);
		printprint("1) соврать\n", 15);
		printprint("2) сказать правду\n", 15);
		switch (choice(2))
		{
		case 1:
			//evil += 20;
			_player_.kind_evil -= 20;
			system("cls");
			printprint("\nвы говорите, что никого не видели. из вашего кармана выпадает шпажка, это видет дед и говорит\nтеперь, по нашим сказаниям, ты наш король, в честь этого устроим ВЕЛИКИЙ пир \n", 15);
			king = true;
			text_festival();
			break;
		case 2:
			//evil -= 2;
			_player_.kind_evil += 2;
			//intelect -= 10;
			_player_.intelligence -= 10;
			//text_jail();
			break;
		}

	case 3:
		printprint(" и вместе с ним был хазбик. они подходят к ВАМ и говорят\n\"вы украли нашу реликвию и навредили ВЫСОКОчинному гражданину ВЕЛИКОЙ деревни \n мы вынуждены взять вас под стражу\"\n \n", 15);
		printprint("1) пойти в тюрму \n", 15);
		printprint("2) сделать что-нибудь, чтобы оправдаться\n", 15);
		switch (choice(2))
		{
		case 1:
			//evil -= 2;
			system("cls");
			_player_.kind_evil += 2;
			//text_jail();
			break;
		case 2:
			printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
			mission = true;
			text_ant_anthill();
			break;

			break;
		}
		break;
	case 4:
		namefalse = true;
		printprint(",он подошёл к в вам и спросил\"как вас зовут?\"\n(мы забыли записать ваше имя, можете его написать ещё раз. Спасибо за понимание<3)  \n", 15);
		char f[40];
		scanf_s("%s", f, 40);
		system("cls");
		printprint("\nтеперь, по нашим сказаниям, ты наш король, в честь этого устроим ВЕЛИКИЙ пир \n", 15);
		king = true;
		text_festival();
		break;
	case 5:
		printprint("\nхазбик подбегает к деду и шепчет что-то ему, дед поворачивается к ВАМ и говорит\n благодаря тебе мы нашли короля, в честь этого устроим ВЕЛИКИЙ пир \n", 15);
		text_festival();
		break;
	}
}
void text_festival()
{
	printprint("\nначинается празднование за нового короля\n", 15);
	if (choice_on_village == 5)
		printprint("\nВАМ приносят ОГРОМНУЮ кастрюлю размером со стакан\n", 15);
	else
		printprint("\nВАМ приносят САМУЮ БОЛЬШУЮ тарелку на столе размером с ноготок\n", 15);
	printprint("\nк вам подходит гном и говорит, что он лучший игрок в камень ножницы бумага\n\n", 15);
	printprint("1) предложить сыграть  в камень ножницы бумага\n", 15);
	printprint("2) предложить сыграть  в крестики-нолики\n", 15);
	switch (choice(2))
	{
	case 1:
		//intelect -= 3;
		_player_.intelligence -= 3;
		system("cls");
		printprint("вы не поверили, ведь  камень ножницы бумага, по вашему мнению, зависит от случайности \n", 15);
		system("pause");
		gamescissors();
		break;
	case 2:
		//evil += 1;
		_player_.kind_evil -= 1;
		system("cls");
		printprint("он говорит ВАМ, что впервые в своей ДЛИННОЙ жизни слышит о такой игре, поэтому\n вы в КРАТЦЕ рассказываете правила и начинаете \n", 15);
		system("pause");
		if (krestiki() == 1) //?
			printprint("\nкакой ВЫ молодец, выиграли гнома, который играл в первый раз. ВЫ ВЕЛИКИЙ человек! \n", 15);
		else {
			printprint("\nВЫ решили поддаться гному, который видит эту игру впервые. ВЫ ВЕЛИКИЙ человек! \n", 15);
			//evil -= 3;
			_player_.kind_evil += 3;
		}
		break;
	}
	if (king == true)
		int reighnResuly = Reighn();
	//-2: Вас сверг уставший от диктатуры народ -1: Казна опустела 1: Вы продержались 15 дней. 
}

/*
1 попасть случайно
2 убил на либуре
3 оставил в живых
4 забираешь себе
5 не 4 идешь с ним

*/