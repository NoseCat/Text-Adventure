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
void destroy_village();
void end_microforest();
void text_jail();
void pinok();
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
	if(!destroy)
		printprint("вы проиграли.КАКАЯ НЕОЖИДАНОСТЬ\n Вы стали слабей -1 атака\n", 15);
	system("pause");
	_player_.strength -= 1;

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
					{
						printf("вы умерли от муравьев, проиграли такой МАЛЕНЬКОЙ угрозе.\n ");
						exit(0);
					}
				}
			}
		}
		
	} while (!endfight);
	system("cls");
	printprint("из муравейника вылез липрикон, и говорит, что он герой этого леса, отдаёт горшочек золота и улетает на радуге \n", 15);
	if (mission)
	{
		printprint("1) вернуться домой\n", 15);
		printprint("2) вернуться в деревню\n", 15);
		switch (choice(2))
		{
		case 1:
			
			system("cls");
			printprint("ВЫ возвращаетесь с ОГРОМНЫМ горшочком золота. поздравляю. \n", 15);
			exit(0);
			break;
		case 2:
			system("cls");
			printprint("из-за ВАС эта тирания кончилась, в честь этого началось празднавание \n", 15);
			king = true;
			text_festival();
			break;
		}
	}
	else
	{
		printprint("ВЫ возвращаетесь с ОГРОМНЫМ горшочком золота. поздравляю. \n", 15);
	
		exit(0);
	}
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
		if (WasAcademy)
		{
			printprint("ВЫ убегаете настолько далеко, насколько это возможно\n в этот раз вам не везет и вы оказываетесь посреди абсолютного ничего\n никто не услышит твой ВЫСОКИЙ юмор \n\n", 15);
			exit(0);
		}
		else
		{
			printprint("ВЫ убегаете настолько далеко, насколько это возможно\n как только вы начали успокаиваться и понимать что проиходит\n ВЫ давно выбежали из леса и попали на лекцию по некромантии \n\n", 15);
			text2_2();
		}
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
	printprint("ВЫ высовываете шпажку и отдаёте её хазбику.\nон просит вас пойти с ним в деревню, чтобы ВАС отблагодарить \n\n", 15);
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
		printprint("\nк ВАМ подходит дед и говорит \"чужеземец, мы видим на сколько ты ВЕЛИК и не хотим с тобой сражаться\"\n ВАМ дают выбор: помочь деревне или просто уйти. \n", 15);
		printprint("1) уйти\n", 15);
		printprint("2) помочь деревне\n", 15);
		printprint("3) разграбить деревню\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("вам не понравилось в этом лесу он был слишком МАЛ для вас\n", 15);
			exit(0);
			_player_.kind_evil += 2;
			//text_jail();
			break;
		case 2:
			system("cls");
			printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
			mission = true;
			text_ant_anthill();
			break;
		case 3:
			system("cls");
			printprint("\n  вы решаете уничтожить деревню, что бы забрать все их ценности \n", 15);
			mission = true;
			destroy_village();
			break;
			
		}
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
			text_jail();
			break;
		}

	case 3:
		printprint("\n и вместе с ним был хазбик. они подходят к ВАМ и говорят\n\"вы украли нашу реликвию и навредили ВЫСОКОчинному гражданину ВЕЛИКОЙ деревни \n мы вынуждены взять вас под стражу\"\n \n", 15);
		printprint("1) пойти в тюрму \n", 15);
		printprint("2) сделать что-нибудь, чтобы оправдаться\n", 15);
		switch (choice(2))
		{
		case 1:
			//evil -= 2;
			system("cls");
			_player_.kind_evil += 2;
			text_jail();
			break;
		case 2:
			printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
			mission = true;
			text_ant_anthill();
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
		{
			printprint("\nкакой ВЫ молодец, выиграли гнома, который играл в первый раз. ВЫ ВЕЛИКИЙ человек!\n Вы стали сильней +1 атака \n", 15);
			_player_.strength += 1;
		}
		else {
			printprint("\nВЫ решили поддаться гному, который видит эту игру впервые. ВЫ ВЕЛИКИЙ человек! \n Вы стали сильней +3 атака \n", 15);
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
			printprint("ВЫ были плохим королём, народ в вас разачаровался и сверг\n", 15);
		if (reighnResuly == -1)
			printprint("ВЫ грязный жинрый капиталист бургер(деньги кончились)\n есть или не есть вот в чём вопрос", 15);
		printprint("\n1)съесть\n", 15);
		printprint("2)СЪЕСТЬ\n", 15);
		printprint("\nКОНЕЦ\n", 5);
		if (reighnResuly == 1)
			printprint("ВЫ были отличным королем эта деревня процветает, но вы умерли с голода из-за МАЛЕНЬКИХ порций\n", 15);
		if(choice_on_village == 4)
			printprint("\n(Мицура не сделал запоминание имён поэтому о вас никто не будет помнить)\n", 15);
	}
	else
	{
		printprint("\nк ВАМ подходит старейшина и просит об 1 услуге: уничтожить ОГРОМНОЕ чудовище нападающие на поселение\n", 15);
		printprint("1) Я ВЕЛИКИЙ герой и не могу отказать\n", 15);
		printprint("2) Я ВЕЛИЧАЙШИЙ герой и не могу отказать\n", 15);
		printprint("3) Я ОГРОМЕННЕЙШИЙ герой и не могу отказать\n", 15);
		choice(3);
		system("cls");
		printprint("перед походом старейшина говорит ВАМ заточить своё оружие перед великим боем\n", 15);
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
		strcpy_s(rat.p_class, "Крыса");
		printprint("ВЫ пришли к логову этого зверя там была ОГРОМННАЯ крыса\n", 15);
		system("pause");
		fight(rat);
		printprint("тепереь ВЫ ВЕЛИКИЙ герой этого леса, о ктором будут сказывать легенды\n", 15);
	}
	exit(0);
	//-2: Вас сверг уставший от диктатуры народ -1: Казна опустела 1: Вы продержались 15 дней. 
}
void text_jail()
{
	system("cls");
	printprint("вы оказываетесь в тюрьме, но весьма условно, ведь в деревни не было таких ОГРОМНЫХ домов\n", 15);
	printprint("1) продолжить сидеть в тюрьме\n", 15);
	printprint("2) вымолить прощение\n", 15);
	printprint("3) уйти домой\n\n", 15);
	switch (choice(3))
	{
	case 1:
		system("cls");
		printprint("ВЫ продолжаете сидеть в тюрьме уже несколько дней. ВЫ хотите есть\n", 15);
		printprint("1) продолжить сидеть в тюрьме\n", 15);
		printprint("2) вымолить прощение\n", 15);
		printprint("3) уйти домой\n\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("ВЫ сидите в тюрьме довольно долго. ВЫ умираете с голода\n", 15);
			printprint("1) продолжить сидеть в тюрьме\n", 15);
			printprint("2) вымолить прощение\n", 15);
			printprint("3) уйти домой\n\n", 15);
			switch (choice(3)) //ААААААААААААААААААААААА матрешка лол
			{
			case 1:
				system("cls");
				printprint("ВЫ умерли с голода\n", 15);
				exit(0);
				break;
			case 2:
				system("cls");
				printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
				mission = true;
				text_ant_anthill();

				break;
			case 3:
				end_microforest();
				break;
			}
		case 2:
			system("cls");
			printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
			mission = true;
			text_ant_anthill();
			break;
		case 3:
			end_microforest();
			break;
		}

	case 2:
		system("cls");
		printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
		mission = true;
		text_ant_anthill();
		break;
	case 3:
		end_microforest();
		break;
		//case 3 вставил такой же как в блоке ниже потому что похоже на правду 
	}
	// я не знаю куда это закинуть выглядит вообще как копия года выше
		/*case 2:
			system("cls");
			printprint("\nВАМ дали задание, уничтножить колонию, котороя их уже долгое время терроризирует  \n", 15);
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
	printprint("\nВЫ начали разрушать дома и растаптывать всех подходящий защитников с зубачистками вместо оружия\nВЫ остановились, когда увидели безоружного, он предложил сыграть в камень ножницы бумагу\n если выиграет он то вы покините деревню, иначе они отдадут противоядие\n", 15);
	printprint("1) сыграть в камень ножницы бумага\n", 15);
	printprint("2) пнуть его\n", 15);
	switch (choice(2))
	{
	case 1:
	
		system("cls");
		gamescissors();
		system("cls");
		printprint("Вы проигрываете с ОГРОМНЫМ отстованием\n", 15);
		printprint("1) сделать, как вы договаривались\n", 15);
		printprint("2) забыть о договоре и пнуть его\n", 15);
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
	printprint("Вы пинаете его, как футбольный мячик, он улетает за горизонт\n", 15);
	printprint("больше никто не может ВАС остановить, полностью уничтожив деревню ВЫ не находите ничего ценного \n", 15);
	end_microforest();
	//break;
}
void end_microforest()
{
	if(destroy)
		printprint("Вы уже возвращаетесь домой, но оказывается, что те зубачистки были отравленны, ВЫ падаете без сознания\n", 15);
	else
		printprint("Вы возвращаетесь домой, c пустыми руками\n", 15);
}
/*
1 попасть случайно
2 убил на либуре
3 оставил в живых
4 забираешь себе
5 не 4 идешь с ним

*/