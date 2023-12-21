#include <iostream>
#include <windows.h>
#include "func2.h"
#include "func3.h"
#include "Opening.h"
#include "fight.h"
#include "Krestiki.h"

HANDLE circ = GetStdHandle(STD_OUTPUT_HANDLE);


// Был ли игрок в цирке.
bool was_at_circus = 0;

#pragma region circus_variables

// Репутация получаемая в пределах цирка.
int circus_reputation = 0;

// Волкоподобность.
int auf = 0;

// Знакомые в пределах цирка.
struct meetings_in_the_circus
{
	bool antrepreneur = 0, good_giant = 0, dresser = 0;
} circus_meetings;


// Роль игрока в цирке.
enum who_are_you
{
	defender = 1, clown, wolf, shapimaster, sprechstalmeister
};
// clown, wolf, shapimaster, sprechstalmeister
who_are_you hero_2_3;

#pragma endregion

#pragma region items
//проверка использования наковальни
bool sharp_2_3 = 0;
//необычное зеркало. подразумевается, что при 0, его нету у игрока.
bool mirror = 0;
#pragma endregion

extern Player _player_;

//
void opening_of_the_circus_2_3_0();
void beginning_of_the_circus_2_3_0();
void meet_with_antrepreneur_2_3_0();
void dialog_with_antrepreneur();
void circus_choice_2_3(int);
void event_progulka_2_3();
void defender_2_3_1();
void clown_2_3_2();
void Bonk_2_3_3();
void shapitmaster_2_3_4_1();
void sprechstalmeister_2_3_4_2();
void oddity_event_2_3();
void final_fight_2_3();
void ending_2_3(int story_code);

void opening_of_the_circus_2_3_0()
{
	system("cls");
	if (was_at_circus == 1)
	{
		printprint("Вы уже пробовали работать в цирке, независимо от результата, теперь это завершённая часть вашей истории.\n", 15);
		system("pause");
		system("cls");
		Begining();
	}
	printprint("Бродя по округе, Вы наткнулись на циркачей. Мания денег и внимания вынудила вас спросить, как примкнуть к ним.\nОни ответили, что нужно обратится к их «главному».\n", 15);
	printprint("\n1) Продолжить.\n2) Не решится. (попробовать найти другой способ заработать)\n", 15);
	switch (choice(2))
	{
	case 1:
		beginning_of_the_circus_2_3_0();
		break;
	case 2:
		system("cls");
		printprint("Вы не решаетесь рисковать и идти на это страшное испытание - проходить собеседование.\n", 15);
		system("pause");
		system("cls");
		Begining();
		break;
	default:
		printf("\nswitch error: opening_of_the_circus_2_3_0()\n");
		system("pause");
		break;
	}
}

void beginning_of_the_circus_2_3_0()
{
	system("cls");
	printprint("Пока Вы размышляли «цирковые» оценивали вас.\n", 15);
	if (_player_.charisma < 3)
		printprint("Ваша харизма показала персоналу цирка, что Вы не способны сделать практически ничего самостоятельно.\nВас отвели к «главному».\n", 15);
	else
	{
		printprint("Ваша харизма показала персоналу цирка, что Вы вполне самостоятельный. Вы самостоятельно пошли к «главному».\n", 15);
		circus_reputation++;
	}
	system("pause");
	system("cls");
	printprint("По пути Вы наблюдаете за репетицией цирковой труппы.\n", 15);
		switch (rand() % (3) + 1)
		{
		case 1:
			printprint("Вы пришли сюда заниматься серьёзными вещами и решили не отвлекаться от своей цели.\n(В соответствии с вашей удачей ничего не произошло)\n", 15);
			break;

		case 2:
			printprint("Вы наблюдали за трюковым номером волков. ( +1 к волкоподобности)\n", 15);
			auf++;
			break;

		case 3:
			printprint("Вы увидели как циркачи соревнуются в силе.\n\n1) Присоединиться и показать силу.\n2) Не отвлекаться\n", 15);
			switch (choice(2))
			{
			case 1:
				system("cls");
				if (_player_.strength < 15)
				{
					printprint("И что Вы собрались показывать? Вы заняли последнее место. Вы расстроились, но пользу для себя вынесли.\n(+1 к силе, -1 к репутации в цирке)\n", 15);
					_player_.strength++;
					circus_reputation--;
				}
				else if (_player_.strength >= 15 && _player_.strength < 40)
					printprint("Вы показали средний результат. Вас не забудут, ведь нельзя забыть то, что не запоминали.\n", 15);
				else if (_player_.strength >= 40)
				{
					printprint("Вы заняли лидирующие места. Кто-то весьма сильно похлопал вас по плечу.\n", 15);
					printprint("Мускулистый мужчина Вас похвалил и представился. Он оказался участником силовых номеров и весьма добрым «великаном».\n", 15);
					printprint("(+2 к репутации в цирке, новый знакомый: «добрый великан», -1 от текущего здоровья)\n", 15);
					_player_.health--;
					if (_player_.health <= 0)
						death();
					circus_reputation += 2;
					circus_meetings.good_giant = 1;
					_player_.kind_evil += 1;
				}
				break;

			case 2:
				system("cls");
				if (_player_.strength < 40)
				{
					printprint("Это было разумное решение. Для вас проявление силы уже только сопротивление притяжению.\n(+3 к интеллекту)\n", 15);
					_player_.intelligence += 3;
				}
				else
				{
					printprint("Вы решили не показывать свои способности. Возможно, в будущем эта нерешительность Вам поможет.\n(-1 от харизмы)\n", 15);
				}
				break;

			default:
				printf("\nswitch error: beginning_of_the_circus_2_3_0() case3\n");
				system("pause");
				break;
			}
			break;

		default:
			printf("\nswitch error: beginning_of_the_circus_2_3_0()\n");
			system("pause");
			break;
		}
	
	system("pause");
	system("cls");
	meet_with_antrepreneur_2_3_0();
	return;
}

void meet_with_antrepreneur_2_3_0()
{
	printprint("Наконец Вы заходите в кабинет антрепренёра цирка. Убранство комнаты граничит между роскошью и сортировкой по фэншую –\n", 5);
	printprint("часть комнаты завалена хламом. Однако владельца этой комнаты внутри не обнаруживается, и Вы остались на едине с собой.\n\n", 5);
	for (int wait = 0, loot_table = 1, loot_bunch = 1; wait <= 3;)
	{
		printprint("1) Осмотреть рабочий стол.\n2) Осмотреть валяющиеся вещи.\n3) Подойти к стиральной доске.\n4) Ждать\n5) Выйти из кабинета.\n", 5);
		// switch floor 1
		switch (choice(5))
		{
			// Рабочий стол
		case 1:
			system("cls");
			_player_.kind_evil -= 2;
			if (loot_table > 0)
			{
				printprint("Это потрёпанный дорогой стол. Возле него стоит такого же состояния кожаное кресло.\n", 15);
				printprint("В столе Вы находите потрёпанную книгу. Это сборник вдохновляющих цитат о волках.\nРядом лежит странное зеркальце. Хоть и старое на вид, но оно притягивает Ваш взгляд.\n(+2 к волкоподобности, теперь у вас есть необчное зеркало)\n", 15);
				auf += 2;
				mirror = 1;
				loot_table = 0;
				wait++;
			}
			else
				printprint("В столе нету ничего, что стояло бы Вашего внимания.\n", 15);
			system("pause");
			break;
			// Веши на полу
		case 2:
			_player_.kind_evil -= 2;
			system("cls");
			if (loot_bunch > 0)
			{
				printprint("Вы протягиваете руку к ближайшей вещи. Она пошевелилась за секунуду до вышего касания.\nНа вас выползает таракан.\n", 15);
				system("pause");
				Player cockroach;
				cockroach.max_health = 200.f;
				cockroach.health = 200.f;
				cockroach.strength = 1;
				cockroach.defense = 2;
				cockroach.intelligence = 1200;
				strcpy_s(cockroach.p_class, "Таракан");
				strcpy_s(cockroach.p_weapon, "лапки");
				fight(cockroach);
				wait++;
				loot_bunch = 0;
			}
			else
			{
				printprint("В этих вещах нету ничего, что стояло бы Вашего внимания. Хотя и до этого так же было.\n", 15);
				system("pause");
			}
			break;
			// книга и молот (r.i.p.) => стиральная доска.
		case 3:
			system("cls");
			printprint("Вы подходите к стиральной доске.\n", 15);
			printprint("Вы слышали разговоры и истории о способе заточки оружия при помощи шершавого молота. Может...\n", 15);
			printprint("\n1) Попробовать заточить своё оружие.\n2) Отойти.\n", 15);
			switch (choice(2))
			{
			case 1:
				_player_.kind_evil -= 2;
				enchantment(_player_);
				sharp_2_3 = 1;
				wait++;
				break;
			case 2:
				break;
			default:
				printf("\nswitch error: meet_with_antrepreneur_2_3_0() case3\n");
				system("pause");
				break;
			}
			break;
			// ожидание(+1 к wait)
		case 4:
			system("cls");
			printprint("Вы бездельничаете некоторое время...\n\n", 15);
			_player_.kind_evil += 1;
			wait++;
			break;
			// За кабинетом.
		case 5:
			system("cls");
			printprint("Вы выходите из кабинета.\n", 15);
			switch (wait)
			{
				// +1 wait
			case 0:
				printprint("Теперь Вы бездельничаете снаружи...\n", 15);
				printprint("Вы старались провести время с пользой:\nпинали земелю, думали о своём будущем величии и смотрели на потолок. Вы возвращаетесь в кабинет.\n\n", 15);
				wait++;
				break;

				// meet and +2 wait or +1 wait
			case 1:
				printprint("Мимо проходит парень в не дорогом, но аккуратном костюме. Он здоровается с вами.\n\n1) Попробовать завести разговор.\n2) Кивнуть.\n", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					if (_player_.charisma < 5)
					{
						printprint("Вы неловко мямлите. Парень спешит пройти мимо...\n", 15);
						wait++;
						break;
					}
					printprint("У вас получатся завести разговор с парнишкой. Он - костюмер цирковой турппы. (новый знакомый: костюмер)\n", 15);
					circus_meetings.dresser = 1;
					wait += 2;
					break;
				case 2:
					printprint("Вы кивнули. Паренёк проходит мимо.\n", 15);
					wait++;
					break;
				default:
					printf("\nswitch error: meet_with_antrepreneur_2_3_0() case5 case1\n");
					system("pause");
					break;
				}
				break;

				// помощь дргугу-силачу и +1 wait, если не знакомы +1 wait
			case 2:
				printprint("Вы наблюдаете за репетицией силового номера... ", 15);
				if (circus_meetings.good_giant == 1)
				{
					printprint("Вы решили помочь в тренировке «доброму великану».\nОн втянул вас в свою тренировку...\n(+1 к репутации в цирке, +1 к силе)\n", 15);
					circus_reputation++;
					_player_.strength++;
					_player_.kind_evil += 2;
					system("pause");
					wait++;
					break;
				}
				printprint("Ничего не проиcходит и Вы возвращаетесь в кабинет.\n", 15);
				wait++;
				system("pause");
				break;

				// антрепренёр у входа в кабинет.
			case 3:
				printprint("Вы наткнулись рослого мужчину в вычурном костюме.\nНекто: «Приветствую, полагаю Вы антрепренёр сего цирка, раз Вы вышли из этого кабинета».\n", 15);
				printprint("\n1) Да.\n2) Нет, как раз его жду.\n", 15);
				switch (choice(2))
				{
				case 1:
					_player_.kind_evil -= 2;
					system("cls");
					printprint("Вы приглашаете мужчину в кабинет, пропуская его вперёд.\n«Гость» ехидно улыбается Вам...\n", 15);
					SetConsoleTextAttribute(circ, 4);
					printprint("\n(-\b+\b-5\b6\b5 о\bО\bот\bТ\bт р\bР\bре\bЕ\bеп\bП\bпу\bУ\bут\bТ\bта\bА\bац\bЦ\bци\bИ\bии\bИ\bи в\bВ\bв ц\bЦ\bци\bИ\bир\bР\bрк\bК\bке\bЕ\bе)\n", 15);
					SetConsoleTextAttribute(circ, 7);
					circus_reputation -= 5;
					system("pause");
					break;
				case 2:
					system("cls");
					printprint("Некто: «Тогда я вас поздравляю, Вы дождались. Прошу, входите»\nМужчина пропускает вас внутрь.\n", 15);
					system("pause");
					break;
				default:
					printf("\nswitch error: meet_with_antrepreneur_2_3_0() case5 case3\n");
					system("pause");
					break;
				}
				wait++;
				break;
			default:
				printf("\nswitch error: meet_with_antrepreneur_2_3_0() case5\n");
				system("pause");
				break;
			}

			//system("pause");
			break;

		default:
			printf("\nswitch error: meet_with_antrepreneur_2_3_0()\n");
			system("pause");
			break;
		}
	}

	system("cls");
	printprint("В кабинет заходит мужчина и садится за рабочий стол.\n", 15);
	printprint("Некто: «Не буду тянуть волка за хвост и представлюсь. Я - антрепренёр данного цирка».\n", 15);
	system("pause");
	dialog_with_antrepreneur();
}

void dialog_with_antrepreneur()
{
	was_at_circus = 1;
	system("cls");
	printprint("Перед вами сидит на столько не низкий, что даже высокий,\nкрупного телосложения, что тощим не назвать,\n", 15);
	printprint("лицом не красен, а значит не ужасен, голосом низким пищать не станет,\n", 15);
	printprint("и в целом замечательный админ паблика в вк с цитатами.\n\n", 15);
	system("pause");
	system("cls");
	printprint("Антрепренёр: «Чем могу Вам угодить, уважаемый путник?»\n", 15);
	printprint("Аккуратная одежда, сравнимая с автобусным чеком в кармане, сразу выдаёт Ваш пустой кошелёк.\n", 15);
	system("pause");
	system("cls");
	printprint("Антрепренёр: «Если Вы здесь в поисках работы, то у нас как раз найдётся пару вакансий.\nПередайте Тому и Уилсону, что завтра могут не приходить... \n", 15);
	printprint("Возвращаясь к нашей теме, теперь могу предложить Вам три роли в нашем театре комедии».\n", 15);
	system("pause");
	system("cls");
	printprint("Антрепренёр предлагает Вам следующие вакансии: охранник; клоун; на бумаге медведь, на сцене волк.\n", 15);
	printprint("\n1) Выбрать охранника. [если уверенны в своей силе]\n2) Выбрать клоуна.\n3) Выбрать медведя (волка).\n4) Отказаться от работы в цирке. [Вы не сможете сюда вернутся]\n", 15);

	switch (choice(4))
	{
	case 1:
		circus_choice_2_3(1);
		break;
	case 2:
		circus_choice_2_3(2);
		break;
	case 3:
		circus_choice_2_3(3);
		break;
	case 4:
		circus_choice_2_3(6);
		break;
		/*case 4: 4) Вы пришли сюда не шутки шутить, а зарабатывать серьёзные деньги.\n
			printprint("Антрепренёр: «Вот как.\n", 15);
			Sleep(1500);
			printprint("Если ты заслуживаешь того, я назначу тебя на более ответственную роль,\n", 15);
			printprint("Можешь стать ведущим, а позднее и руководителем представлений - шпрейхшталмейстером,\nили же можешь стать шапитмейстером - надо же кому то декорации таскать.", 15);
			printprint("Работу стабильнее будет сложно найти,\nкак я говорю отсутствие спроса на кресло гарантирует комфорт сидящего».\n", 15);
			printprint("\n1) Шпрейхшталмейстер (киньте D20 на проверку дикции).\n2) Шапитмейстер.\n3) Обдумать все варианты.\n", 15);
			switch (choice(3))
			{
			case 1:
				circus_choice_2_3(5);
				break;
			case 2:
				circus_choice_2_3(4);
				break;

			case 3:
				system("cls");
				printprint("1) Выбрать охранника.\n2) Выбрать клоуна.\n3) Выбрать медведя (волка).\n4) Шпрейхшталмейстер\n5) Шапитмейстер.\n6) Отказаться от работы в цирке.\n", 10);
				circus_choice_2_3(choice(6));
				break;
			default:
				printf("\nswitch error: dialog_with_antrepreneur() switch4\n");
				system("pause");
				break;
			}*/
	default:
		printf("\nswitch error: dialog_with_antrepreneur()\n");
		system("pause");
		break;
	}

}

void circus_choice_2_3(int num)
{
	system("cls");
	switch (num)
	{
	case 1:
		printprint("Вы решаете пойти по трудоёмкому, но незамысловатому пути.\nОт того видите Вы здесь плюс и минус или два минуса будет зависеть остаток вашей жизни...\n", 15);
		hero_2_3 = defender;
		system("pause");
		system("cls");

		defender_2_3_1();
		break;
	case 2:
		printprint("Отныне для вас быть посмешищем для вас не позор, а повод для гордости.\n", 15);
		hero_2_3 = clown;
		system("pause");
		system("cls");

		clown_2_3_2();
		break;
	case 3:
		printprint("Как говорится, волк в цирке не выступает. Вы решились пойти против этого утверждения, Вам придётся постараться.\n", 15);
		printprint("Будьте осторожны, ведь многие в этом мире слышали эти слова. Раз уж волк таки выступает, может это и не волк вовсе?..\n", 15);
		hero_2_3 = wolf;
		system("pause");
		system("cls");

		Bonk_2_3_3();
		break;
	case 4:
		printprint("Вы либо замена грузчика, либо творец. Ваши действия дадут ответ на этот вопрос.\n", 15);
		hero_2_3 = shapimaster;
		system("pause");
		system("cls");

		shapitmaster_2_3_4_1();
		break;
	case 5:
		printprint("Ваши амбиции велики, но всегда найдётся рыбка покрупнее...\n", 15);
		hero_2_3 = sprechstalmeister;
		system("pause");
		system("cls");

		sprechstalmeister_2_3_4_2();
		break;
	case 6:
		printprint("Вы покидаете цирк и решаете попробовать что-то ещё.\n", 15);
		system("pause");
		system("cls");
		Begining();
		break;
	default:
		printf("\nswitch error: circus_choice_2_3()\n");
		system("pause");
		break;
	}
}
//праведный защитник великого театра комедии - охранник цирка
void defender_2_3_1()
{
	Player cockroach;
	cockroach.max_health = 200.f;
	cockroach.health = 200.f;
	cockroach.strength = 1;
	cockroach.defense = 2;
	cockroach.intelligence = 1200;
	strcpy_s(cockroach.p_class, "Таракан");
	strcpy_s(cockroach.p_weapon, "лапки");

	system("cls");
	printprint("Всё что от вас требуется:\nОхранять вещи антрепренёра от тараканов. По какой-то причине обычный охрынник ему не нужен...\n", 15);
	printprint("Не потребовалось много времени,\nчтобы в поле зрения появился первый таракан - отныне Ваш естественный враг.\n", 15);
	system("pause");
	system("cls");
	fight(cockroach);
	system("cls");
	printprint("Из под хлама выползает ещё один.\n", 15);
	system("pause");
	fight(cockroach);
	system("cls");
	printprint("Присмотревшись Вы обнаруживаете, что это не таракан, а блоха-переросток. Вы замечаете ещё двух особей...\nНе к месту, но Вы вспоминаете, что слышали как-то, что существует карликовый лес.\nКак бы его обитатели отреагировали на это место?\n", 15);
	system("pause");
	strcpy_s(cockroach.p_class, "БЛОХА");
	fight(cockroach);
	system("cls");
	printprint("...", 40);
	printprint("\b\b\bПроходит несколько недель. Блохи - переростки продолжают отовсюду лезть, а прошлым вечером Вы перед уходом видели\nторчащую из под хлама кисть. Антрепренёр - не художник, да и кисть - не для красок.\n", 15);

	bool run_later_2_3 = 0;
	printprint("\n1) Бежать из цирка.\n2) Запланировать побег\n3) Вам показалось и боятся на самом деле нечего.\n", 5);
	if (choice(3) == 1)
	{
		system("cls");
		printprint("Вы бежите из цирка.\n", 15);
		system("pause");
		ending_2_3(1);
	}
	else
		run_later_2_3 = 1;

	system("cls");
	printprint("...", 40);
	printprint("\b\b\bСпустя ещё пару дней Вы решаетесь задать несколько вопросов антрепренёру.\nОн молча слушал вас и потом никак не реагировал ещё несколько секунд.\nПосле чего слегка улыбнулся и ссылается на Вашу усталость и реквизит.\nУходя дальше по своим делам он сказал, чтобы Вы отдохнули пару дней.\n", 15);
	system("pause");
	system("cls");

	if (run_later_2_3 == 0)
		printprint("После отдыха Вы действительно не замечали больше ничего необычного, а тараканы обьяснялись\nэлементарной утечкой газа пару лет назад недалеко от этого цирка.\n", 15);
	else
	{
		printprint("Вы решаете, что лучшего момента для побега не будет.\n", 15);
		system("pause");
			switch (rand() % (2) + 1)
			{
			case 1:
				system("cls");
				printprint("Когда Вы уже подходили к выходу из шатра Вам показалось, что кто-то стоит у выхода.\nПодождав с минуту Вы решаете аккуратно проверить кто это, и он оказываетс знаком Вам,\nдаже очень - антрепренёр. \n", 15);
				printprint("1) Притвориться, что ничего не замышляете и идти дальше.\n2) Осторожно уйти и попытаться уйти другим способом.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					printprint("Антрепренёр поварачивает голову в вашу сторону.\nУвидев вас он ехидно улыбается. В следующее мгновение когтистая лапа протыкает Вам живот.\nОн догадался, что Вы собираетесь уйти и ждал вас.\n", 15);
					printprint("(-30 от здоровья)\n", 15);
					_player_.health -= 30;
					system("pause");
					final_fight_2_3();
				}
				else
				{
					system("cls");
					printprint("Вы пролазите под покрытием шатра в задней его части и бежите из цирка.\n", 15);
					ending_2_3(1);
				}
				system("pause");
				break;

			case 2:
				system("cls");
				printprint("Вы выходите из циркового шатра, но замечаете, как вас атакует когтистая лапа.\nУворачиваясь Вы замечаете, что вас атакует волкоподобный антрепренёр.\n", 15);
				system("pause");
				final_fight_2_3();
				system("pause");

				break;

			default:
				system("cls");
				printprint("\nswitch error: defender_2_3_1()\n", 15);
				system("pause");
				break;
			}
	}
	system("pause");
	system("cls");
	printprint("Вы работаете «охранником» цирка на протежении многих лет.\nПока одним вечером на вас не нападает огромный волкоподобный монстр...\n", 15);
	printprint("Возможно, если бы Вы тогда попытались разобраться или уйти, когда Вы были в лучшей форме,\nто смогли бы спастись из этого театра реквиема.\n", 15);
	system("pause");
	system("cls");
	death();
}

void clown_2_3_2()
{
	if (_player_.charisma < 10)
	{
		printprint("Вы только заступили на должность, из чувства ответственности Вам показалось,\nчто было бы неплохо изучить осноВы своей профессии.", 15);
		printprint("Не смыкаете глаза на протяжении двух суток,\nВы научились начальному искусству клоуна.\n(+2 к харизме)\n", 15);
		_player_.charisma += 2;
		system("pause");
		system("cls");
	}
	printprint("Спустя пару дней приходит время Вашего первого показа. Вам выдали небольшой открывок времени после антракта.\nЕсли Вы опозоритесь, пара человек не успеет это увидеть.\n", 15);
	system("pause");
	system("cls");
	printprint("Наконец приходит час вашей славы! Хотя час это громко сказано, у вас 10 минут,\nчтобы показать над чем Вы работали последние несколько дней. Вы выходите на манеж.\n", 15);
	printprint("\n1) Использовать цитату, которую видели в кабинете антрепренёра. [Удача]\n2) Импровизировать. [Харизма]\n3) Показать трюк. [Сила]\n", 15);
	switch (choice(3))
	{
	case 1:
		_player_.kind_evil -= 2;
		system("cls");
		printprint("Вы: «Бесплатный сыр не обязательно будет платным».\n", 15);
		switch (rand() % (3) + 1)
		{
		case 1:
			printprint("Всем это понравилось\n(+3 к репутации в цирке, +2 к харизме, +2 удаче, надбавка: +15 к деньгам)\n", 15);
			circus_reputation += 3;
			_player_.charisma += 2;
			_player_.luck += 2;
			_player_.money += 15;
			break;

		case 2:
			printprint("Звучит пару смешков, но на этом всё. Вы вынессли для себя урок\n(+1 к харизме, надбавка: +5 к деньгам)\n", 15);
			_player_.charisma += 1;
			_player_.money += 5;
			break;

		case 3:
			printprint("В ответ Вам была тишина.\nАнтрепренёр не знает с чего больше злится, с того что Вы украли его цитату, или с того,\nкакая рекция была на Ваши потуги.\n(-3 от репутации в цирке)\n", 15);
			circus_reputation -= 3;
			_player_.kind_evil -= 1;
			break;

		default:
			printf("\nswitch error: clown_2_3_2() case1\n");
			system("pause");
			break;
		}
		break;

	case 2:
		system("cls");
		printprint("Вы показываете публике комедийную сценку.\n", 15);
		if (_player_.charisma >= 5) // Харизма мага +2, 2 харизмы ему даётся в начале клоунады.
		{
			printprint("Ваша подача угодила людям.\n(+1 к репутации в цирке, +1 к харизме, надбавка: +10 к деньгам)\n", 15);
			circus_reputation++;
			_player_.charisma++;
			_player_.money += 10;
			system("pause");
			break;
		}
		printprint("Ваши действия не нашли отклика.\n", 15);
		system("pause");
		break;

	case 3:
		system("cls");
		printprint("Вы решаете показываеть силовой трюк.\n", 15);
		if (_player_.strength < 15)
		{
			printprint("У вас не вышло осуществить задуманное. Но публика восприняла это как часть комедийного номера.\n(+1 к репутации в цирке, надбавка: +5 к деньгам)\n", 15);
			circus_reputation++;
			_player_.money += 5;
		}
		else if (_player_.strength >= 15)
		{
			printprint("У вас вышло осуществить задуманное. Публика хорошо оценила Ваш номер.\n(+2 к репутации в цирке, надбавка: +10 к деньгам)\n", 15);
			circus_reputation += 2;
			_player_.money += 10;
		}
		else if (_player_.strength >= 40)
		{
			printprint("Вы показываете пару трюков, рассчитанных на силу: жонглирование гантелей и\nкомедийную сценку, выполненную полностью в стойке на руках. ", 15);
			printprint("Публика с восторгом оценивает Ваше выступление\n(+4 к репутации в цирке, +1 к харизме, надбавка: +20 к деньгам)\n", 15);
			circus_reputation += 4;
			_player_.charisma++;
			_player_.money += 20;
			if (circus_meetings.good_giant == 0)
			{
				printprint("После выступления к Вам подходит мускулистый мужчина и сильно хлопает вас по плечу.\n", 15);
				printprint("Он похвалил Вас и представился. Мужчина оказался участником силовых номеров и весьма добрым «великаном».\n", 15);
				printprint("(новый знакомый: «добрый великан», -1 от текущего здоровья)\n", 15);
				_player_.health--;
				_player_.kind_evil += 1;
				if (_player_.health <= 0)
					death();
				circus_meetings.good_giant = 1;
			}
			else
			{
				printprint("После выступления к Вам подходит «добрый великан» и сильно хлопает вас по плечу.\nОн хвалит Вас и добровольно-принудительно забирает отпраздновать успешное выступление.\n(-1 здоровье(приветствие), -1 здоровья на одну ночь(опьянение))\n", 15);
				_player_.health -= 2; // -1 на одну ночь из-за алкоголя
				if (_player_.health <= 0)
					death();
			}
		}
		system("pause");
		break;

	default:
		printf("\nswitch error: clown_2_3_2()\n");
		system("pause");
		break;
	}

	system("cls");
	printprint("(зарплата: +10 к деньгам)\n", 15);
	system("pause");
	system("cls");
	printprint("Наступает следующее утро. Вы находитесь в выделенном «жилом» углу.\nВыберите чем Вы займётесь перед следующим выступлением.\n", 15);
	_player_.health++; //возврат 1 хп.
	printprint("\n1) Отдыхать. [Восстановление здоровья]\n2) Посмотреть в необычное зеркальце.\n3) Репетировать [Увеличение харизмы]\n4) Пройтись по округе цирка.\n", 15);
	bool sh_continue = 0;
	do
	{

		switch (choice(4))
		{
		case 1:
			system("cls");
			printprint("Вы отдыхаете весь оставшийся день.\n(здоровье полностью восстановлено)\n", 15);
			_player_.health = _player_.max_health;
			system("pause");
			sh_continue = 1;
			break;

		case 2:
			system("cls");
			if (mirror == 1)
			{
				printprint("Это необычное зеркало, Вам сложно отвести взгляд от него.\n1) Взглянуть на «Я». [Характеристики]\n2) Долго смотреть на «Я»", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					printstats(_player_);
					system("pause");
					break;

				case 2:
					system("cls");
					printprint("Вы долго смотрите в зеркало...\n", 15);

					SetConsoleTextAttribute(circ, 4);
					printprint("П\bп\bПо\bО\bок\bК\bка\bА\bа «\b#\b«Я\bя\bЯ»\b#\b» н\bН\bне\bЕ\bе п\bП\bпо\bО\bос\bС\bсм\bМ\bмо\bО\bот\bТ\bтр\bР\bре\bЕ\bел\bЛ\bло\bО\bо н\bН\bна\bА\bа в\bВ\bва\bА\bас\bС\bс в\bВ\bв о\bО\bот\bТ\bтв\bВ\bве\bЕ\bет\bТ\bт...\n", 9);
					system("pause");
					SetConsoleTextAttribute(circ, 7);

					char real_class_2_3[50];
					strcpy_s(real_class_2_3, _player_.p_class);
					strcpy_s(_player_.p_class, "Ты");
					fight(_player_);
					strcpy_s(_player_.p_class, real_class_2_3);
					_player_.health = 0;
					death();

					break;

				default:
					printf("\nswitch error: second clown_2_3_2 case2\n");
					system("pause");
					break;
				}

			}
			printprint("У вас нету зеркала, но его вероятно можно найти в кабинете антрепренёра.\n", 15);
			system("pause");
			break;

		case 3:
			system("cls");
			printprint("Вы репетировали весь оставшийся день.\n(+2 к харизме)\n", 15);
			_player_.charisma += 2;
			system("pause");
			sh_continue = 1;
			break;

		case 4:
			system("cls");
			event_progulka_2_3();
			sh_continue = 1;
			break;
		default:
			printf("\nswitch error: second clown_2_3_2\n");
			system("pause");
			break;
		}
	} while (sh_continue == 0);

	oddity_event_2_3();

}


// первая 1/3 комплекта концовки
void event_progulka_2_3()
{
	printprint("1) Вернуться в свой угол\n2) Проникнуть в кабинет антрепренёра.\n3) Прогулятся по территории цирка\n4) Пойти на рынок\n5) Пойти в лес.\n", 15);
	int num = choice(5);
	bool buy = 1;
	system("cls");
	switch (num)
	{
	case 1:
		system("cls");
		break;

	case 2:
		if (rand() % (2) + 0)
		{
			printprint("Неудача!\nВ кабинете оказался антрепренёр. Он оценил Ваше «кродёться».\n(-2 от репутации в цирке)\n", 15);
			circus_reputation -= 3;
			system("pause");
		}
		else
		{
			printprint("Успех!\nКабинет оказывается пуст. Вы в попыхах осматриваете рабочий стол и груды вещей на полу.\n", 15);
			if (sharp_2_3 == 0)
			{
				printprint("Вы подходите к стиральной доске.\n", 15);
				printprint("Вы слышали разговоры и истории о способе заточки оружия при помощи шершавого молота. Может...\n", 15);
				printprint("\n1) Попробовать заточить своё оружие.\n2) Отойти.\n", 15);
				switch (choice(2))
				{
				case 1:
					//Проверка на !
					enchantment(_player_);
					sharp_2_3 = 1;
					system("cls");
					break;
				case 2:
					system("cls");
					break;
				default:
					printf("\nswitch error: event_progulka_2_3() case2\n");
					system("pause");
					break;
				}
			}
			if (mirror == 0)
			{
				printprint("(+10 к деньгам, теперь у вас есть необычное зеркало)\n", 15);
				mirror = 1;
				system("pause");
				break;
			}
			printprint("(+10 к деньгам)\n", 15);
			system("pause");
		}
		break;

	case 3:
		printprint("Вы проходите мимо места тренировки животных\n(+1 к волкоподобности)\n", 15);
		auf++;
		system("pause");
		break;

	case 4:
		printprint("Вы приходите на рынок.\n\n1) Купить кровавое зелье. [20 золота = + 10 к максимальному здоровью]\n2) Купить светлое нефильтрованное зелье. [20 золота = + 10 к макс.", 15);
		printf("%s", _player_.p_class_stamina);
		printprint("]\n3) Уйти.\n", 15);
		printstat(_player_, money);
		printf("\n");
		if (_player_.money < 20)
		{
			printprint("\nДенег нету, Вы уходите.\n", 15);
			system("pause");
			system("cls");
			break;
		}
		while (_player_.money >= 20 and buy == 1)
		{
			system("cls");
			printprint("Вы приходите на рынок.\n\n1) Купить кровавое зелье. [20 золота = + 10 к максимальному здоровью]\n2) Купить светлое нефильтрованное зелье. [20 золота = + 10 к макс.", 15);
			printf("%s", _player_.p_class_stamina);
			printprint("]\n3) Уйти.\n", 15);
			printstat(_player_, money);
			switch (choice(3))
			{
			case 1:

				printprint("Вы покупаете кровавое зелье и выпиваете его.\n(+10 к текущему здоровью, + 10 к максимальному здоровью)\n", 15);
				_player_.money -= 20;
				_player_.max_health += 10;
				_player_.health += 10;
				break;

			case 2:

				printprint("Вы покупаете светлое нефильтрованное зелье и выпиваете его.\n(+10 к текущему значению ", 15);
				printf("«%s»", _player_.p_class_stamina);
				printprint(", +10 к максимальному значению ", 15);
				printf("«%s»)\n", _player_.p_class_stamina);
				_player_.money -= 20;
				_player_.max_stamina += 10;
				_player_.stamina += 10;
				break;

			case 3:
				system("cls");
				buy = 0;
				break;
			default:
				printf("\nswitch error: event_progulka_2_3() case4\n");
				system("pause");
				break;

			}
		}
		printprint("\nВы уходите.\n", 15);
		system("pause");
		system("cls");
		break;

	case 5:
		system("cls");
		printprint("1) Идти дальше\n2) Вернуться\n", 15);
		if (choice(2) == 2)
			break;
		system("cls");
		printprint("1) Идти дальше\n2) Вернуться\n", 15);
		if (choice(2) == 2)
			break;
		system("cls");
		printprint("!) Идти дальше\n2) Вернуться\n", 15);
		if (choice(2) == 2)
			break;
		system("cls");
		printprint("Вы наткнулись на стаю волков.\n", 15);
		system("pause");
		Player wolfick;
		wolfick.max_health = 35.f;
		wolfick.health = 35.f;
		wolfick.strength = 15;
		wolfick.defense = 5;
		strcpy_s(wolfick.p_class, "Волк");
		strcpy_s(wolfick.p_weapon, "Клыки");

		Player alfa_wolfick;
		alfa_wolfick.max_health = 75.f;
		alfa_wolfick.health = 75.f;
		alfa_wolfick.strength = 25;
		alfa_wolfick.defense = 25;
		strcpy_s(alfa_wolfick.p_class, "Альфа волк");
		strcpy_s(alfa_wolfick.p_weapon, "Острые когти");

		fight(wolfick);
		system("cls");
		printprint("Бой продолжается...\n", 15);
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("Бой продолжается...\n", 15);
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("Бой продолжается. А Вы устаёте...\n", 15);
		_player_.stamina -= _player_.max_stamina / 2;
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("Бой продолжается. А Вы устаёте...\n", 15);
		_player_.stamina -= _player_.max_stamina / 4;
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("Бой продолжается, Вы устаёте, но главное препятствие ещё впереди...\n", 15);
		_player_.stamina = 0;
		system("pause");
		fight(alfa_wolfick);
		_player_.stamina = 0;

		system("cls");
		printprint("(+5 к силе, +8 к интеллекту, +10 волкоподобности (победа над альфа-особью волка))\n", 15);
		_player_.strength += 5;
		_player_.intelligence += 8;
		auf += 10;
		system("pause");
		system("cls");
		printprint("Вы пытаетесь выйти из леса. Спустя несколько часов блужданий блужданий Вам удаётся выйти на рыночную площадь.\nПоследний торговец, который уже собирался уходить замечает вас и шокированный вашем видом подбегает к Вам.\n", 15);
		printprint("Вам повезло, он был торговцем зелий. Пока Вы рассказывали что с Вами приключилось торговец вылечил вас.\n(Теперь Вы полностью здоровы)\n", 15);
		_player_.health = _player_.max_health;
		_player_.stamina = _player_.max_stamina;
		system("pause");
		system("cls");

		printprint("В качестве оплаты Вы отдаёте пару тушу волка, которую Вы решили взять как трофей.\nПосле обмена любезностями Вы наконец возвращаетесь в цирк.\n", 15);
		system("pause");
		break;

	default:
		printf("\nswitch error: event_progulka_2_3()\n");
		system("pause");
		break;

	}
	system("cls");
}

// Вторая 1/3 комплекта концовки
// Очень сюрные дела. Первые попытки игрока выйти на концовку. 
void oddity_event_2_3()
{
	bool sh_continue = 0;
	bool cabinet = 0;

	do {
		system("cls");
		printprint("С самого утра в цирке почему-то шумно. Вы не обращаете на это внимаения и продолжаете заниматься своими делами.\n", 15);
		printprint("Днём запланированно представление и Вы в нём учавствуете.\n1) Подготавливаться.\n2) Проверить необычное зеркало.\n", 15);
		switch (choice(3))
		{

		case 1:
			system("cls");
			printprint("Вы повторяете свои номера.\n", 15);
			system("pause");
			sh_continue = 1;
			break;

		case 2:
			system("cls");
			if (mirror == 1)
			{
				printprint("Это необычное зеркало, Вам сложно отвести взгляд от него.\n1) Взглянуть на «Я». [Характеристики]\n2) Долго смотреть на «Я»", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					printstats(_player_);
					system("pause");
					break;

				case 2:
					system("cls");
					printprint("Вы долго смотрите в зеркало...\n", 15);

					SetConsoleTextAttribute(circ, 4);
					printprint("П\bп\bПо\bО\bок\bК\bка\bА\bа «\b#\b«Я\bя\bЯ»\b#\b» н\bН\bне\bЕ\bе п\bП\bпо\bО\bос\bС\bсм\bМ\bмо\bО\bот\bТ\bтр\bР\bре\bЕ\bел\bЛ\bло\bО\bо н\bН\bна\bА\bа в\bВ\bва\bА\bас\bС\bс в\bВ\bв о\bО\bот\bТ\bтв\bВ\bве\bЕ\bет\bТ\bт...\n", 9);
					system("pause");
					SetConsoleTextAttribute(circ, 7);

					char real_class_2_3[50];
					strcpy_s(real_class_2_3, _player_.p_class);
					strcpy_s(_player_.p_class, "Ты");
					fight(_player_);
					strcpy_s(_player_.p_class, real_class_2_3);
					_player_.health = 0;
					death();

					break;

				default:
					printf("\nswitch error: oddity_event_2_3() case2\n");
					system("pause");
					break;
				}

			}
			printprint("У вас нету зеркала, но его вероятно можно найти в кабинете антрепренёра.\n", 15);
			system("pause");
			break;
		case 3:
			if (cabinet == 0)
			{
				printprint("Вы идёте к кабинету антрепренёра. Возле двери лежит растрёпанная одежда. Вы лишь подмечаете,\nчто убранство комнаты постепенно выходит за её пределы. Кабинет оказывается пуст.\nВы в попыхах осматриваете рабочий стол и груды вещей на полу.\n", 15);
				if (sharp_2_3 == 0)
				{
					printprint("Вы подходите к стиральной доске.\n", 15);
					printprint("Вы слышали разговоры и истории о способе заточки оружия при помощи шершавого молота. Может...\n", 15);
					printprint("\n1) Попробовать заточить своё оружие.\n2) Отойти.\n", 15);
					switch (choice(2))
					{
					case 1:
						enchantment(_player_);
						sharp_2_3 = 1;
						system("cls");
						break;
					case 2:
						system("cls");
						break;
					default:
						printf("\nswitch error: oddity_event_2_3() case3\n");
						system("pause");
						break;
					}
				}
				if (mirror == 0)
				{
					printprint("(+10 к деньгам, теперь у вас есть необычное зеркало)\n", 15);
					mirror = 1;
					system("pause");
					break;
				}
				printprint("(Вы ничего не находите)\n", 15);
				system("pause");
				system("cls");
				printprint("На обратном пути Вы заметили рыцарей в фуражках. ", 15);
				printprint("Вы решили, раз не к Вам - значит не важно.\n", 15);
				system("pause");
				cabinet = 1;
				break;
			}
			printprint("Вы уже были там.\n", 15);
			system("pause");
			break;
		}
	} while (sh_continue == 0);

	system("cls");
	printprint("Представление начинается, но за пределами манежа циркачи ведут себя кто будто напуганые,\nкто будто опечаленные. Наконец приходит ваша очередь выступать.\n", 15);

	int sherlok = 0;
	// разветвление по рутам
	switch (hero_2_3)
	{

	case clown:


		printprint("\n1) Импровизация. [Удача]\n2) Показать подготовленные номера. [Харизма]\n3) Показать трюк. [Сила]\n", 15);

		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("Вы: «Бесплатный сыр не обязательно будет платным».\n", 15);
			switch (rand() % (3) + 1)
			{
			case 1:
				printprint("Всем это понравилось\n(+2 к репутации в цирке, +2 к харизме, +2 удаче, надбавка: +10 к деньгам)\n", 15);
				circus_reputation += 2;
				_player_.charisma += 2;
				_player_.luck += 2;
				_player_.money += 10;
				break;

			case 2:
				printprint("Звучит пару смешков, но на этом всё.\n", 15);
				break;

			case 3:
				printprint("В ответ Вам была тишина.\n(-3 от репутации в цирке)\n", 15);
				circus_reputation -= 3;
				break;

			default:
				printf("\nswitch error: clown_2_3_2() case1\n");
				system("pause");
				break;
			}
			break;

		case 2:
			system("cls");
			printprint("Вы показываете публике комедийный номер.\n", 15);
			if (_player_.charisma >= 15) // Харизма мага +2, 2 харизмы ему даётся в начале клоунады.
			{
				printprint("Ваша подача развеселила людям.\n(+2 к репутации в цирке, +1 к харизме, надбавка: +15 к деньгам)\n", 15);
				circus_reputation += 2;
				_player_.charisma++;
				_player_.money += 15;
				system("pause");
				break;
			}
			printprint("Ваши действия не нашли отклика. Возможно стоило больше репетировать, либо Вы, как говорят, обделены талантом.\n", 15);
			system("pause");
			break;

		case 3:
			system("cls");
			printprint("Вы решаете показываеть силовой трюк.\n", 15);
			if (_player_.strength < 15)
			{
				printprint("У вас не вышло осуществить задуманное.\n(-1 к репутации в цирке)\n", 15);
				circus_reputation--;
			}
			else if (_player_.strength >= 15)
			{
				printprint("У вас вышло осуществить задуманное. Публика хорошо оценила Ваш номер.\n(+2 к репутации в цирке, надбавка: +10 к деньгам)\n", 15);
				circus_reputation += 2;
				_player_.money += 10;
			}
			else if (_player_.strength >= 40)
			{
				printprint("Вы с блеском показываете пару трюков.\nАкробаты и силачи начинают думать, что Вы хотите завтрать их работу.\n", 15);
				printprint("Публика с восторгом оценивает Ваше выступление\n(+2 к репутации в цирке, надбавка: +20 к деньгам)\n", 15);
				circus_reputation += 2;
				_player_.money += 20;
			}
			system("pause");
			break;

		default:
			printf("\nswitch error: clown_2_3_2()\n");
			system("pause");
			break;
		}

		system("cls");
		printprint("(зарплата: +10 к деньгам)\n", 15);
		system("pause");
		system("cls");
		printprint("Наступает следующее утро. Всебщяя паника становится явной.\n", 15);

		printprint("1) Не обращать внимания\n2) Попытаться разобратьс\n3) Уйти с тем, что есть.\n", 15);

		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("Вы решаете не обращать внимания.\n", 15);
			printprint("Спустя месяц работы антрепренёр приглашает вас к себе.\n", 15);
			if (circus_reputation > 20)
			{
				printprint("Он предлагает стать Вам оборотнем.\n1) Согласиться\n2) Отказаться\n", 15);
				if (choice(2) == 1)
					ending_2_3(6);
			}
			else
				if (circus_reputation > 6)
				{
					printprint("Он предлагает Вам стать его помощником.\n1) Согласиться\n2) Отказаться\n", 15);
					if (choice(2) == 1)
						ending_2_3(2);
					else
					{
						system("cls");
						printprint("Антрепренёр: «Очень жаль».\n", 15);
						printprint("В Вас на большой скорости что-то врезается и откидывает в другой конец комнаты.\nВы вырубаетесь.\n", 15);
						death();
					}
				}
			printprint("Вы закрываете дверь и подходите к столу антрепренёра.\nПоследнее что у Вас получается заметить - как он разворачивается в кресле и в Вас что-то летит.\nВы вырубаетесь.\n", 15);
			death();
			break;

		case 2:



			if (circus_meetings.good_giant == 1)
			{
				system("cls");
				printprint("Вы находите «доброго великана» и узнаёте у него о произошедшем.\nОказывается несколько цирковых пропали. Друг советует Вам быть осторожнее\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			if (circus_meetings.dresser == 1)
			{
				system("cls");
				printprint("Найдя костюмера Вы узнаёте у него о произошедшем.\nОказывается неподалёку в лесу нашли кости ещё недавно действующего артиста цирка.\nДруг советует Вам быть осторожнее\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			printprint("Вы расспрашиваете персонал цирка.\n", 15);
			system("pause");
			sherlok += _player_.charisma / 2;

			if (sherlok > 10)
			{

				printprint("Сложив всё известно об этом цирке, Вам становится очевидно:\nантрепренёр - волкоподобный монстр, который убивает своих подчинённых.\n1) Уйти с тем, что уже есть.\n2) Попробовать противостоять антрепренёру.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					ending_2_3(1);
				}
				else
				{
					system("cls");
					printprint("Вы находите антрепренёра. После обвинения его в пропаже циркачей Вы начинаете бой.\n", 15);
					system("pause");
					final_fight_2_3();
				}
			}
			else
			{
				printprint("Вам не приходит в голову идей, что щас происходит в цирке.\nСледовательно у вас есть два варианта:\n1) Уйти с тем, что уже есть.\n2) Продолжить, не обращая внимания на окружающий сюр.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					ending_2_3(1);
				}
				else
				{
					system("cls");
					printprint("Вы решаете не обращать внимания.\n", 15);
					printprint("Спустя месяц работы антрепренёр приглашает вас к себе.\n", 15);
					if (circus_reputation > 20)
					{
						printprint("Он предлагает стать Вам оборотнем.\n1) Согласиться\n2) Отказаться\n", 15);
						if (choice(2) == 1)
							ending_2_3(6);
					}
					else
						if (circus_reputation > 6)
						{
							printprint("Он предлагает Вам стать его помощником.\n1) Согласиться\n2) Отказаться\n", 15);
							if (choice(2) == 1)
								ending_2_3(2);
							else
							{
								system("cls");
								printprint("Антрепренёр: «Очень жаль».\n", 15);
								printprint("В Вас на большой скорости что-то врезается и откидывает в другой конец комнаты.\nВы вырубаетесь.\n", 15);
								death();
							}
						}
					printprint("Вы закрываете дверь и подходите к столу антрепренёра.\nПоследнее что у Вас получается заметить - как он разворачивается в кресле и в Вас что-то летит.\nВы вырубаетесь.\n", 15);
					death();
				}
			}
			break;

		case 3:
			system("cls");
			ending_2_3(1);
			break;

		default:
			printf("\nswitch error: second oddity_event_2_3() clown\n");
			system("pause");
			break;
		}

		break;

	case wolf:

		printprint("\n1) От волкоподобности\n2) За счёт харизмы и репутации\n3) На удачу\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("Вы стараетесь не выдавать в себе человека.\n", 15);

			if (auf > 25)
			{
				system("cls");
				printprint("Это было ужасающе. Прекрассный результат для волка - людей, что упали в обморок, выносят доктора.\n(+4 к репутации в цирке, надбавка: +15 к деньгам, штраф: -15 от денег)\n", 15);
				circus_reputation += 3;
				_player_.money += 15;
				system("pause");
			}
			else if (auf > 10)
			{
				system("cls");
				printprint("Будь у вас талант, Вы бы более талантливо выступили.\n(+1 к репутации в цирке, надбавка: +5 к деньгам)\n", 15);
				circus_reputation++;
				_player_.money += 5;
				system("pause");
			}
			else
			{
				system("cls");
				printprint("Вам сказали дать лапу, а Вы дали руку.\n(-2 от репутации в цирке)\n", 15);
				circus_reputation -= 2;
				system("pause");
			}
			system("pause");
			break;


		case 2:
			system("cls");
			printprint("Вы жертвуете харизмой и репутацией ради заработа.\n(-3 от харизма, -3 от репутации в цирке, надбавка: 20)\n", 15);
			circus_reputation -= 3;
			_player_.money += 20;
			_player_.charisma -= 3;
			system("pause");
			break;


		case 3:
			system("cls");
			switch (rand() % (3) + 1)
			{
			case 1:
				printprint("Вы хороший результат для прямоходящего.\n(+2 к репутации в цирке)\n", 15);
				circus_reputation += 2;

				break;

			case 2:
				printprint("Вы просто следовали инструкциям дрессировщика\n", 15);
				break;

			case 3:
				printprint("Встать и размятся посреди выступления было ошибкой.\n(-2 к репутации в цирке)\n", 15);
				circus_reputation -= 2;
				break;
			}
			system("pause");
			system("cls");
			break;
		default:
			printf("\nswitch error: second Bonk_2_3_3\n");
			system("pause");
			break;
		}

		system("cls");
		printprint("(зарплата: +10 к деньгам)\n", 15);
		system("pause");
		system("cls");
		printprint("Наступает следующее утро. Всебщяя паника становится явной.\n", 15);

		printprint("1) Не обращать внимания\n2) Попытаться разобратьс\n3) Уйти с тем, что есть.\n", 15);

		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("Вы решаете не обращать внимания.\n", 15);
			printprint("Спустя месяц работы антрепренёр приглашает Вас к себе.\n", 15);
			if (auf > 20)
			{
				printprint("Он предлагает стать Вам оборотнем.\n1) Согласиться\n2) Отказаться\n", 15);
				if (choice(2) == 1)
					ending_2_3(6);
			}
			else
				if (circus_reputation > 6 or auf > 10)
				{
					printprint("Он предлагает Вам стать его помощником.\n1) Согласиться\n2) Отказаться\n", 15);
					if (choice(2) == 1)
						ending_2_3(2);
					else
					{
						system("cls");
						printprint("Антрепренёр: «Очень жаль».\n", 15);
						printprint("В Вас на большой скорости что-то врезается и откидывает в другой конец комнаты.\nВы вырубаетесь.\n", 15);
						death();
					}
				}

			printprint("Вы закрываете дверь и подходите к столу антрепренёра.\nПоследнее что Вам удаётся заметить - как он разворачивается в кресле и в Вас что-то летит.\nВы вырубаетесь.\n", 15);
			death();
			break;

		case 2:


			if (circus_meetings.good_giant == 1)
			{
				system("cls");
				printprint("Вы находите «доброго великана» и узнаёте у него о произошедшем.\nОказывается несколько цирковых пропали. Друг советует Вам быть осторожнее\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			if (circus_meetings.dresser == 1)
			{
				system("cls");
				printprint("Найдя костюмера Вы узнаёте у него о произошедшем.\nОказывается неподалёку в лесу нашли кости ещё недавно действующего артиста цирка.\nДруг советует Вам быть осторожнее\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			printprint("Вы расспрашиваете персонал цирка.\n", 15);
			system("pause");
			sherlok += _player_.charisma / 2;

			if (sherlok > 10)
			{

				printprint("Сложив всё известно Вам об этом цирке, Вам становится очевидно:\nантрепренёр - волкоподобный монстр, который убивает своих подчинённых.\n1) Уйти с тем, что уже есть.\n2) Попробовать противостоять антрепренёру.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					ending_2_3(1);
				}
				else
				{
					system("cls");
					printprint("Вы находите антрепренёра. После обвинения его в пропаже циркачей Вы начинаете бой.\n", 15);
					system("pause");
					final_fight_2_3();
				}
			}
			else
				if (auf > 20)
				{
					printprint("Своим волчьим чутьём Вы узнаёте в антрепренёре - волкоподобного.\nОн и является виновником пропаж.\n1) Уйти с тем, что уже есть.\n2) Попробовать противостоять антрепренёру.\n", 15);
					if (choice(2) == 1)
					{
						system("cls");
						ending_2_3(1);
					}
					else
					{
						system("cls");
						printprint("Вы находите антрепренёра. После обвинения его в пропаже циркачей Вы начинаете бой.\n", 15);
						system("pause");
						final_fight_2_3();
					}
				}
				else
				{
					printprint("Вам не приходит в голову идей, что щас происходит в цирке.\nСледовательно у вас есть два варианта:\n1) Уйти с тем, что уже есть.\n2) Продолжить, не обращая внимания на окружающий сюр.\n", 15);
					if (choice(2) == 1)
					{
						system("cls");
						ending_2_3(1);
					}
					else
					{
						system("cls");
						printprint("Вы решаете не обращать внимания.\n", 15);
						printprint("Спустя месяц работы антрепренёр приглашает Вас к себе.\n", 15);
						if (auf > 20)
						{
							printprint("Он предлагает стать Вам оборотнем.\n1) Согласиться\n2) Отказаться\n", 15);
							if (choice(2) == 1)
								ending_2_3(6);
						}
						else
							if (circus_reputation > 6 or auf > 10)
							{
								printprint("Он предлагает Вам стать его помощником.\n1) Согласиться\n2) Отказаться\n", 15);
								if (choice(2) == 1)
									ending_2_3(2);
								else
								{
									system("cls");
									printprint("Антрепренёр: «Очень жаль».\n", 15);
									printprint("В Вас на большой скорости что-то врезается и откидывает в другой конец комнаты.\nВы вырубаетесь.\n", 15);
									death();
								}
							}

						printprint("Вы закрываете дверь и подходите к столу антрепренёра.\nПоследнее что Вам удаётся заметить - как он разворачивается в кресле и в Вас что-то летит.\nВы вырубаетесь.\n", 15);
						death();
					}
				}
			break;

		case 3:
			system("cls");
			ending_2_3(1);
			break;

		default:
			printf("\nswitch error: second oddity_event_2_3() wolf\n");
			system("pause");
			break;
		}

		break;

	case shapimaster:

		break;

	case sprechstalmeister:

		break;

	default:
		printf("\nswitch error: second oddity_event_2_3()\n");
		system("pause");
		break;



	}
}

void Bonk_2_3_3()
{
	system("cls");
	printprint("(-1 к харизме, +5 к волкоподобности)\n", 15);
	_player_.charisma--;
	auf += 5;
	system("pause");
	system("cls");
	printprint("Как бы парадоксально это не звучало, а главное не реализовывалось, Вы взяли на себя роль волка.\nМожете гордится собой, Вы первый зарегистрированный в этом мире цирковой волк.\nУ других волков не хватило духу для этого, ну или они были банально умнее, чем могли показаться.\n", 15);
	printprint("Дабы получать хорошую зарплату, надо скрывать свою человеческую сущность.\nПопробуете ли развить в себе другую сущность – волка,\nили пожертвуете гордостью и будете ползать на четвереньках - решать Вам.\n", 15);
	system("pause");
	system("cls");
	printprint("Вас отводят к дрессировщику и отныне он Ваш босс. Хотя, возможно,\nВы найдёте кого-то авторитетнее или сами станете этим авторитетом. Но вернитесь на землю,\nа лучше сразу опуститесь ещё ниже, чтобы соответствовать образу волка.\n", 15);
	printprint("После вводной тренировки дрессировщик оставил вас на попечение самому себе. Пока что Вы вольны выбирать чем заняться.\n", 15);
	printprint("\n1) Пройтись по округе\n2) Зайти в кабинет антрепренёра\n3) Пойти в выделенный Вам угол\n4) Репетировать [продолжение]\n5) Ползти в выделенный Вам угол\n6) Проползти в кабинет антрепренёра\n7) Проползать по округе\n", 15);
	bool x17 = false, x26 = false, x35 = false, x4 = false;
	//Почему они былит = 0 если они bool? Почему они названы как координаты? Что будет если я запущу программу в 354 день года в 17:26?
	do
	{
		switch (choice(7))
		{
		case 1:
			if (!x17)
			{
				system("cls");
				printprint("Вы натыкаетесь на компанию крепких мужчин. ", 15);
				if (circus_meetings.good_giant) //bool тебя не любит
				{
					printprint("Среди них есть и «добрый великан». Вы рассказываете о начале своей карьеры.\nОн не понимает вашего выбора, но не станет осуждыть друга.\n", 15);
					system("pause");
					system("cls");
				}
				else
				{
					printprint("Вы здороваетесь с ними и идёте дальше.\n(-2 волкоподобности)\n", 15);
					auf -= 2;
					system("pause");
					system("cls");
				}
				x17 = true;
				break;
			}
			system("cls");
			printprint("Вы уже исследовали округу.\n", 15);
			system("pause");
			system("cls");
			break;

		case 2:
			if (!x26)
			{

				system("cls");
				printprint("Вы стучитесь и входите в кабинет антрепренёра.\nАнтрепренёр: «Смотрю Вы ещё не смогли отпустить прошлые привычки.\nНичего, как никак для меня тоже в новинку нанимать актёра на роль циркового зверя».\nАнтрепренёр даёт Вам несколько советов, о том, как стоит играть роль волка.\nОткуда он это знает?\n", 15);

				x26 = true;
				break;
			}
			system("cls");
			printprint("Вы уже были в кабинете.\n", 15);
			system("pause");
			system("cls");
			break;

		case 3:
			if (!x35)
			{

				system("cls");
				printprint("Вы подходите к выделенному Вам «жилому» углу.\nСобачья конура будет более «жилой», впрчему, может Вас в неё позже и переселят.\n", 15);
				printprint("(+2 к волкободобности)\n", 15);
				auf += 2;
				if (mirror == 1)
				{

					printprint("В стороне от чужих взглядов Вы можете изучить необычное зеркало,\nкоторое нашли в кабинете антрепренёра.\n1) Изучить.\n2) Занятся чем-то ещё.\n", 15);
					if (choice(2) == 1)
					{
						printprint("Это необычное зеркало, Вам сложно отвести взгляд от него.\n1) Взглянуть на «Я». [Характеристики]\n2) Долго смотреть на «Я»", 15);
						switch (choice(2))
						{
						case 1:
							system("cls");
							printstats(_player_);
							system("pause");
							break;

						case 2:
							system("cls");
							printprint("Вы долго смотрите в зеркало...\n", 15);

							SetConsoleTextAttribute(circ, 4);
							printprint("П\bп\bПо\bО\bок\bК\bка\bА\bа «\b#\b«Я\bя\bЯ»\b#\b» н\bН\bне\bЕ\bе п\bП\bпо\bО\bос\bС\bсм\bМ\bмо\bО\bот\bТ\bтр\bР\bре\bЕ\bел\bЛ\bло\bО\bо н\bН\bна\bА\bа в\bВ\bва\bА\bас\bС\bс в\bВ\bв о\bО\bот\bТ\bтв\bВ\bве\bЕ\bет\bТ\bт...\n", 9);
							system("pause");
							SetConsoleTextAttribute(circ, 7);

							char real_class_2_3[50];
							strcpy_s(real_class_2_3, _player_.p_class);
							strcpy_s(_player_.p_class, "Ты");
							fight(_player_);
							strcpy_s(_player_.p_class, real_class_2_3);
							_player_.health = 0;
							death();

							break;

						default:
							printf("\nswitch error: second Bonk_2_3_3() case2\n");
							system("pause");
							break;
						}
					}
				}
				x35 = true;
				break;
			}
			system("cls");
			printprint("Вы уже были в «жилом» углу.\n", 15);
			system("pause");
			system("cls");
			break;

		case 4:
			printprint("Проходит несколько дней. Между делом Вы репетируете.\nК Вам приходит дрессировщик и говорит, что в полдень будет выступление.\n", 15);
			auf += 2;
			_player_.charisma += 2;
			x4 = true;
			system("pause");
			system("cls");
			break;

		case 5:
			if (!x35)
			{

				system("cls");
				printprint("Вы подходите к выделенному Вам «жилому» углу.\nСобачья конура будет более «жилой», впрчему, может Вас в неё позже и переселят.\n", 15);
				printprint("(+2 к волкободобности)\n", 15);
				auf += 2;
				if (mirror == 1)
				{

					printprint("В стороне от чужих взглядов Вы можете изучить необычное зеркало,\nкоторое нашли в кабинете антрепренёра.\n1) Изучить.\n2) Занятся чем-то ещё.\n", 15);
					if (choice(2) == 1)
					{
						printprint("Это необычное зеркало, Вам сложно отвести взгляд от него.\n1) Взглянуть на «Я». [Характеристики]\n2) Долго смотреть на «Я»", 15);
						switch (choice(2))
						{
						case 1:
							system("cls");
							printstats(_player_);
							system("pause");
							break;

						case 2:
							system("cls");
							printprint("Вы долго смотрите в зеркало...\n", 15);

							SetConsoleTextAttribute(circ, 4);
							printprint("П\bп\bПо\bО\bок\bК\bка\bА\bа «\b#\b«Я\bя\bЯ»\b#\b» н\bН\bне\bЕ\bе п\bП\bпо\bО\bос\bС\bсм\bМ\bмо\bО\bот\bТ\bтр\bР\bре\bЕ\bел\bЛ\bло\bО\bо н\bН\bна\bА\bа в\bВ\bва\bА\bас\bС\bс в\bВ\bв о\bО\bот\bТ\bтв\bВ\bве\bЕ\bет\bТ\bт...\n", 9);
							system("pause");
							SetConsoleTextAttribute(circ, 7);

							char real_class_2_3[50];
							strcpy_s(real_class_2_3, _player_.p_class);
							strcpy_s(_player_.p_class, "Ты");
							fight(_player_);
							strcpy_s(_player_.p_class, real_class_2_3);
							_player_.health = 0;
							death();

							break;

						default:
							printf("\nswitch error: second Bonk_2_3_3() case2\n");
							system("pause");
							break;
						}
					}
				}
				x35 = true;

				break;
			}
			system("cls");
			printprint("Вы уже были в «жилом» углу.\n", 15);
			system("pause");
			system("cls");
			break;

		case 6:
			if (!x26)
			{

				system("cls");
				printprint("Вы скребётесь в кабинет антрепренёра. Антрепренёр открывает Вам дверь. \nАнтрепренёр: «Смотрю Вы уже вжились в роль, мой четвероногий друг.\nАнтрепренёр бросает Вам под нос кость и закрывает дверь.\nОткуда у него в кабинете была кость?\n(+4 к волкоподобности, +1 к репутации в цирке)\n", 15);
				auf += 4;
				circus_reputation++;
				x26 = true;
				break;
			}
			system("cls");
			printprint("Вы уже были в кабинете.\n", 15);
			system("pause");
			system("cls");
			break;

		case 7:
			if (!x17)
			{

				system("cls");
				printprint("Вы натыкаетесь на компанию крепких мужчин.\n", 15);
				if (circus_meetings.good_giant == 1)
				{
					printprint("Среди них есть и «добрый великан». Он не понимает вашего выбора, но не станет осуждыть друга.\nА вот Вы напротив, ведь лучше осудить друга, чем друг друга\n(+2 к волкоподобности)\n", 15);
					auf += 2;
					system("pause");
					system("cls");
				}
				else
				{
					printprint("ЦиркоВы силачи недоверчиво смотрят на вас, но решают не придавать значения и пытаются покормить вас с руки.\n(+1 к волкоподобности)\n", 15);
					auf += 1;
					system("pause");
					system("cls");
				}
				x17 = true;
				break;
			}
			system("cls");
			printprint("Вы уже исследовали округу.\n", 15);
			system("pause");
			system("cls");
			break;

		default:
			printf("\nswitch error: Bonk_2_3_3()\n");
			system("pause");
			break;
		}
	} while (!x4);
	system("cls");
	printprint("Всё оставшееся время с вами тренируют разные трюки и номера.\n", 15);
	printprint("Приходит ваша очередь явить себя этому маленькому миру.\n\n1) От волкоподобности\n2) За счёт харизмы и репутации\n3) На удачу\n", 15);
	switch (choice(3))
	{
	case 1:
		system("cls");
		printprint("Вы стараетесь не выдавать в себе человека, непонятные отростки на задних лапах мешают этому...\n", 15);

		if (auf > 10)
		{
			system("cls");
			printprint("Это было ужасающе. Прекрассный результат для волка - Вы напугали подавляющую часть зрителей.\n(+3 к репутации в цирке, надбавка: +15 к деньгам)\n", 15);
			circus_reputation += 3;
			_player_.money += 15;
			system("pause");
		}
		else if (auf > 5)
		{
			system("cls");
			printprint("Вы не дали себя раскусить.\n(+1 к репутации в цирке, надбавка: +5 к деньгам)\n", 15);
			circus_reputation++;
			_player_.money += 5;
			system("pause");
		}
		else
		{
			system("cls");
			printprint("Вы с блеском проваливаетесь!\n(-2 от репутации в цирке)\n", 15);
			circus_reputation -= 2;
			system("pause");
		}
		system("pause");
		break;


	case 2:
		system("cls");
		printprint("Вы жертвуете харизмой и репутацией ради заработа.\n(-3 от харизма, -3 от репутации в цирке, надбавка: 20)\n", 15);
		circus_reputation -= 3;
		_player_.money += 20;
		_player_.charisma -= 3;
		system("pause");
		break;


	case 3:
		system("cls");
		switch (rand() % (3) + 1)
		{
		case 1:
			printprint("Вы случайно упали с барьера манежа, но эффектно сделали бочку.\n(+2 к репутации в цирке)\n", 15);
			circus_reputation += 2;

			break;

		case 2:
			printprint("Вы просто следовали инструкциям дрессировщика\n", 15);
			break;

		case 3:
			printprint("Вы случайно упали с барьера манежа, Вы падали как бренное тело человека, а должны были как туша волка.\n(-2 к репутации в цирке)\n", 15);
			circus_reputation -= 2;
			break;
		}
		system("pause");
		system("cls");
		break;
	default:
		printf("\nswitch error: second Bonk_2_3_3\n");
		system("pause");
		break;
	}

	system("cls");
	printprint("(зарплата: +10 к деньгам)\n", 15);
	system("pause");
	system("cls");
	printprint("Наступает следующее утро. Вы находитесь в выделенном «жилом» углу.\nВыберите чем Вы займётесь перед следующим выступлением.\n", 15);
	_player_.health++; //возврат 1 хп.
	printprint("\n1) Найти себе компнию.\n2) Посмотреть в необычное зеркальце.\n3) Репетировать [Увеличение харизмы]\n4) Пройтись по округе цирка.\n", 15);

	bool sh_continue = 0;
	int meetings_2_3_3 = 0;
	do
	{

		switch (choice(4))
		{
		case 1:
			system("cls");
			printprint("Вы ищете с кем пообщаться весь оставшийся день.\n", 15);


			if (circus_meetings.good_giant == 1)
			{
				system("cls");
				printprint("Вы находите «доброго великана», но это было слишком быстро, поэтому вероятнее это он вас нашёл.\nВы продолжительное время общяетесь с ним.\nон предлагает поиграть в крестики нолики на деньги\n1) Согласиться (-20 от денег)\n2) Отказаться\n", 15);
				if (choice(2) == 1)
				{
					if (_player_.money >= 20)
					{
						switch (krestiki())
						{
						case 1:
							system("cls");
							printf("Вы победили!\n(+20 к золоту)\n");
							_player_.money += 20;
							system("pause");
							break;

						case 3:
							system("cls");
							printf("Ничья!\n");
							system("pause");
							break;

						case 5:
							system("cls");
							printf("«добрый великан» победили!\n(-20 от золота)\n");
							_player_.money -= 20;
							system("pause");
							break;

						default:
							system("cls");
							printf("\nswitch error: Bonk_2_3_3() krestiki()\n");
							system("pause");
							break;
						}
					}
				}
				system("cls");
				printprint("Вы расходитесь на хорошей ноте.\n(+2 к харизме и +2 к репутации в цирке (пообщался с дргуом))\n", 15);
				_player_.charisma += 2;
				circus_reputation += 2;
				system("pause");
				system("cls");
				meetings_2_3_3 += 1;
			}

			if (circus_meetings.dresser == 1)
			{
				system("cls");
				printprint("Вы находите костюмера и продолжительное время общяетесь с ним.\nон предлагает сделать Вам волкоподобный костюм за небольшую плату.\n1) Согласиться (-20 от денег)\n2) Отказаться\n", 15);
				printstat(_player_, money); printf("\n");
				if (choice(2) == 1)
				{
					if (_player_.money >= 20)
					{
						system("cls");
						printprint("Вы будто волка в овечьей шкуре... То есть наоборот... То есть... Неважно\n(+10 к волкоподобности, -20 от денег)\n", 15);
						system("pause");
						auf += 10;
						_player_.money -= 20;
					}
					else
					{
						printprint("У вас не хватает денег, можете взять в долг.\n1) Да\n2) Нет\n", 15);
						if (choice(2) == 1)
						{
							system("cls");
							printprint("Вы будто волка в овечьей шкуре... То есть наоборот... То есть... Неважно\n(+10 к волкоподобности, -20 от денег, -2 от репутации в цирке)\n", 15);
							system("pause");
							auf += 10;
							_player_.money -= 20;
							circus_reputation -= 2;
						}
					}
				}
				system("cls");
				printprint("Вы расходитесь на хорошей ноте.\n(+2 к харизме и +2 к репутации в цирке (пообщался с дргуом))\n", 15);
				_player_.charisma += 2;
				circus_reputation += 2;
				system("pause");
				system("cls");
				meetings_2_3_3 += 1;
			}

			if (meetings_2_3_3 <= 0)
				printprint("У вас нету знакомых, а незнакомцев отпугивает репутация цирковго волка.\n", 15);

			sh_continue = 1;
			break;

		case 2:
			system("cls");
			if (mirror == 1)
			{
				printprint("Это необычное зеркало, Вам сложно отвести взгляд от него.\n1) Взглянуть на «Я». [Характеристики]\n2) Долго смотреть на «Я»", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					printstats(_player_);
					system("pause");
					break;

				case 2:
					system("cls");
					printprint("Вы долго смотрите в зеркало...\n", 15);

					SetConsoleTextAttribute(circ, 4);
					printprint("П\bп\bПо\bО\bок\bК\bка\bА\bа «\b#\b«Я\bя\bЯ»\b#\b» н\bН\bне\bЕ\bе п\bП\bпо\bО\bос\bС\bсм\bМ\bмо\bО\bот\bТ\bтр\bР\bре\bЕ\bел\bЛ\bло\bО\bо н\bН\bна\bА\bа в\bВ\bва\bА\bас\bС\bс в\bВ\bв о\bО\bот\bТ\bтв\bВ\bве\bЕ\bет\bТ\bт...\n", 9);
					system("pause");
					SetConsoleTextAttribute(circ, 7);

					char real_class_2_3[50];
					strcpy_s(real_class_2_3, _player_.p_class);
					strcpy_s(_player_.p_class, "Ты");
					fight(_player_);
					strcpy_s(_player_.p_class, real_class_2_3);
					_player_.health = 0;
					death();

					break;

				default:
					printf("\nswitch error: second clown_2_3_2 case2\n");
					system("pause");
					break;
				}

			}
			printprint("У вас нету зеркала, но его вероятно можно найти в кабинете антрепренёра.\n", 15);
			system("pause");
			break;

		case 3:
			system("cls");
			printprint("Вы репетировали весь оставшийся день.\n(+2 к харизме,+2 к волкоподобности)\n", 15);
			_player_.charisma += 2;
			auf++;
			system("pause");
			sh_continue = 1;
			break;

		case 4:
			system("cls");
			event_progulka_2_3();
			sh_continue = 1;
			break;
		default:
			printf("\nswitch error: second clown_2_3_2\n");
			system("pause");
			break;
		}
	} while (sh_continue == 0);

	system("cls");
	printprint("Наступает день циркового представления.\n", 15);
	system("pause");

	oddity_event_2_3();

}

void shapitmaster_2_3_4_1()
{
	printf("\nИгра в раннем доступе\nПриобретите игру и начните играть — примите участие в ее развитии.\nПримечание: данная игра в раннем доступе находится на стадии разработки.\nОна может измениться в будущем, а может остаться в текущем состоянии,\nтак что, если Вам не по вкусу то, что игра может предложить сейчас,\nрекомендуем дождаться её дальнейшего развития.\n");
	system("pause");
}

void sprechstalmeister_2_3_4_2()
{
	printf("\nИгра в раннем доступе\nПриобретите игру и начните играть — примите участие в ее развитии.\nПримечание: данная игра в раннем доступе находится на стадии разработки.\nОна может измениться в будущем, а может остаться в текущем состоянии,\nтак что, если Вам не по вкусу то, что игра может предложить сейчас,\nрекомендуем дождаться её дальнейшего развития.\n");
	system("pause");
}


// Третья 1/3 комплекта концовки
// Противостояние антогонисту
void final_fight_2_3()
{
	system("cls");

	Player Boss_stage1;
	Boss_stage1.max_health = 38.f;
	Boss_stage1.health = 38.f;
	Boss_stage1.strength = 5;
	Boss_stage1.defense = 4;
	strcpy_s(Boss_stage1.p_class, "Антрепренёр");
	strcpy_s(Boss_stage1.p_weapon, "Кулаки");


	Player Boss_stage2;
	Boss_stage2.max_health = 60.f;
	Boss_stage2.health = 60.f;
	Boss_stage2.strength = 25;
	Boss_stage2.defense = 15;
	strcpy_s(Boss_stage2.p_class, "Волкободобный");
	strcpy_s(Boss_stage2.p_weapon, "Острые ногти");


	Player Boss_stage3;
	Boss_stage3.max_health = 90.f;
	Boss_stage3.health = 90.f;
	Boss_stage3.strength = 30;
	Boss_stage3.defense = 25;
	strcpy_s(Boss_stage3.p_class, "Альфа волкоподобный");
	strcpy_s(Boss_stage3.p_weapon, "Острые когти");

	switch (hero_2_3)
	{
	case defender:
		system("cls");
		printprint("Антрепренёр: «Я ждал тебя».\n", 15);
		system("pause");
		fight(Boss_stage1);
		printprint("Антрепренёр: «Не удивительно, что ты решил работать охранником».\n", 15);
		system("pause");
		fight(Boss_stage1);
		printprint("Антрепренёр: «Не удивительно, что ты решил работать охранником».\n", 15);
		system("pause");
		fight(Boss_stage1);

		printprint("(Благословление погибших: +20 к добру, +10 к макс. здоровью, +10 к защите)\n", 15);
		_player_.kind_evil += 10;
		_player_.max_health += 10;
		_player_.health += 10;
		_player_.defense += 10;
		system("pause");
		system("cls");
		printprint("Антрепренёр так и остался в форме огронмого волка.\nЭто не помешало окружающим людям критиковать Вас за то, что Вы лешили их работы.\n", 15);
		system("cls");
		printprint("С вас хватит этого цирка.\n", 15);
		system("pause");
		ending_2_3(1);
		break;
	case clown:
		fight(Boss_stage1);
		printprint("Антрепренёр покрывается шерстью.\n", 15);
		system("pause");
		fight(Boss_stage2);
		printprint("Перед вами уже не человек, а четвероногий монстр.\n", 15);
		system("pause");
		fight(Boss_stage3);
		printprint("(Благословление погибших: +20 к добру, +10 к макс. здоровью, +10 к защите)\n", 15);
		_player_.kind_evil += 10;
		_player_.max_health += 10;
		_player_.health += 10;
		_player_.defense += 10;
		system("pause");
		system("cls");
		ending_2_3(5);
		break;

	case wolf:

		fight(Boss_stage1);
		printprint("Антрепренёр покрывается шерстью.\n", 15);
		system("pause");
		fight(Boss_stage2);
		printprint("Антрепренёр «Я – альфа-волк, высшее суще…»\nВы: «То есть предрелиз - волка? Может тогда попозже зайти?»\nАнтрепренёр не оценил шутки.\n", 15);
		system("pause");
		fight(Boss_stage3);
		printprint("(Благословление погибших: +20 к добру, +10 к макс. здоровью, +10 к защите)\n", 15);
		_player_.kind_evil += 10;
		_player_.max_health += 10;
		_player_.health += 10;
		_player_.defense += 10;
		system("pause");
		system("cls");
		ending_2_3(5);
		break;

	case shapimaster:
		break;
	case sprechstalmeister:
		break;

	default:


		break; //бой общего типа.
	}
}
/*
1. охранник
2. шестёрка
3. босс цирка
4. конкурент -
5. победа босса
6. примкнуть как генерал князя цирка
*/
void ending_2_3(int story_code)
{
	system("cls");
	switch (story_code)
	{
	case 1:
		printprint("Вы решаете, что ни за что не вернётесь туда. Но куда тогда идти дальше?\n1) Домой [Конец игры]\n2) Попробовать другой способ заработка.\n", 15);
		if (choice(2) == 1)
		{
			system("cls");
			printprint("Вы решаете вернутся домой, где в страхе доживаете свою жизнь.\n", 15);
			system("pause");
			printstats(_player_);
			death();
		}
		else
		{
			system("cls");
			printprint("Вы решаете продолжить приключения.\n", 15);
			system("pause");
			Begining();
		}
		break;

	case 2:
		printprint("Теперь Вы часто сопровождаете антрепренёра.\nВ какой-то момент Вам было поручено выносить большие мешки из его кабинета.\nВам показалось, что он наконец начал убирать свой кбинет. Но Вам показалось.\nВещей в кабинете меньше не становилось...\n", 15);
		system("pause");
		system("cls");
		printprint("Так прошло много лет, Вам стали известны бесчисленные ужасные деяния антрепренёра.\nОднако всё, что Вы могли сделать - повиноваться и надеяться не стать содержимым одного из мешков.\n", 15);
		system("pause");
		system("cls");
		death();
		break;

	case 3:
		printprint("Вы заняли роль антрепренёра ", 15);
		if (_player_.kind_evil > 0)
		{
			printprint("и на протяжении многих лет цирк процветал.\n(+2000 к деньгам (зарплата как антрепренёра))\n", 15);
			_player_.money += 2000;
			system("pause");
			system("cls");
			printprint("Возможно стоит попробовать что-то ещё?\n1) Да.\n2) Нет.\n", 15);
			if (choice(2) == 1)
			{
				system("cls");
				printprint("Вы покидаете цирк и отправляетесь на поиски приключений.\n", 15);
				system("pause");
				system("cls");
				Begining();
			}
			system("cls");
			printprint("Вы остаётесь антрепренёром до самого конца.\n(+0 к деньгам(конец игры ведь уже наступил))\n", 15);
			system("pause");
			system("cls");
			printstats(_player_);
			death();
		}

		printprint("и на протяжении многих лет цирк был под вашей тиранией.\n(+30000 к деньгам (зарплата как антрепренёра + сборы с персонала))\n", 15);
		_player_.money += 30000;
		system("pause");
		system("cls");
		printprint("Возможно стоит попробовать что-то ещё?\n1) Да.\n2) Нет.\n", 15);
		if (choice(2) == 1)
		{
			system("cls");
			printprint("Вы покидаете цирк и отправляетесь на поиски приключений.\n", 15);
			system("pause");
			system("cls");
			Begining();
		}
		system("cls");
		printprint("Вы остаётесь антрепренёром до самого конца.\n(+0 к деньгам(конец игры ведь уже наступил))\n", 15);
		system("pause");
		system("cls");
		printstats(_player_);
		death();

		break;

	case 4:
		break;

	case 5:
		printprint("Вы победили циркового тирана.\n1) Взять на себя бразды правления цирком\n2) Выбрать другой путь.\n3) Закончить с приключениями.\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			ending_2_3(3);
			break;
		case 2:
			system("cls");
			Begining();
			break;
		case 3:
			system("cls");
			printstats(_player_);
			death();
			break;
		default:
			printf("\nswitch error: \n");
			system("pause");
			break;
		}

		break;

	case 6:
		printprint("Вы становетесь полноценным волкоподобным.\n(Ваша класс теперь «Волкоподобный»)\nБыло:\n", 15);
		printstats(_player_);
		printprint("\nСтало:\n", 15);
		_player_.max_health += 30;
		_player_.health += 30;
		_player_.strength += 30;
		_player_.defense += 10;
		_player_.max_stamina += 40;
		_player_.stamina += 40;
		_player_.kind_evil -= 10;
		_player_.charisma = +15;
		strcpy_s(_player_.p_class, "Волкоподобный");
		printstats(_player_);
		system("pause");
		system("cls");

		printprint("Антрепренёр рад новому сородичу и отпускает вас.\n1) Домой [Конец игры]\n2) Попробовать другой способ заработка.\n", 15);
		if (choice(2) == 1)
		{
			system("cls");
			printprint("Вы решаете вернутся домой, где в страхе доживаете свою жизнь.\n", 15);
			system("pause");
			printstats(_player_);
			death();
		}
		else
		{
			system("cls");
			printprint("Вы решаете продолжить приключения.\n", 15);
			system("pause");
			Begining();
		}

		break;

	default:
		printf("\nswitch error: ending_2_3()\n");
		system("pause");
		break;
	}
}