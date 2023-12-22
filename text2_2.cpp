#include <iostream>
#include <Windows.h>
#include "func2.h"
#include "func3.h"
#include "NecroGame.h"
#include "Opening.h"
#include "fight.h"
#include "Krestiki.h"

extern Player _player_;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
extern Player Necromancer;
extern Player Berserk;
extern bool WasAcademy;

bool textNecroPractise1_2NOTtriedRessurect = true;
bool textNecroPractise1_4FirstTime = true;
bool textNecroPractise1_4FoundSecretDoor = false;
bool wasInPodval = false;
bool Zombie = false;
bool Kovka1 = true;
bool Kovka2 = true;
int AmountOfСoffinsChecked = 0;
int Coffin1 = 1;
int Coffin2 = 1;
int Coffin3 = 1;
int Coffin4 = 1;

//чтобы избежать ставить более глубокие ветви выше корня
void text2_2_1();
void text2_2_2();
void textNecroPractise();
void textNecroPractise1();
void textNecroPractise1_double();
void textNecroPractise1_1();
void textNecroPractise1_2();
void textNecroPractise1_2_double();
void textNecroPractise1_3();
void textNecroPractise1_4();
void textNecroPractise1_4_5();
void textNecroPractiseOut();
void tunnel();
void tunnel_2();
void ending2_1();
void textNecroPractise2();
void textNecroPractise3();
void letstryanother();
void aftermath();
void Graduation();

void text2_2()
{
	WasAcademy = true;
	printprint("В Дебрянский государственный Некротехнологическиий университет оказалось довольно легко поступить.\nПохоже что на рынке труда и в правду дефицит Некромантов.\n\n", 15);

	printprint("Вы пришли на пару по Некрологии. Трехсотлетний преподователь уже начал лекцию.\n\n",15);
	printprint("1) Спать\n",15);
	printprint("2) Слушать\n",15);

	switch (choice(2))
	{
	case 1:
		text2_2_1();
		break;
	case 2:
		text2_2_2();
		break;
	default:
		printf("\ndefault. check text2_2()");
	}
}

void text2_2_1()
{
	system("cls");
	printprint("Вы уснули мертвым сном.\n", 15);
	Sleep(1000);
	printprint("Вас воскресили.\n", 15);
	Sleep(1000);
	printprint("Добро пожаловать в вашу новую жизнь безмозглого зомби. Почему-то вы не заметили изменений.\n", 15);
	death();
}

void text2_2_2()
{
	system("cls");
	printprint("Лекция оказалось очень интересной! Вы изучили новое заклинание \"Воскресить нежить\". Смерть больше не преграда. +5 iq\n", 15);
	_player_.intelligence += 5;
	system("pause");
	textNecroPractise();
}

void textNecroPractise()
{
	system("cls");
	printprint("Следущая занятие - практика по Некронализу. К несчастью вы забыли все свои мертвые тела дома.\n\n", 15);
	printprint("1) Спуститься в гробницу и взять мертвых оттуда\n", 15);
	printprint("2) Попытаться выдать своего друга наркомана за зомби\n", 15);
	printprint("3) Убить кого нибудь\n", 15);
	switch (choice(3))
	{
	case 1: textNecroPractise1(); break;
	case 2: textNecroPractise2(); break;
	case 3: textNecroPractise3(); break;
	default: printf("\ndefault\ncheck textNecroPractize\n");
	}
}

void textNecroPractise1()
{
	system("cls");
	if (!wasInPodval)
	{
		printprint("Вы спустились в гробницу. Здесь очень темно. \nВот что вы видите: \n\n\n", 15);
		Sleep(1000);

		printprint("1) Атаковать\n", 15);
		printprint("2) Использовать заклинание \"Воскресить нежить\"\n", 15);
		printprint("3) Зажечь факел\n", 15);
		printprint("4) Поискать выключатель\n", 15);

		switch (choice(4))
		{
		case 1: textNecroPractise1_1(); break;
		case 2: textNecroPractise1_2(); break;
		case 3: textNecroPractise1_3(); break;
		case 4: textNecroPractise1_4(); break;
		default: printf("\ndefault\ncheck textNecroPractise1\n");
		}
	}
	else
	{
		printprint("Вы уже там были.\n\n", 15);
		system("pause");
		textNecroPractise();
	}
	
}
void textNecroPractise1_double()
{
	wasInPodval = true;
	printprint("Вы в гробнице. Здесь очень темно. \nВот что вы видите: \n\n\n", 15);
	Sleep(1000);

	printprint("1) Атаковать\n", 15);
	printprint("2) Использовать заклинание \"Воскресить нежить\"\n", 15);
	printprint("3) Зажечь факел\n", 15);
	printprint("4) Поискать выключатель\n", 15);

	switch (choice(4))
	{
	case 1: textNecroPractise1_1(); break;
	case 2: 
		if (textNecroPractise1_2NOTtriedRessurect)
			textNecroPractise1_2();
		else
			textNecroPractise1_2_double();
		break;
	case 3: textNecroPractise1_3(); break;
	case 4: textNecroPractise1_4(); break;
	default: printf("\ndefault\ncheck textNecroPractise1_double\n");
	}
}

void textNecroPractise1_1()
{
	system("cls");
	printprint("Вы замахнулись со всей силы и ударили. Что то упало и разбилось. Вы надеетесь это не что то ценное. Ваша рука болит.\n-5 iq, - 1 hp\n", 15);
	_player_.intelligence -= 5;
	_player_.health -= 1;
	printstat(_player_, health);
	printf("\n");
	if (_player_.health <= 0)
		death();
	textNecroPractise1_double();
}

void textNecroPractise1_2()
{
	system("cls");
	printprint("Вы использовали \"Воскресить нежить\". На секунду вам показалось, что в темноте что-то шевельнулось.\nНичего не случилось.\n", 15);
	textNecroPractise1_2NOTtriedRessurect = false;
	textNecroPractise1_double();
}

void textNecroPractise1_2_double()
{
	system("cls");
	printprint("Вы уже это пробовали.\n", 15);
	textNecroPractise1_double();
}

void textNecroPractise1_3()
{
	system("cls");
	printprint("Вы не знаете этого заклинания.\n", 15);
	textNecroPractise1_double();
}

int required_int = 95;

void textNecroPractise1_4()
{
	if (textNecroPractise1_4FirstTime)
	{
		system("cls");
		printprint("Вы шарите рукой по стене пытаясь найти выключатель и стараясь не думать о пыли, грязи и насекомых\n", 15);
		printprint("сидевших на этой стене веками. Наконец, у вас получается и старые лампочки загораются с характерным звуком.\n\n", 15);
	}
	textNecroPractise1_4FirstTime = false;
	printprint("Вы в гробнице. На полу стоят четыре гроба. У дальней стены также находится стол.\n\n", 15);

	printprint("1) Осмотреть первый гроб\n", 15);
	printprint("2) Осмотреть второй гроб\n", 15);
	printprint("3) Осмотреть третий гроб\n", 15);
	printprint("4) Осмотреть четвертый гроб\n", 15);
	printprint("5) Осмотреть стол\n", 15);
	printprint("6) Осмотреться\n", 15);
	printprint("7) Осмотреть себя\n", 15);
	printprint("8) Осмотреть стену\n", 15);
	printprint("9) Осмотреть наковальню\n", 15);

	switch (choice(9))
	{
	case 1:
		system("cls");
		printprint("Вы приоткрыли крышку первого гроба. Похоже, внутри только пепел.\n", 15);
		AmountOfСoffinsChecked += Coffin1;
		Coffin1 = 0;
		if (AmountOfСoffinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 2:
		system("cls");
		printprint("Вы приоткрыли крышку второго гроба. Странно, но внутри только пепел.\n", 15);
		AmountOfСoffinsChecked += Coffin2;
		Coffin2 = 0;
		if (AmountOfСoffinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 3:
		system("cls");
		printprint("Вы приоткрыли крышку третьего гроба. Внутри что-то напоминающее пепел.\n", 15);
		AmountOfСoffinsChecked += Coffin3;
		Coffin3 = 0;
		if (AmountOfСoffinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 4:
		system("cls");
		printprint("Вы приоткрыли крышку четвертого гроба. А там... невероятно... это же... \nпепел.\n", 25);
		AmountOfСoffinsChecked += Coffin4;
		Coffin4 = 0;
		if (AmountOfСoffinsChecked >= 4)
			textNecroPractiseOut();
		else
			textNecroPractise1_4();
		break;
	case 5: 
		textNecroPractise1_4_5();
		break;
	case 6:
		system("cls");
		printprint("ну...\n", 35);
		textNecroPractise1_4();
		break;
	case 7:
		system("cls");
		printprint("Вы измзаны в пыли, копоти, и чём-то мертвом, как и подобает студенту.\n", 15);
		printstats(_player_);
		printf("\n");
		textNecroPractise1_4();
		break;
	case 8:
		system("cls");
		printprint("Вы осмотрели стену. На полу явно заметны следы от открывания двери, а между кирпичами есть толстая щель,\n",15);
		printprint("образующая вытянутый полукруг. Очевидно, здесь есть потайная дверь.\n", 15);
		if (!textNecroPractise1_4FoundSecretDoor)
			required_int -= 5;
		textNecroPractise1_4FoundSecretDoor = true;
		textNecroPractise1_4();
		break;
	case 9:
		system("cls");
		if (Kovka1)
		{
			printprint("Ковать?\n\n1) Давай\n2) Не хочу\n", 15);
			switch (choice(2))
			{
			case 1:
				enchantment(_player_);
				printf("\n");
				printstat(_player_, strength);
				printf("\n");
				Kovka1 = false;
				textNecroPractise1_4();
				break;
			case 2:
				system("cls");
				textNecroPractise1_4();
				break;
			}
		}
		else
		{
			printprint("Наковальня себя истощила.\n", 15);
			textNecroPractise1_4();
		}
		break;
	default:
		printf("\ndefault check textNecroPractise1_4()");
	}
}

void textNecroPractise1_4_5()
{
	system("cls");
	printprint("Вы осмотрели стол. На нем лежало письмо заведующего гробницей.\nСреди огромного количества мата вы находите отчеты о поставках мертвецов.\nОни все из крематория.", 15);
	textNecroPractiseOut();
}

void textNecroPractiseOut()
{
	printprint("\nОчевидно, трупов вы тут не найдете.\n\n", 15);
	printprint("1) Вернуться наверх\n", 15);
	if (textNecroPractise1_4FoundSecretDoor)
		printprint("2) Пойти через старый тонель\n", 15);
	else
		printprint("2) Поискать секретные ходы\n", 15);
	printprint("3) Продолжить осматривать гробницу\n", 15);
	switch (choice(3))
	{
	case 1: 
		textNecroPractise();
		break;
	case 2: 
		if(_player_.intelligence >= required_int)
			tunnel();
		else
		{
			system("cls");
			printprint("Дверь оказалась умней. У вас не получилось найти секретный проход.\n", 15);
			textNecroPractise1_4();
		}
		break;
	case 3:
		system("cls");
		textNecroPractise1_4();
		break;
	default:
		printf("\ndefault\ncheck textNecroPractiseOut\n");
	}
}

void tunnel()
{
	system("cls");
	printprint("Вы попытались потянуть за все факела в комнате и нажать каждый кирпич в поисках кнопки активации двери.\n", 15);
	printprint("Вам уже начало казаться что ваши попытки тщетны, как вдруг вы замечаете на двери дверную ручку.\nДверь вовсе не была секретной.\n\n", 15);
	printprint("Вам открылся узкий темный тоннель. Взяв факел (а вообще то минуту назад там лампочки были) со стены, \nвы без сомнений начали в него продвигаться.\n", 15);
	printprint("Прямо за вами тоннель завалило, похоже пути назад не будет.\n\n", 15);
	printprint("Не пройдя и ста метров вы натыкаетесь на пьяного спящего \nнекроманта Петровича с бутылкой самогона - заведующего гробницей.\n", 15);
	printprint("Вы пытаетесь его разбудить, но в таком состоянии он почти как мертвый. Вас посетила идея...\n\n", 15);
	printprint("1) Идти дальше.\n", 15);
	printprint("2) Воскресить.\n", 15);

	switch (choice(2))
	{
	case 1:
		system("cls");
		printprint("Вы решили не воскрешать нежить 1 уровня.\n", 15);
		printprint("Вы упустили возможность чему то научиться. -5 iq\n", 15);
		_player_.intelligence -= 5;
		printprint("Вы пощадили человека. +5 добро.\n", 15);
		_player_.kind_evil += 5;
		tunnel_2();
		break;
	case 2:
		system("cls");
		printprint("Вы использовали \"Воскресить нежить\"...", 30);
		if (NecroGame() == 1)
		{
			system("cls");
			Zombie = true;
			printprint("Вы воскресили нежить 1 уровня! Теперь за вами следует зомби(1).\n", 15);
			printprint("Вы чему то научились и чувствуете себя умнее. + 5 iq\n", 15);
			_player_.intelligence += 5;
			printprint("Вы совершили аморальный поступок. -5 добро.\n", 15);
			_player_.kind_evil -= 5;
		}
		else 
		{
			system("cls");
			printprint("Вы решили не воскрешать нежить 1 уровня.\n", 15);
			printprint("Вы упустили возможность чему то научиться. -5 iq\n", 15);
			_player_.intelligence -= 5;
			printprint("Вы пощадили человека. +5 добро.\n", 15);
			_player_.kind_evil += 5;
		}
		tunnel_2();
		break;
	}
}
bool CornerStand = true;
bool CornerWeb = true;
bool Chest = true;

void tunnel_2()
{
	printprint("Вы пробираетесь дальше по тоннелю без особых проишествий, пока наконец не находите выход.\n", 15);
	printprint("Перед вами открылась слабо освешенная квадратная комната. В углу стоит зеркало. В другом углу стоит сундук.\n", 15);
	printprint("В третьем углу ничего нет. В следующем углу паутина. В последнем углу стоит наковальня.\n\n", 15);
	
	printprint("1) Зеркало.\n2) Сундук.\n3) Встать в угол.\n4) Убрать паутину.\n5) Ковать.\n", 15);

	switch (choice(5))
	{
	case 1:
		system("cls");
		printprint("1) Осмотреться.\n2) Атаковать.\n3) Вернуться.\n", 15);
		switch (choice(3))
		{
		case 1:
			printstats(_player_);
			system("pause");
			system("cls");
			tunnel_2();
			break;
		case 2:
			printprint("Зеркало атакует в ответ!\n", 15);
			Player enemy;
			fill_player(enemy, _player_);
			if (Zombie)
			{
				printprint("Ваш зомби бездумно атакует и наносит 15 урона. Зомби погибает.\n", 15);
				enemy.health -= 15;
			}
			Sleep(1000);
			fight(enemy);
			ending2_1();
			break;
		case 3:
			tunnel_2();
		}
		break;
	case 2:
		if (Chest)
		{
			printprint("На сундук наложен магический замок. Похоже чтобы его открыть нужно решить сложную головоломку.", 15);
			system("pause");
			if (krestiki() == 1)
			{
				printprint("Успех! В сундуке лежало оружие, абсолютно идентичное вашему, но сильнее. +5 силы\n", 15);
				_player_.strength += 5;
			}
			else
				printprint("У вас не получилось взломать сундук.", 15);
			Chest = false;
			tunnel_2();
		}
		else
		{
			printprint("Тут ничего нет.\n", 15);
			tunnel_2();
		}
		break;
	case 3:
		system("cls");
		if (CornerStand)
		{
			printprint("Вы встали в угол чтобы наказать себя за все свои злые поступки. +10 добро.\n", 15);
			_player_.kind_evil += 10;
			CornerStand = false;
			tunnel_2();
		}
		else
		{
			system("cls");
			printprint("Тут ничего нет.\n", 15);
			tunnel_2();
		}
		break;
	case 4:
		system("cls");
		if (CornerWeb)
		{
			printprint("Вы разрушили плоды чьейто усердной работы. -10 добро.\n", 15);
			_player_.kind_evil -= 10;
			CornerWeb = false;
			tunnel_2();
		}
		else
		{
			system("cls");
			printprint("Тут ничего нет.\n", 15);
			tunnel_2();
		}
		break;
	case 5:
		if (Kovka2)
		{
			printprint("Ковать?\n\n1) Давай\n2) Не хочу\n", 15);
			switch (choice(2))
			{
			case 1:
				enchantment(_player_);
				printf("\n");
				printstat(_player_, strength);
				printf("\n");
				Kovka2 = false;
				tunnel_2();
				break;
			case 2:
				system("cls");
				tunnel_2();
				break;
			}
		}
		else
		{
			system("cls");
			printprint("Наковальня себя истощила.\n", 15);
			tunnel_2();
		}
		break;
	}
}

void ending2_1()
{
	if (_player_.kind_evil > 0)
	{
		printprint("Вы победили себя.\nИ пусть вы замурованы где то глубоко под землей, вы смогли понять самого себя и сделаться намного лучше,\nа это и есть настоящее сакровище!\n", 15);
		printprint("\nКОНЕЦ!", 5);
		Sleep(2000);
		exit(0);
	}
	else
	{
		printprint("Вы победили себя.\nНо что теперь?\nВ поисках сокровища и славы, вы забрели в самое глубокое из возможных подземелий, а по пути растеряли душу.\n", 15);
		printprint("Вам остается только сожалеть о своих решениях в ожидании неизбежного конца.", 15);
		printprint("\nКОНЕЦ!", 5);
		Sleep(2000);
		exit(0);
	}
}

void textNecroPractise2()
{
	system("cls");
	printprint("Вы спускаетесь в общагу, по пути задумавшись: \"Есть ли в некроманском вузе вообще лестницы ведущие вверх?\"\n", 15);
	printprint("Зайдя в общагу перед вами встает неописуемая картина:\n\n", 15);
	Sleep(1001);
	printprint("В углу сидит ваш знакомый. Врятли он пойдет на сделку просто так.\n\n", 15);
	printprint("1) Атаковать\n2) Попытаться договориться\n", 15);

	switch (choice(2))
	{
	case 1:
		Player Narcomant;
		fill_player(Narcomant, Necromancer);
		strcpy_s(Narcomant.p_class, "Наркомант");
		Narcomant.strength += 10;
		fight(Narcomant);
		aftermath();
		break;
	case 2:
		system("cls");
		printprint("Он предлогает вам сыграть партию шахмат. Если вы выиграете он согласиться вам помочь.\nВы не грандмастер, но сыграть придется.\n", 15);
		system("pause");
		if (krestiki() == 1)
		{
			aftermath();
		}
		else
		{
			printprint("Вы проиграли, похоже некромантия все же не для вас.\n", 15);
			system("pause");
			letstryanother();
		}
	}
}

void textNecroPractise3()
{
	system("cls");
	printprint("Вы атакуете случайного студента...\n", 10);
	fight(Necromancer);
	system("cls");
	printprint("Вы победили некроманта! В бою вы чему-то научились +1 iq, +1 силы.\n", 15);
	_player_.intelligence += 1;
	_player_.strength += 1;
	printprint("Прежде чем вы смогли воскресить побежденного противника вас исключили за нападения на ученика.\n", 15);
	system("pause");
	letstryanother();
}

void letstryanother()
{
	system("cls");
	Begining();
	/*printprint("Вам всё еще нужна работа.\n\n", 15);

	printprint("1) Пойти в лес\n", 15);
	printprint("2) Пойти в цирк\n", 15);

	switch (choice(2))
	{
	case 1:
		forest(); 
		break;
	case 2:
		Circus(); 
		break;
	}*/
}

void aftermath()
{
	system("cls");
	printprint("Вы победили! Можете приступать к воскрешению.\n\n", 15);
	printprint("1) Воскресить\n", 15);
	printprint("2) А знаете, как то это слишком уже.. Я пожалуй другую работу поищу.\n", 15);

	switch (choice(2))
	{
	case 1:
		system("cls");
		printprint("Вы использовали \"Воскресить нежить\"...", 30);
		if (NecroGame() == 1)
		{
			system("cls");
			Zombie = true;
			printprint("Вы воскресили нежить 1 уровня! Теперь за вами следует зомби(1).\n", 15);
			printprint("Вы чему то научились и чувствуете себя умнее. + 5 iq\n", 15);
			_player_.intelligence += 5;
			printprint("Вы совершили аморальный поступок. -5 добро.\n", 15);
			_player_.kind_evil -= 5;
			printprint("Отлично! Теперь можно продолжить учебу.\n", 15);
			system("pause");
			Graduation();
		}
		else
		{
			system("cls");
			printprint("Вы решили не воскрешать нежить 1 уровня.\n", 15);
			printprint("Вы упустили возможность чему то научиться. -5 iq\n", 15);
			_player_.intelligence -= 5;
			printprint("Вы пощадили человека. +5 добро.\n", 15);
			_player_.kind_evil += 5;
			printprint("Что ж вы за некромант то такой?\nПохоже некромантия это не для вас...\n", 15);
			system("pause");
			letstryanother();
		}
		break;
	case 2:
		system("cls");
		printprint("Похоже некромантия это не для вас...\n", 10);
		letstryanother();
		break;
	}
}

void Graduation()
{
	system("cls");
	printprint("Хотя погодите, я и так все умею! Зачем мне это образование?\n\n1)И вправду (пойти убить дракона)\n2) Одуматься и вернуться на пары.\n", 15);
	switch (choice(2))
	{
	case 1:
		printprint("Вы решаете что мир у ваших ног, а потому сразу беретесь за самое трудное и опасное из возможных испытаний - пещера дракона...\n\n", 15);
		Player Dragon;
		fill_player(Dragon, Berserk);
		strcpy_s(Dragon.p_class, "Дракон");
		Dragon.max_health = 200;
		Dragon.health = 200;
		Dragon.defense = 20;
		if (Zombie)
		{
			printprint("Ваш зомби бездумно атакует и наносит 15 урона. Зомби погибает.\n", 15);
			Dragon.health -= 15;
		}
		fight(Dragon);
		system("cls");
		printprint("Вы победили! Все золото дракона теперь ваше! Вот это приключение, а не ваши образования!\n\n", 15);
		printprint("КОНЕЦ!", 5);
		Sleep(2000);
		exit(0);
		break; //бедный брэйк :(
	case 2:
		printprint("Пускай с небольшим опозданием вы вернулись на некронализ...\n\n", 15);
		if (_player_.intelligence >= 100)
		{
			printprint("Ваша учеба прошла отлично и вы смогли устроиться на высокооплачиваемую должность в крупную компанию ритуальных услуг.\n", 15);
			printprint("Пусть и эпического приключения у вас не получилось, \nоднако порой, стабильность - это и есть настоящее сокровище.\n\n", 15);
		}
		else
		{
			printprint("Ваша учеба прошла ужасно и вы смогли устроиться только в захудалую сельскую компанию ритуальных услуг.\n", 15);
			printprint("Пусть эпического приключения у вас не получилось и вы не стали по настоящему образованым некромантом, \nоднако порой, стабильность - это и есть настоящее сокровище.\n\n", 15);
		}
		printprint("КОНЕЦ!", 5);
		Sleep(2000);
		exit(0);
		break;
	}
}