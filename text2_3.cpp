#include <iostream>
#include <windows.h>
#include "func2.h"
#include "func3.h"
#include "Opening.h"
#include "fight.h"
#include "Krestiki.h"

HANDLE circ = GetStdHandle(STD_OUTPUT_HANDLE);


// ��� �� ����� � �����.
bool was_at_circus = 0;

#pragma region circus_variables

// ��������� ���������� � �������� �����.
int circus_reputation = 0;

// ���������������.
int auf = 0;

// �������� � �������� �����.
struct meetings_in_the_circus
{
	bool antrepreneur = 0, good_giant = 0, dresser = 0;
} circus_meetings;


// ���� ������ � �����.
enum who_are_you
{
	defender = 1, clown, wolf, shapimaster, sprechstalmeister
};
// clown, wolf, shapimaster, sprechstalmeister
who_are_you hero_2_3;

#pragma endregion

#pragma region items
//�������� ������������� ����������
bool sharp_2_3 = 0;
//��������� �������. ���������������, ��� ��� 0, ��� ���� � ������.
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
		printprint("�� ��� ��������� �������� � �����, ���������� �� ����������, ������ ��� ����������� ����� ����� �������.\n", 15);
		system("pause");
		system("cls");
		Begining();
	}
	printprint("����� �� ������, �� ���������� �� ��������. ����� ����� � �������� �������� ��� ��������, ��� ��������� � ���.\n��� ��������, ��� ����� ��������� � �� ���������.\n", 15);
	printprint("\n1) ����������.\n2) �� �������. (����������� ����� ������ ������ ����������)\n", 15);
	switch (choice(2))
	{
	case 1:
		beginning_of_the_circus_2_3_0();
		break;
	case 2:
		system("cls");
		printprint("�� �� ��������� ��������� � ���� �� ��� �������� ��������� - ��������� �������������.\n", 15);
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
	printprint("���� �� ���������� ��������� ��������� ���.\n", 15);
	if (_player_.charisma < 3)
		printprint("���� ������� �������� ��������� �����, ��� �� �� �������� ������� ����������� ������ ��������������.\n��� ������ � ���������.\n", 15);
	else
	{
		printprint("���� ������� �������� ��������� �����, ��� �� ������ ���������������. �� �������������� ����� � ���������.\n", 15);
		circus_reputation++;
	}
	system("pause");
	system("cls");
	printprint("�� ���� �� ���������� �� ���������� �������� ������.\n", 15);
		switch (rand() % (3) + 1)
		{
		case 1:
			printprint("�� ������ ���� ���������� ���������� ������ � ������ �� ����������� �� ����� ����.\n(� ������������ � ����� ������ ������ �� ���������)\n", 15);
			break;

		case 2:
			printprint("�� ��������� �� �������� ������� ������. ( +1 � ���������������)\n", 15);
			auf++;
			break;

		case 3:
			printprint("�� ������� ��� ������� ����������� � ����.\n\n1) �������������� � �������� ����.\n2) �� �����������\n", 15);
			switch (choice(2))
			{
			case 1:
				system("cls");
				if (_player_.strength < 15)
				{
					printprint("� ��� �� ��������� ����������? �� ������ ��������� �����. �� ������������, �� ������ ��� ���� �������.\n(+1 � ����, -1 � ��������� � �����)\n", 15);
					_player_.strength++;
					circus_reputation--;
				}
				else if (_player_.strength >= 15 && _player_.strength < 40)
					printprint("�� �������� ������� ���������. ��� �� �������, ���� ������ ������ ��, ��� �� ����������.\n", 15);
				else if (_player_.strength >= 40)
				{
					printprint("�� ������ ���������� �����. ���-�� ������ ������ �������� ��� �� �����.\n", 15);
					printprint("����������� ������� ��� �������� � ������������. �� �������� ���������� ������� ������� � ������ ������ ����������.\n", 15);
					printprint("(+2 � ��������� � �����, ����� ��������: ������� �������, -1 �� �������� ��������)\n", 15);
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
					printprint("��� ���� �������� �������. ��� ��� ���������� ���� ��� ������ ������������� ����������.\n(+3 � ����������)\n", 15);
					_player_.intelligence += 3;
				}
				else
				{
					printprint("�� ������ �� ���������� ���� �����������. ��������, � ������� ��� ��������������� ��� �������.\n(-1 �� �������)\n", 15);
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
	printprint("������� �� �������� � ������� ����������� �����. ��������� ������� �������� ����� �������� � ����������� �� ������ �\n", 5);
	printprint("����� ������� �������� ������. ������ ��������� ���� ������� ������ �� ��������������, � �� �������� �� ����� � �����.\n\n", 5);
	for (int wait = 0, loot_table = 1, loot_bunch = 1; wait <= 3;)
	{
		printprint("1) ��������� ������� ����.\n2) ��������� ���������� ����.\n3) ������� � ���������� �����.\n4) �����\n5) ����� �� ��������.\n", 5);
		// switch floor 1
		switch (choice(5))
		{
			// ������� ����
		case 1:
			system("cls");
			_player_.kind_evil -= 2;
			if (loot_table > 0)
			{
				printprint("��� ���������� ������� ����. ����� ���� ����� ������ �� ��������� ������� ������.\n", 15);
				printprint("� ����� �� �������� ���������� �����. ��� ������� ������������� ����� � ������.\n����� ����� �������� ���������. ���� � ������ �� ���, �� ��� ����������� ��� ������.\n(+2 � ���������������, ������ � ��� ���� �������� �������)\n", 15);
				auf += 2;
				mirror = 1;
				loot_table = 0;
				wait++;
			}
			else
				printprint("� ����� ���� ������, ��� ������ �� ������ ��������.\n", 15);
			system("pause");
			break;
			// ���� �� ����
		case 2:
			_player_.kind_evil -= 2;
			system("cls");
			if (loot_bunch > 0)
			{
				printprint("�� ������������ ���� � ��������� ����. ��� ������������ �� �������� �� ������ �������.\n�� ��� ��������� �������.\n", 15);
				system("pause");
				Player cockroach;
				cockroach.max_health = 200.f;
				cockroach.health = 200.f;
				cockroach.strength = 1;
				cockroach.defense = 2;
				cockroach.intelligence = 1200;
				strcpy_s(cockroach.p_class, "�������");
				strcpy_s(cockroach.p_weapon, "�����");
				fight(cockroach);
				wait++;
				loot_bunch = 0;
			}
			else
			{
				printprint("� ���� ����� ���� ������, ��� ������ �� ������ ��������. ���� � �� ����� ��� �� ����.\n", 15);
				system("pause");
			}
			break;
			// ����� � ����� (r.i.p.) => ���������� �����.
		case 3:
			system("cls");
			printprint("�� ��������� � ���������� �����.\n", 15);
			printprint("�� ������� ��������� � ������� � ������� ������� ������ ��� ������ ��������� ������. �����...\n", 15);
			printprint("\n1) ����������� �������� ��� ������.\n2) ������.\n", 15);
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
			// ��������(+1 � wait)
		case 4:
			system("cls");
			printprint("�� �������������� ��������� �����...\n\n", 15);
			_player_.kind_evil += 1;
			wait++;
			break;
			// �� ���������.
		case 5:
			system("cls");
			printprint("�� �������� �� ��������.\n", 15);
			switch (wait)
			{
				// +1 wait
			case 0:
				printprint("������ �� �������������� �������...\n", 15);
				printprint("�� ��������� �������� ����� � �������:\n������ ������, ������ � ���� ������� ������� � �������� �� �������. �� ������������� � �������.\n\n", 15);
				wait++;
				break;

				// meet and +2 wait or +1 wait
			case 1:
				printprint("���� �������� ������ � �� �������, �� ���������� �������. �� ����������� � ����.\n\n1) ����������� ������� ��������.\n2) �������.\n", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					if (_player_.charisma < 5)
					{
						printprint("�� ������� �������. ������ ������ ������ ����...\n", 15);
						wait++;
						break;
					}
					printprint("� ��� ��������� ������� �������� � ���������. �� - �������� �������� ������. (����� ��������: ��������)\n", 15);
					circus_meetings.dresser = 1;
					wait += 2;
					break;
				case 2:
					printprint("�� �������. ������ �������� ����.\n", 15);
					wait++;
					break;
				default:
					printf("\nswitch error: meet_with_antrepreneur_2_3_0() case5 case1\n");
					system("pause");
					break;
				}
				break;

				// ������ ������-������ � +1 wait, ���� �� ������� +1 wait
			case 2:
				printprint("�� ���������� �� ���������� �������� ������... ", 15);
				if (circus_meetings.good_giant == 1)
				{
					printprint("�� ������ ������ � ���������� �������� ��������.\n�� ������ ��� � ���� ����������...\n(+1 � ��������� � �����, +1 � ����)\n", 15);
					circus_reputation++;
					_player_.strength++;
					_player_.kind_evil += 2;
					system("pause");
					wait++;
					break;
				}
				printprint("������ �� ����c����� � �� ������������� � �������.\n", 15);
				wait++;
				system("pause");
				break;

				// ���������� � ����� � �������.
			case 3:
				printprint("�� ���������� ������� ������� � �������� �������.\n�����: ������������, ������� �� ���������� ���� �����, ��� �� ����� �� ����� ��������.\n", 15);
				printprint("\n1) ��.\n2) ���, ��� ��� ��� ���.\n", 15);
				switch (choice(2))
				{
				case 1:
					_player_.kind_evil -= 2;
					system("cls");
					printprint("�� ����������� ������� � �������, ��������� ��� �����.\n������� ������ ��������� ���...\n", 15);
					SetConsoleTextAttribute(circ, 4);
					printprint("\n(-\b+\b-5\b6\b5 �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b� �\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b�)\n", 15);
					SetConsoleTextAttribute(circ, 7);
					circus_reputation -= 5;
					system("pause");
					break;
				case 2:
					system("cls");
					printprint("�����: ������ � ��� ����������, �� ���������. �����, �������\n������� ���������� ��� ������.\n", 15);
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
	printprint("� ������� ������� ������� � ������� �� ������� ����.\n", 15);
	printprint("�����: ��� ���� ������ ����� �� ����� � ������������. � - ���������� ������� �����.\n", 15);
	system("pause");
	dialog_with_antrepreneur();
}

void dialog_with_antrepreneur()
{
	was_at_circus = 1;
	system("cls");
	printprint("����� ���� ����� �� ������� �� ������, ��� ���� �������,\n�������� ������������, ��� ����� �� �������,\n", 15);
	printprint("����� �� ������, � ������ �� ������, ������� ������ ������ �� ������,\n", 15);
	printprint("� � ����� ������������� ����� ������� � �� � ��������.\n\n", 15);
	system("pause");
	system("cls");
	printprint("����������: ���� ���� ��� �������, ��������� ������?�\n", 15);
	printprint("���������� ������, ��������� � ���������� ����� � �������, ����� ����� ��� ������ ������.\n", 15);
	system("pause");
	system("cls");
	printprint("����������: ����� �� ����� � ������� ������, �� � ��� ��� ��� ������� ���� ��������.\n��������� ���� � �������, ��� ������ ����� �� ���������... \n", 15);
	printprint("����������� � ����� ����, ������ ���� ���������� ��� ��� ���� � ����� ������ �������.\n", 15);
	system("pause");
	system("cls");
	printprint("���������� ���������� ��� ��������� ��������: ��������; �����; �� ������ �������, �� ����� ����.\n", 15);
	printprint("\n1) ������� ���������. [���� �������� � ����� ����]\n2) ������� ������.\n3) ������� ������� (�����).\n4) ���������� �� ������ � �����. [�� �� ������� ���� ��������]\n", 15);

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
		/*case 4: 4) �� ������ ���� �� ����� ������, � ������������ ��������� ������.\n
			printprint("����������: ���� ���.\n", 15);
			Sleep(1500);
			printprint("���� �� ������������ ����, � ������� ���� �� ����� ������������� ����,\n", 15);
			printprint("������ ����� �������, � ������� � ������������� ������������� - �������������������,\n��� �� ������ ����� �������������� - ���� �� ���� �� ��������� �������.", 15);
			printprint("������ ���������� ����� ������ �����,\n��� � ������ ���������� ������ �� ������ ����������� ������� ��������.\n", 15);
			printprint("\n1) ����������������� (������ D20 �� �������� ������).\n2) ������������.\n3) �������� ��� ��������.\n", 15);
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
				printprint("1) ������� ���������.\n2) ������� ������.\n3) ������� ������� (�����).\n4) �����������������\n5) ������������.\n6) ���������� �� ������ � �����.\n", 10);
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
		printprint("�� ������� ����� �� ����������, �� ��������������� ����.\n�� ���� ������ �� ����� ���� � ����� ��� ��� ������ ����� �������� ������� ����� �����...\n", 15);
		hero_2_3 = defender;
		system("pause");
		system("cls");

		defender_2_3_1();
		break;
	case 2:
		printprint("������ ��� ��� ���� ���������� ��� ��� �� �����, � ����� ��� ��������.\n", 15);
		hero_2_3 = clown;
		system("pause");
		system("cls");

		clown_2_3_2();
		break;
	case 3:
		printprint("��� ���������, ���� � ����� �� ���������. �� �������� ����� ������ ����� �����������, ��� ������� �����������.\n", 15);
		printprint("������ ���������, ���� ������ � ���� ���� ������� ��� �����. ��� �� ���� ���� ���������, ����� ��� � �� ���� �����?..\n", 15);
		hero_2_3 = wolf;
		system("pause");
		system("cls");

		Bonk_2_3_3();
		break;
	case 4:
		printprint("�� ���� ������ ��������, ���� ������. ���� �������� ����� ����� �� ���� ������.\n", 15);
		hero_2_3 = shapimaster;
		system("pause");
		system("cls");

		shapitmaster_2_3_4_1();
		break;
	case 5:
		printprint("���� ������� ������, �� ������ ������� ����� ���������...\n", 15);
		hero_2_3 = sprechstalmeister;
		system("pause");
		system("cls");

		sprechstalmeister_2_3_4_2();
		break;
	case 6:
		printprint("�� ��������� ���� � ������� ����������� ���-�� ���.\n", 15);
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
//��������� �������� �������� ������ ������� - �������� �����
void defender_2_3_1()
{
	Player cockroach;
	cockroach.max_health = 200.f;
	cockroach.health = 200.f;
	cockroach.strength = 1;
	cockroach.defense = 2;
	cockroach.intelligence = 1200;
	strcpy_s(cockroach.p_class, "�������");
	strcpy_s(cockroach.p_weapon, "�����");

	system("cls");
	printprint("�� ��� �� ��� ���������:\n�������� ���� ����������� �� ���������. �� �����-�� ������� ������� �������� ��� �� �����...\n", 15);
	printprint("�� ������������� ����� �������,\n����� � ���� ������ �������� ������ ������� - ������ ��� ������������ ����.\n", 15);
	system("pause");
	system("cls");
	fight(cockroach);
	system("cls");
	printprint("�� ��� ����� ��������� ��� ����.\n", 15);
	system("pause");
	fight(cockroach);
	system("cls");
	printprint("�������������� �� �������������, ��� ��� �� �������, � �����-����������. �� ��������� ��� ���� ������...\n�� � �����, �� �� �����������, ��� ������� ���-��, ��� ���������� ���������� ���.\n��� �� ��� ��������� ������������� �� ��� �����?\n", 15);
	system("pause");
	strcpy_s(cockroach.p_class, "�����");
	fight(cockroach);
	system("cls");
	printprint("...", 40);
	printprint("\b\b\b�������� ��������� ������. ����� - ���������� ���������� �������� �����, � ������� ������� �� ����� ������ ������\n�������� �� ��� ����� �����. ���������� - �� ��������, �� � ����� - �� ��� ������.\n", 15);

	bool run_later_2_3 = 0;
	printprint("\n1) ������ �� �����.\n2) ������������� �����\n3) ��� ���������� � ������ �� ����� ���� ������.\n", 5);
	if (choice(3) == 1)
	{
		system("cls");
		printprint("�� ������ �� �����.\n", 15);
		system("pause");
		ending_2_3(1);
	}
	else
		run_later_2_3 = 1;

	system("cls");
	printprint("...", 40);
	printprint("\b\b\b������ ��� ���� ���� �� ��������� ������ ��������� �������� �����������.\n�� ����� ������ ��� � ����� ����� �� ���������� ��� ��������� ������.\n����� ���� ������ ��������� � ��������� �� ���� ��������� � ��������.\n����� ������ �� ����� ����� �� ������, ����� �� ��������� ���� ����.\n", 15);
	system("pause");
	system("cls");

	if (run_later_2_3 == 0)
		printprint("����� ������ �� ������������� �� �������� ������ ������ ����������, � �������� �����������\n������������ ������� ���� ���� ��� ����� �������� �� ����� �����.\n", 15);
	else
	{
		printprint("�� �������, ��� ������� ������� ��� ������ �� �����.\n", 15);
		system("pause");
			switch (rand() % (2) + 1)
			{
			case 1:
				system("cls");
				printprint("����� �� ��� ��������� � ������ �� ����� ��� ����������, ��� ���-�� ����� � ������.\n�������� � ������ �� ������� ��������� ��������� ��� ���, � �� ���������� ������ ���,\n���� ����� - ����������. \n", 15);
				printprint("1) ������������, ��� ������ �� ���������� � ���� ������.\n2) ��������� ���� � ���������� ���� ������ ��������.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					printprint("���������� ������������ ������ � ���� �������.\n������ ��� �� ������ ���������. � ��������� ��������� ��������� ���� ��������� ��� �����.\n�� ���������, ��� �� ����������� ���� � ���� ���.\n", 15);
					printprint("(-30 �� ��������)\n", 15);
					_player_.health -= 30;
					system("pause");
					final_fight_2_3();
				}
				else
				{
					system("cls");
					printprint("�� ��������� ��� ��������� ����� � ������ ��� ����� � ������ �� �����.\n", 15);
					ending_2_3(1);
				}
				system("pause");
				break;

			case 2:
				system("cls");
				printprint("�� �������� �� ��������� �����, �� ���������, ��� ��� ������� ��������� ����.\n������������ �� ���������, ��� ��� ������� ������������� ����������.\n", 15);
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
	printprint("�� ��������� ����������� ����� �� ���������� ������ ���.\n���� ����� ������� �� ��� �� �������� �������� ������������� ������...\n", 15);
	printprint("��������, ���� �� �� ����� ���������� ����������� ��� ����, ����� �� ���� � ������ �����,\n�� ������ �� �������� �� ����� ������ ��������.\n", 15);
	system("pause");
	system("cls");
	death();
}

void clown_2_3_2()
{
	if (_player_.charisma < 10)
	{
		printprint("�� ������ ��������� �� ���������, �� ������� ��������������� ��� ����������,\n��� ���� �� ������� ������� ������ ����� ���������.", 15);
		printprint("�� �������� ����� �� ���������� ���� �����,\n�� ��������� ���������� ��������� ������.\n(+2 � �������)\n", 15);
		_player_.charisma += 2;
		system("pause");
		system("cls");
	}
	printprint("������ ���� ���� �������� ����� ������ ������� ������. ��� ������ ��������� �������� ������� ����� ��������.\n���� �� �����������, ���� ������� �� ������ ��� �������.\n", 15);
	system("pause");
	system("cls");
	printprint("������� �������� ��� ����� �����! ���� ��� ��� ������ �������, � ��� 10 �����,\n����� �������� ��� ��� �� �������� ��������� ��������� ����. �� �������� �� �����.\n", 15);
	printprint("\n1) ������������ ������, ������� ������ � �������� �����������. [�����]\n2) ���������������. [�������]\n3) �������� ����. [����]\n", 15);
	switch (choice(3))
	{
	case 1:
		_player_.kind_evil -= 2;
		system("cls");
		printprint("��: ����������� ��� �� ����������� ����� �������.\n", 15);
		switch (rand() % (3) + 1)
		{
		case 1:
			printprint("���� ��� �����������\n(+3 � ��������� � �����, +2 � �������, +2 �����, ��������: +15 � �������)\n", 15);
			circus_reputation += 3;
			_player_.charisma += 2;
			_player_.luck += 2;
			_player_.money += 15;
			break;

		case 2:
			printprint("������ ���� �������, �� �� ���� ��. �� �������� ��� ���� ����\n(+1 � �������, ��������: +5 � �������)\n", 15);
			_player_.charisma += 1;
			_player_.money += 5;
			break;

		case 3:
			printprint("� ����� ��� ���� ������.\n���������� �� ����� � ���� ������ ������, � ���� ��� �� ������ ��� ������, ��� � ����,\n����� ������ ���� �� ���� ������.\n(-3 �� ��������� � �����)\n", 15);
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
		printprint("�� ����������� ������� ���������� ������.\n", 15);
		if (_player_.charisma >= 5) // ������� ���� +2, 2 ������� ��� ����� � ������ ��������.
		{
			printprint("���� ������ ������� �����.\n(+1 � ��������� � �����, +1 � �������, ��������: +10 � �������)\n", 15);
			circus_reputation++;
			_player_.charisma++;
			_player_.money += 10;
			system("pause");
			break;
		}
		printprint("���� �������� �� ����� �������.\n", 15);
		system("pause");
		break;

	case 3:
		system("cls");
		printprint("�� ������� ����������� ������� ����.\n", 15);
		if (_player_.strength < 15)
		{
			printprint("� ��� �� ����� ����������� ����������. �� ������� ���������� ��� ��� ����� ����������� ������.\n(+1 � ��������� � �����, ��������: +5 � �������)\n", 15);
			circus_reputation++;
			_player_.money += 5;
		}
		else if (_player_.strength >= 15)
		{
			printprint("� ��� ����� ����������� ����������. ������� ������ ������� ��� �����.\n(+2 � ��������� � �����, ��������: +10 � �������)\n", 15);
			circus_reputation += 2;
			_player_.money += 10;
		}
		else if (_player_.strength >= 40)
		{
			printprint("�� ����������� ���� ������, ������������ �� ����: ������������� �������� �\n���������� ������, ����������� ��������� � ������ �� �����. ", 15);
			printprint("������� � ��������� ��������� ���� �����������\n(+4 � ��������� � �����, +1 � �������, ��������: +20 � �������)\n", 15);
			circus_reputation += 4;
			_player_.charisma++;
			_player_.money += 20;
			if (circus_meetings.good_giant == 0)
			{
				printprint("����� ����������� � ��� �������� ����������� ������� � ������ ������� ��� �� �����.\n", 15);
				printprint("�� �������� ��� � ������������. ������� �������� ���������� ������� ������� � ������ ������ ����������.\n", 15);
				printprint("(����� ��������: ������� �������, -1 �� �������� ��������)\n", 15);
				_player_.health--;
				_player_.kind_evil += 1;
				if (_player_.health <= 0)
					death();
				circus_meetings.good_giant = 1;
			}
			else
			{
				printprint("����� ����������� � ��� �������� ������� ������� � ������ ������� ��� �� �����.\n�� ������ ��� � �����������-������������� �������� ������������� �������� �����������.\n(-1 ��������(�����������), -1 �������� �� ���� ����(���������))\n", 15);
				_player_.health -= 2; // -1 �� ���� ���� ��-�� ��������
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
	printprint("(��������: +10 � �������)\n", 15);
	system("pause");
	system("cls");
	printprint("��������� ��������� ����. �� ���������� � ���������� ������ ����.\n�������� ��� �� �������� ����� ��������� ������������.\n", 15);
	_player_.health++; //������� 1 ��.
	printprint("\n1) ��������. [�������������� ��������]\n2) ���������� � ��������� ���������.\n3) ������������ [���������� �������]\n4) �������� �� ������ �����.\n", 15);
	bool sh_continue = 0;
	do
	{

		switch (choice(4))
		{
		case 1:
			system("cls");
			printprint("�� ��������� ���� ���������� ����.\n(�������� ��������� �������������)\n", 15);
			_player_.health = _player_.max_health;
			system("pause");
			sh_continue = 1;
			break;

		case 2:
			system("cls");
			if (mirror == 1)
			{
				printprint("��� ��������� �������, ��� ������ ������� ������ �� ����.\n1) ��������� �� �߻. [��������������]\n2) ����� �������� �� �߻", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					printstats(_player_);
					system("pause");
					break;

				case 2:
					system("cls");
					printprint("�� ����� �������� � �������...\n", 15);

					SetConsoleTextAttribute(circ, 4);
					printprint("�\b�\b��\b�\b��\b�\b��\b�\b� �\b#\b��\b�\b߻\b#\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b� �\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b�...\n", 9);
					system("pause");
					SetConsoleTextAttribute(circ, 7);

					char real_class_2_3[50];
					strcpy_s(real_class_2_3, _player_.p_class);
					strcpy_s(_player_.p_class, "��");
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
			printprint("� ��� ���� �������, �� ��� �������� ����� ����� � �������� �����������.\n", 15);
			system("pause");
			break;

		case 3:
			system("cls");
			printprint("�� ������������ ���� ���������� ����.\n(+2 � �������)\n", 15);
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


// ������ 1/3 ��������� ��������
void event_progulka_2_3()
{
	printprint("1) ��������� � ���� ����\n2) ���������� � ������� �����������.\n3) ���������� �� ���������� �����\n4) ����� �� �����\n5) ����� � ���.\n", 15);
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
			printprint("�������!\n� �������� �������� ����������. �� ������ ���� ����������.\n(-2 �� ��������� � �����)\n", 15);
			circus_reputation -= 3;
			system("pause");
		}
		else
		{
			printprint("�����!\n������� ����������� ����. �� � ������� ������������ ������� ���� � ����� ����� �� ����.\n", 15);
			if (sharp_2_3 == 0)
			{
				printprint("�� ��������� � ���������� �����.\n", 15);
				printprint("�� ������� ��������� � ������� � ������� ������� ������ ��� ������ ��������� ������. �����...\n", 15);
				printprint("\n1) ����������� �������� ��� ������.\n2) ������.\n", 15);
				switch (choice(2))
				{
				case 1:
					//�������� �� !
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
				printprint("(+10 � �������, ������ � ��� ���� ��������� �������)\n", 15);
				mirror = 1;
				system("pause");
				break;
			}
			printprint("(+10 � �������)\n", 15);
			system("pause");
		}
		break;

	case 3:
		printprint("�� ��������� ���� ����� ���������� ��������\n(+1 � ���������������)\n", 15);
		auf++;
		system("pause");
		break;

	case 4:
		printprint("�� ��������� �� �����.\n\n1) ������ �������� �����. [20 ������ = + 10 � ������������� ��������]\n2) ������ ������� ��������������� �����. [20 ������ = + 10 � ����.", 15);
		printf("%s", _player_.p_class_stamina);
		printprint("]\n3) ����.\n", 15);
		printstat(_player_, money);
		printf("\n");
		if (_player_.money < 20)
		{
			printprint("\n����� ����, �� �������.\n", 15);
			system("pause");
			system("cls");
			break;
		}
		while (_player_.money >= 20 and buy == 1)
		{
			system("cls");
			printprint("�� ��������� �� �����.\n\n1) ������ �������� �����. [20 ������ = + 10 � ������������� ��������]\n2) ������ ������� ��������������� �����. [20 ������ = + 10 � ����.", 15);
			printf("%s", _player_.p_class_stamina);
			printprint("]\n3) ����.\n", 15);
			printstat(_player_, money);
			switch (choice(3))
			{
			case 1:

				printprint("�� ��������� �������� ����� � ��������� ���.\n(+10 � �������� ��������, + 10 � ������������� ��������)\n", 15);
				_player_.money -= 20;
				_player_.max_health += 10;
				_player_.health += 10;
				break;

			case 2:

				printprint("�� ��������� ������� ��������������� ����� � ��������� ���.\n(+10 � �������� �������� ", 15);
				printf("�%s�", _player_.p_class_stamina);
				printprint(", +10 � ������������� �������� ", 15);
				printf("�%s�)\n", _player_.p_class_stamina);
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
		printprint("\n�� �������.\n", 15);
		system("pause");
		system("cls");
		break;

	case 5:
		system("cls");
		printprint("1) ���� ������\n2) ���������\n", 15);
		if (choice(2) == 2)
			break;
		system("cls");
		printprint("1) ���� ������\n2) ���������\n", 15);
		if (choice(2) == 2)
			break;
		system("cls");
		printprint("!) ���� ������\n2) ���������\n", 15);
		if (choice(2) == 2)
			break;
		system("cls");
		printprint("�� ���������� �� ���� ������.\n", 15);
		system("pause");
		Player wolfick;
		wolfick.max_health = 35.f;
		wolfick.health = 35.f;
		wolfick.strength = 15;
		wolfick.defense = 5;
		strcpy_s(wolfick.p_class, "����");
		strcpy_s(wolfick.p_weapon, "�����");

		Player alfa_wolfick;
		alfa_wolfick.max_health = 75.f;
		alfa_wolfick.health = 75.f;
		alfa_wolfick.strength = 25;
		alfa_wolfick.defense = 25;
		strcpy_s(alfa_wolfick.p_class, "����� ����");
		strcpy_s(alfa_wolfick.p_weapon, "������ �����");

		fight(wolfick);
		system("cls");
		printprint("��� ������������...\n", 15);
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("��� ������������...\n", 15);
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("��� ������������. � �� ������...\n", 15);
		_player_.stamina -= _player_.max_stamina / 2;
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("��� ������������. � �� ������...\n", 15);
		_player_.stamina -= _player_.max_stamina / 4;
		system("pause");

		fight(wolfick);
		system("cls");
		printprint("��� ������������, �� ������, �� ������� ����������� ��� �������...\n", 15);
		_player_.stamina = 0;
		system("pause");
		fight(alfa_wolfick);
		_player_.stamina = 0;

		system("cls");
		printprint("(+5 � ����, +8 � ����������, +10 ��������������� (������ ��� �����-������ �����))\n", 15);
		_player_.strength += 5;
		_player_.intelligence += 8;
		auf += 10;
		system("pause");
		system("cls");
		printprint("�� ��������� ����� �� ����. ������ ��������� ����� ��������� ��������� ��� ������ ����� �� �������� �������.\n��������� ��������, ������� ��� ��������� ������� �������� ��� � ������������ ����� ����� ��������� � ���.\n", 15);
		printprint("��� �������, �� ��� ��������� �����. ���� �� ������������ ��� � ���� ������������ �������� ������� ���.\n(������ �� ��������� �������)\n", 15);
		_player_.health = _player_.max_health;
		_player_.stamina = _player_.max_stamina;
		system("pause");
		system("cls");

		printprint("� �������� ������ �� ������ ���� ���� �����, ������� �� ������ ����� ��� ������.\n����� ������ ������������ �� ������� ������������� � ����.\n", 15);
		system("pause");
		break;

	default:
		printf("\nswitch error: event_progulka_2_3()\n");
		system("pause");
		break;

	}
	system("cls");
}

// ������ 1/3 ��������� ��������
// ����� ������ ����. ������ ������� ������ ����� �� ��������. 
void oddity_event_2_3()
{
	bool sh_continue = 0;
	bool cabinet = 0;

	do {
		system("cls");
		printprint("� ������ ���� � ����� ������-�� �����. �� �� ��������� �� ��� ��������� � ����������� ���������� ������ ������.\n", 15);
		printprint("��� �������������� ������������� � �� � �� �����������.\n1) ����������������.\n2) ��������� ��������� �������.\n", 15);
		switch (choice(3))
		{

		case 1:
			system("cls");
			printprint("�� ���������� ���� ������.\n", 15);
			system("pause");
			sh_continue = 1;
			break;

		case 2:
			system("cls");
			if (mirror == 1)
			{
				printprint("��� ��������� �������, ��� ������ ������� ������ �� ����.\n1) ��������� �� �߻. [��������������]\n2) ����� �������� �� �߻", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					printstats(_player_);
					system("pause");
					break;

				case 2:
					system("cls");
					printprint("�� ����� �������� � �������...\n", 15);

					SetConsoleTextAttribute(circ, 4);
					printprint("�\b�\b��\b�\b��\b�\b��\b�\b� �\b#\b��\b�\b߻\b#\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b� �\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b�...\n", 9);
					system("pause");
					SetConsoleTextAttribute(circ, 7);

					char real_class_2_3[50];
					strcpy_s(real_class_2_3, _player_.p_class);
					strcpy_s(_player_.p_class, "��");
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
			printprint("� ��� ���� �������, �� ��� �������� ����� ����� � �������� �����������.\n", 15);
			system("pause");
			break;
		case 3:
			if (cabinet == 0)
			{
				printprint("�� ���� � �������� �����������. ����� ����� ����� ����������� ������. �� ���� ����������,\n��� ��������� ������� ���������� ������� �� � �������. ������� ����������� ����.\n�� � ������� ������������ ������� ���� � ����� ����� �� ����.\n", 15);
				if (sharp_2_3 == 0)
				{
					printprint("�� ��������� � ���������� �����.\n", 15);
					printprint("�� ������� ��������� � ������� � ������� ������� ������ ��� ������ ��������� ������. �����...\n", 15);
					printprint("\n1) ����������� �������� ��� ������.\n2) ������.\n", 15);
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
					printprint("(+10 � �������, ������ � ��� ���� ��������� �������)\n", 15);
					mirror = 1;
					system("pause");
					break;
				}
				printprint("(�� ������ �� ��������)\n", 15);
				system("pause");
				system("cls");
				printprint("�� �������� ���� �� �������� ������� � ��������. ", 15);
				printprint("�� ������, ��� �� � ��� - ������ �� �����.\n", 15);
				system("pause");
				cabinet = 1;
				break;
			}
			printprint("�� ��� ���� ���.\n", 15);
			system("pause");
			break;
		}
	} while (sh_continue == 0);

	system("cls");
	printprint("������������� ����������, �� �� ��������� ������ ������� ����� ���� ��� ����� ���������,\n��� ����� �����������. ������� �������� ���� ������� ���������.\n", 15);

	int sherlok = 0;
	// ������������ �� �����
	switch (hero_2_3)
	{

	case clown:


		printprint("\n1) ������������. [�����]\n2) �������� �������������� ������. [�������]\n3) �������� ����. [����]\n", 15);

		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("��: ����������� ��� �� ����������� ����� �������.\n", 15);
			switch (rand() % (3) + 1)
			{
			case 1:
				printprint("���� ��� �����������\n(+2 � ��������� � �����, +2 � �������, +2 �����, ��������: +10 � �������)\n", 15);
				circus_reputation += 2;
				_player_.charisma += 2;
				_player_.luck += 2;
				_player_.money += 10;
				break;

			case 2:
				printprint("������ ���� �������, �� �� ���� ��.\n", 15);
				break;

			case 3:
				printprint("� ����� ��� ���� ������.\n(-3 �� ��������� � �����)\n", 15);
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
			printprint("�� ����������� ������� ���������� �����.\n", 15);
			if (_player_.charisma >= 15) // ������� ���� +2, 2 ������� ��� ����� � ������ ��������.
			{
				printprint("���� ������ ����������� �����.\n(+2 � ��������� � �����, +1 � �������, ��������: +15 � �������)\n", 15);
				circus_reputation += 2;
				_player_.charisma++;
				_player_.money += 15;
				system("pause");
				break;
			}
			printprint("���� �������� �� ����� �������. �������� ������ ������ ������������, ���� ��, ��� �������, �������� ��������.\n", 15);
			system("pause");
			break;

		case 3:
			system("cls");
			printprint("�� ������� ����������� ������� ����.\n", 15);
			if (_player_.strength < 15)
			{
				printprint("� ��� �� ����� ����������� ����������.\n(-1 � ��������� � �����)\n", 15);
				circus_reputation--;
			}
			else if (_player_.strength >= 15)
			{
				printprint("� ��� ����� ����������� ����������. ������� ������ ������� ��� �����.\n(+2 � ��������� � �����, ��������: +10 � �������)\n", 15);
				circus_reputation += 2;
				_player_.money += 10;
			}
			else if (_player_.strength >= 40)
			{
				printprint("�� � ������� ����������� ���� ������.\n�������� � ������ �������� ������, ��� �� ������ �������� �� ������.\n", 15);
				printprint("������� � ��������� ��������� ���� �����������\n(+2 � ��������� � �����, ��������: +20 � �������)\n", 15);
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
		printprint("(��������: +10 � �������)\n", 15);
		system("pause");
		system("cls");
		printprint("��������� ��������� ����. ������� ������ ���������� �����.\n", 15);

		printprint("1) �� �������� ��������\n2) ���������� ����������\n3) ���� � ���, ��� ����.\n", 15);

		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("�� ������� �� �������� ��������.\n", 15);
			printprint("������ ����� ������ ���������� ���������� ��� � ����.\n", 15);
			if (circus_reputation > 20)
			{
				printprint("�� ���������� ����� ��� ���������.\n1) �����������\n2) ����������\n", 15);
				if (choice(2) == 1)
					ending_2_3(6);
			}
			else
				if (circus_reputation > 6)
				{
					printprint("�� ���������� ��� ����� ��� ����������.\n1) �����������\n2) ����������\n", 15);
					if (choice(2) == 1)
						ending_2_3(2);
					else
					{
						system("cls");
						printprint("����������: ������ �����.\n", 15);
						printprint("� ��� �� ������� �������� ���-�� ��������� � ���������� � ������ ����� �������.\n�� �����������.\n", 15);
						death();
					}
				}
			printprint("�� ���������� ����� � ��������� � ����� �����������.\n��������� ��� � ��� ���������� �������� - ��� �� ��������������� � ������ � � ��� ���-�� �����.\n�� �����������.\n", 15);
			death();
			break;

		case 2:



			if (circus_meetings.good_giant == 1)
			{
				system("cls");
				printprint("�� �������� �������� �������� � ������ � ���� � ������������.\n����������� ��������� �������� �������. ���� �������� ��� ���� ����������\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			if (circus_meetings.dresser == 1)
			{
				system("cls");
				printprint("����� ��������� �� ������ � ���� � ������������.\n����������� ��������� � ���� ����� ����� ��� ������� ������������ ������� �����.\n���� �������� ��� ���� ����������\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			printprint("�� �������������� �������� �����.\n", 15);
			system("pause");
			sherlok += _player_.charisma / 2;

			if (sherlok > 10)
			{

				printprint("������ �� �������� �� ���� �����, ��� ���������� ��������:\n���������� - ������������� ������, ������� ������� ����� ����������.\n1) ���� � ���, ��� ��� ����.\n2) ����������� ������������� �����������.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					ending_2_3(1);
				}
				else
				{
					system("cls");
					printprint("�� �������� �����������. ����� ��������� ��� � ������� �������� �� ��������� ���.\n", 15);
					system("pause");
					final_fight_2_3();
				}
			}
			else
			{
				printprint("��� �� �������� � ������ ����, ��� ��� ���������� � �����.\n������������� � ��� ���� ��� ��������:\n1) ���� � ���, ��� ��� ����.\n2) ����������, �� ������� �������� �� ���������� ���.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					ending_2_3(1);
				}
				else
				{
					system("cls");
					printprint("�� ������� �� �������� ��������.\n", 15);
					printprint("������ ����� ������ ���������� ���������� ��� � ����.\n", 15);
					if (circus_reputation > 20)
					{
						printprint("�� ���������� ����� ��� ���������.\n1) �����������\n2) ����������\n", 15);
						if (choice(2) == 1)
							ending_2_3(6);
					}
					else
						if (circus_reputation > 6)
						{
							printprint("�� ���������� ��� ����� ��� ����������.\n1) �����������\n2) ����������\n", 15);
							if (choice(2) == 1)
								ending_2_3(2);
							else
							{
								system("cls");
								printprint("����������: ������ �����.\n", 15);
								printprint("� ��� �� ������� �������� ���-�� ��������� � ���������� � ������ ����� �������.\n�� �����������.\n", 15);
								death();
							}
						}
					printprint("�� ���������� ����� � ��������� � ����� �����������.\n��������� ��� � ��� ���������� �������� - ��� �� ��������������� � ������ � � ��� ���-�� �����.\n�� �����������.\n", 15);
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

		printprint("\n1) �� ���������������\n2) �� ���� ������� � ���������\n3) �� �����\n", 15);
		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("�� ���������� �� �������� � ���� ��������.\n", 15);

			if (auf > 25)
			{
				system("cls");
				printprint("��� ���� ��������. ����������� ��������� ��� ����� - �����, ��� ����� � �������, ������� �������.\n(+4 � ��������� � �����, ��������: +15 � �������, �����: -15 �� �����)\n", 15);
				circus_reputation += 3;
				_player_.money += 15;
				system("pause");
			}
			else if (auf > 10)
			{
				system("cls");
				printprint("���� � ��� ������, �� �� ����� ���������� ���������.\n(+1 � ��������� � �����, ��������: +5 � �������)\n", 15);
				circus_reputation++;
				_player_.money += 5;
				system("pause");
			}
			else
			{
				system("cls");
				printprint("��� ������� ���� ����, � �� ���� ����.\n(-2 �� ��������� � �����)\n", 15);
				circus_reputation -= 2;
				system("pause");
			}
			system("pause");
			break;


		case 2:
			system("cls");
			printprint("�� ��������� �������� � ���������� ���� ��������.\n(-3 �� �������, -3 �� ��������� � �����, ��������: 20)\n", 15);
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
				printprint("�� ������� ��������� ��� �������������.\n(+2 � ��������� � �����)\n", 15);
				circus_reputation += 2;

				break;

			case 2:
				printprint("�� ������ ��������� ����������� �������������\n", 15);
				break;

			case 3:
				printprint("������ � �������� ������� ����������� ���� �������.\n(-2 � ��������� � �����)\n", 15);
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
		printprint("(��������: +10 � �������)\n", 15);
		system("pause");
		system("cls");
		printprint("��������� ��������� ����. ������� ������ ���������� �����.\n", 15);

		printprint("1) �� �������� ��������\n2) ���������� ����������\n3) ���� � ���, ��� ����.\n", 15);

		switch (choice(3))
		{
		case 1:
			system("cls");
			printprint("�� ������� �� �������� ��������.\n", 15);
			printprint("������ ����� ������ ���������� ���������� ��� � ����.\n", 15);
			if (auf > 20)
			{
				printprint("�� ���������� ����� ��� ���������.\n1) �����������\n2) ����������\n", 15);
				if (choice(2) == 1)
					ending_2_3(6);
			}
			else
				if (circus_reputation > 6 or auf > 10)
				{
					printprint("�� ���������� ��� ����� ��� ����������.\n1) �����������\n2) ����������\n", 15);
					if (choice(2) == 1)
						ending_2_3(2);
					else
					{
						system("cls");
						printprint("����������: ������ �����.\n", 15);
						printprint("� ��� �� ������� �������� ���-�� ��������� � ���������� � ������ ����� �������.\n�� �����������.\n", 15);
						death();
					}
				}

			printprint("�� ���������� ����� � ��������� � ����� �����������.\n��������� ��� ��� ������ �������� - ��� �� ��������������� � ������ � � ��� ���-�� �����.\n�� �����������.\n", 15);
			death();
			break;

		case 2:


			if (circus_meetings.good_giant == 1)
			{
				system("cls");
				printprint("�� �������� �������� �������� � ������ � ���� � ������������.\n����������� ��������� �������� �������. ���� �������� ��� ���� ����������\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			if (circus_meetings.dresser == 1)
			{
				system("cls");
				printprint("����� ��������� �� ������ � ���� � ������������.\n����������� ��������� � ���� ����� ����� ��� ������� ������������ ������� �����.\n���� �������� ��� ���� ����������\n", 15);
				system("pause");
				sherlok += 5;
				system("cls");
			}

			printprint("�� �������������� �������� �����.\n", 15);
			system("pause");
			sherlok += _player_.charisma / 2;

			if (sherlok > 10)
			{

				printprint("������ �� �������� ��� �� ���� �����, ��� ���������� ��������:\n���������� - ������������� ������, ������� ������� ����� ����������.\n1) ���� � ���, ��� ��� ����.\n2) ����������� ������������� �����������.\n", 15);
				if (choice(2) == 1)
				{
					system("cls");
					ending_2_3(1);
				}
				else
				{
					system("cls");
					printprint("�� �������� �����������. ����� ��������� ��� � ������� �������� �� ��������� ���.\n", 15);
					system("pause");
					final_fight_2_3();
				}
			}
			else
				if (auf > 20)
				{
					printprint("����� ������� ������ �� ������ � ����������� - ��������������.\n�� � �������� ���������� ������.\n1) ���� � ���, ��� ��� ����.\n2) ����������� ������������� �����������.\n", 15);
					if (choice(2) == 1)
					{
						system("cls");
						ending_2_3(1);
					}
					else
					{
						system("cls");
						printprint("�� �������� �����������. ����� ��������� ��� � ������� �������� �� ��������� ���.\n", 15);
						system("pause");
						final_fight_2_3();
					}
				}
				else
				{
					printprint("��� �� �������� � ������ ����, ��� ��� ���������� � �����.\n������������� � ��� ���� ��� ��������:\n1) ���� � ���, ��� ��� ����.\n2) ����������, �� ������� �������� �� ���������� ���.\n", 15);
					if (choice(2) == 1)
					{
						system("cls");
						ending_2_3(1);
					}
					else
					{
						system("cls");
						printprint("�� ������� �� �������� ��������.\n", 15);
						printprint("������ ����� ������ ���������� ���������� ��� � ����.\n", 15);
						if (auf > 20)
						{
							printprint("�� ���������� ����� ��� ���������.\n1) �����������\n2) ����������\n", 15);
							if (choice(2) == 1)
								ending_2_3(6);
						}
						else
							if (circus_reputation > 6 or auf > 10)
							{
								printprint("�� ���������� ��� ����� ��� ����������.\n1) �����������\n2) ����������\n", 15);
								if (choice(2) == 1)
									ending_2_3(2);
								else
								{
									system("cls");
									printprint("����������: ������ �����.\n", 15);
									printprint("� ��� �� ������� �������� ���-�� ��������� � ���������� � ������ ����� �������.\n�� �����������.\n", 15);
									death();
								}
							}

						printprint("�� ���������� ����� � ��������� � ����� �����������.\n��������� ��� ��� ������ �������� - ��� �� ��������������� � ������ � � ��� ���-�� �����.\n�� �����������.\n", 15);
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
	printprint("(-1 � �������, +5 � ���������������)\n", 15);
	_player_.charisma--;
	auf += 5;
	system("pause");
	system("cls");
	printprint("��� �� ������������� ��� �� �������, � ������� �� ���������������, �� ����� �� ���� ���� �����.\n������ �������� �����, �� ������ ������������������ � ���� ���� �������� ����.\n� ������ ������ �� ������� ���� ��� �����, �� ��� ��� ���� �������� �����, ��� ����� ����������.\n", 15);
	printprint("���� �������� ������� ��������, ���� �������� ���� ������������ ��������.\n���������� �� ������� � ���� ������ �������� � �����,\n��� ����������� ��������� � ������ ������� �� ������������ - ������ ���.\n", 15);
	system("pause");
	system("cls");
	printprint("��� ������� � ������������� � ������ �� ��� ����. ����, ��������,\n�� ������ ����-�� ������������ ��� ���� ������� ���� �����������. �� ��������� �� �����,\n� ����� ����� ���������� ��� ����, ����� ��������������� ������ �����.\n", 15);
	printprint("����� ������� ���������� ������������ ������� ��� �� ��������� ������ ����. ���� ��� �� ������ �������� ��� ��������.\n", 15);
	printprint("\n1) �������� �� ������\n2) ����� � ������� �����������\n3) ����� � ���������� ��� ����\n4) ������������ [�����������]\n5) ������ � ���������� ��� ����\n6) ��������� � ������� �����������\n7) ���������� �� ������\n", 15);
	bool x17 = false, x26 = false, x35 = false, x4 = false;
	//������ ��� ����� = 0 ���� ��� bool? ������ ��� ������� ��� ����������? ��� ����� ���� � ������ ��������� � 354 ���� ���� � 17:26?
	do
	{
		switch (choice(7))
		{
		case 1:
			if (!x17)
			{
				system("cls");
				printprint("�� ����������� �� �������� ������� ������. ", 15);
				if (circus_meetings.good_giant) //bool ���� �� �����
				{
					printprint("����� ��� ���� � ������� �������. �� ������������� � ������ ����� �������.\n�� �� �������� ������ ������, �� �� ������ �������� �����.\n", 15);
					system("pause");
					system("cls");
				}
				else
				{
					printprint("�� ������������ � ���� � ���� ������.\n(-2 ���������������)\n", 15);
					auf -= 2;
					system("pause");
					system("cls");
				}
				x17 = true;
				break;
			}
			system("cls");
			printprint("�� ��� ����������� ������.\n", 15);
			system("pause");
			system("cls");
			break;

		case 2:
			if (!x26)
			{

				system("cls");
				printprint("�� ��������� � ������� � ������� �����������.\n����������: ������� �� ��� �� ������ ��������� ������� ��������.\n������, ��� ����� ��� ���� ���� � ������� �������� ����� �� ���� ��������� ������.\n���������� ��� ��� ��������� �������, � ���, ��� ����� ������ ���� �����.\n������ �� ��� �����?\n", 15);

				x26 = true;
				break;
			}
			system("cls");
			printprint("�� ��� ���� � ��������.\n", 15);
			system("pause");
			system("cls");
			break;

		case 3:
			if (!x35)
			{

				system("cls");
				printprint("�� ��������� � ����������� ��� ������� ����.\n������� ������ ����� ����� ������, �������, ����� ��� � �� ����� � ���������.\n", 15);
				printprint("(+2 � ���������������)\n", 15);
				auf += 2;
				if (mirror == 1)
				{

					printprint("� ������� �� ����� �������� �� ������ ������� ��������� �������,\n������� ����� � �������� �����������.\n1) �������.\n2) ������� ���-�� ���.\n", 15);
					if (choice(2) == 1)
					{
						printprint("��� ��������� �������, ��� ������ ������� ������ �� ����.\n1) ��������� �� �߻. [��������������]\n2) ����� �������� �� �߻", 15);
						switch (choice(2))
						{
						case 1:
							system("cls");
							printstats(_player_);
							system("pause");
							break;

						case 2:
							system("cls");
							printprint("�� ����� �������� � �������...\n", 15);

							SetConsoleTextAttribute(circ, 4);
							printprint("�\b�\b��\b�\b��\b�\b��\b�\b� �\b#\b��\b�\b߻\b#\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b� �\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b�...\n", 9);
							system("pause");
							SetConsoleTextAttribute(circ, 7);

							char real_class_2_3[50];
							strcpy_s(real_class_2_3, _player_.p_class);
							strcpy_s(_player_.p_class, "��");
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
			printprint("�� ��� ���� � ������ ����.\n", 15);
			system("pause");
			system("cls");
			break;

		case 4:
			printprint("�������� ��������� ����. ����� ����� �� �����������.\n� ��� �������� ������������ � �������, ��� � ������� ����� �����������.\n", 15);
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
				printprint("�� ��������� � ����������� ��� ������� ����.\n������� ������ ����� ����� ������, �������, ����� ��� � �� ����� � ���������.\n", 15);
				printprint("(+2 � ���������������)\n", 15);
				auf += 2;
				if (mirror == 1)
				{

					printprint("� ������� �� ����� �������� �� ������ ������� ��������� �������,\n������� ����� � �������� �����������.\n1) �������.\n2) ������� ���-�� ���.\n", 15);
					if (choice(2) == 1)
					{
						printprint("��� ��������� �������, ��� ������ ������� ������ �� ����.\n1) ��������� �� �߻. [��������������]\n2) ����� �������� �� �߻", 15);
						switch (choice(2))
						{
						case 1:
							system("cls");
							printstats(_player_);
							system("pause");
							break;

						case 2:
							system("cls");
							printprint("�� ����� �������� � �������...\n", 15);

							SetConsoleTextAttribute(circ, 4);
							printprint("�\b�\b��\b�\b��\b�\b��\b�\b� �\b#\b��\b�\b߻\b#\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b� �\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b�...\n", 9);
							system("pause");
							SetConsoleTextAttribute(circ, 7);

							char real_class_2_3[50];
							strcpy_s(real_class_2_3, _player_.p_class);
							strcpy_s(_player_.p_class, "��");
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
			printprint("�� ��� ���� � ������ ����.\n", 15);
			system("pause");
			system("cls");
			break;

		case 6:
			if (!x26)
			{

				system("cls");
				printprint("�� ��������� � ������� �����������. ���������� ��������� ��� �����. \n����������: ������� �� ��� ������� � ����, ��� ������������ ����.\n���������� ������� ��� ��� ��� ����� � ��������� �����.\n������ � ���� � �������� ���� �����?\n(+4 � ���������������, +1 � ��������� � �����)\n", 15);
				auf += 4;
				circus_reputation++;
				x26 = true;
				break;
			}
			system("cls");
			printprint("�� ��� ���� � ��������.\n", 15);
			system("pause");
			system("cls");
			break;

		case 7:
			if (!x17)
			{

				system("cls");
				printprint("�� ����������� �� �������� ������� ������.\n", 15);
				if (circus_meetings.good_giant == 1)
				{
					printprint("����� ��� ���� � ������� �������. �� �� �������� ������ ������, �� �� ������ �������� �����.\n� ��� �� ��������, ���� ����� ������� �����, ��� ���� �����\n(+2 � ���������������)\n", 15);
					auf += 2;
					system("pause");
					system("cls");
				}
				else
				{
					printprint("������� ������ ����������� ������� �� ���, �� ������ �� ��������� �������� � �������� ��������� ��� � ����.\n(+1 � ���������������)\n", 15);
					auf += 1;
					system("pause");
					system("cls");
				}
				x17 = true;
				break;
			}
			system("cls");
			printprint("�� ��� ����������� ������.\n", 15);
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
	printprint("�� ���������� ����� � ���� ��������� ������ ����� � ������.\n", 15);
	printprint("�������� ���� ������� ����� ���� ����� ���������� ����.\n\n1) �� ���������������\n2) �� ���� ������� � ���������\n3) �� �����\n", 15);
	switch (choice(3))
	{
	case 1:
		system("cls");
		printprint("�� ���������� �� �������� � ���� ��������, ���������� �������� �� ������ ����� ������ �����...\n", 15);

		if (auf > 10)
		{
			system("cls");
			printprint("��� ���� ��������. ����������� ��������� ��� ����� - �� �������� ����������� ����� ��������.\n(+3 � ��������� � �����, ��������: +15 � �������)\n", 15);
			circus_reputation += 3;
			_player_.money += 15;
			system("pause");
		}
		else if (auf > 5)
		{
			system("cls");
			printprint("�� �� ���� ���� ���������.\n(+1 � ��������� � �����, ��������: +5 � �������)\n", 15);
			circus_reputation++;
			_player_.money += 5;
			system("pause");
		}
		else
		{
			system("cls");
			printprint("�� � ������� ��������������!\n(-2 �� ��������� � �����)\n", 15);
			circus_reputation -= 2;
			system("pause");
		}
		system("pause");
		break;


	case 2:
		system("cls");
		printprint("�� ��������� �������� � ���������� ���� ��������.\n(-3 �� �������, -3 �� ��������� � �����, ��������: 20)\n", 15);
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
			printprint("�� �������� ����� � ������� ������, �� �������� ������� �����.\n(+2 � ��������� � �����)\n", 15);
			circus_reputation += 2;

			break;

		case 2:
			printprint("�� ������ ��������� ����������� �������������\n", 15);
			break;

		case 3:
			printprint("�� �������� ����� � ������� ������, �� ������ ��� ������� ���� ��������, � ������ ���� ��� ���� �����.\n(-2 � ��������� � �����)\n", 15);
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
	printprint("(��������: +10 � �������)\n", 15);
	system("pause");
	system("cls");
	printprint("��������� ��������� ����. �� ���������� � ���������� ������ ����.\n�������� ��� �� �������� ����� ��������� ������������.\n", 15);
	_player_.health++; //������� 1 ��.
	printprint("\n1) ����� ���� �������.\n2) ���������� � ��������� ���������.\n3) ������������ [���������� �������]\n4) �������� �� ������ �����.\n", 15);

	bool sh_continue = 0;
	int meetings_2_3_3 = 0;
	do
	{

		switch (choice(4))
		{
		case 1:
			system("cls");
			printprint("�� ����� � ��� ���������� ���� ���������� ����.\n", 15);


			if (circus_meetings.good_giant == 1)
			{
				system("cls");
				printprint("�� �������� �������� ��������, �� ��� ���� ������� ������, ������� ��������� ��� �� ��� �����.\n�� ��������������� ����� ��������� � ���.\n�� ���������� �������� � �������� ������ �� ������\n1) ����������� (-20 �� �����)\n2) ����������\n", 15);
				if (choice(2) == 1)
				{
					if (_player_.money >= 20)
					{
						switch (krestiki())
						{
						case 1:
							system("cls");
							printf("�� ��������!\n(+20 � ������)\n");
							_player_.money += 20;
							system("pause");
							break;

						case 3:
							system("cls");
							printf("�����!\n");
							system("pause");
							break;

						case 5:
							system("cls");
							printf("������� ������� ��������!\n(-20 �� ������)\n");
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
				printprint("�� ����������� �� ������� ����.\n(+2 � ������� � +2 � ��������� � ����� (��������� � ������))\n", 15);
				_player_.charisma += 2;
				circus_reputation += 2;
				system("pause");
				system("cls");
				meetings_2_3_3 += 1;
			}

			if (circus_meetings.dresser == 1)
			{
				system("cls");
				printprint("�� �������� ��������� � ��������������� ����� ��������� � ���.\n�� ���������� ������� ��� ������������� ������ �� ��������� �����.\n1) ����������� (-20 �� �����)\n2) ����������\n", 15);
				printstat(_player_, money); printf("\n");
				if (choice(2) == 1)
				{
					if (_player_.money >= 20)
					{
						system("cls");
						printprint("�� ����� ����� � ������� �����... �� ���� ��������... �� ����... �������\n(+10 � ���������������, -20 �� �����)\n", 15);
						system("pause");
						auf += 10;
						_player_.money -= 20;
					}
					else
					{
						printprint("� ��� �� ������� �����, ������ ����� � ����.\n1) ��\n2) ���\n", 15);
						if (choice(2) == 1)
						{
							system("cls");
							printprint("�� ����� ����� � ������� �����... �� ���� ��������... �� ����... �������\n(+10 � ���������������, -20 �� �����, -2 �� ��������� � �����)\n", 15);
							system("pause");
							auf += 10;
							_player_.money -= 20;
							circus_reputation -= 2;
						}
					}
				}
				system("cls");
				printprint("�� ����������� �� ������� ����.\n(+2 � ������� � +2 � ��������� � ����� (��������� � ������))\n", 15);
				_player_.charisma += 2;
				circus_reputation += 2;
				system("pause");
				system("cls");
				meetings_2_3_3 += 1;
			}

			if (meetings_2_3_3 <= 0)
				printprint("� ��� ���� ��������, � ����������� ���������� ��������� �������� �����.\n", 15);

			sh_continue = 1;
			break;

		case 2:
			system("cls");
			if (mirror == 1)
			{
				printprint("��� ��������� �������, ��� ������ ������� ������ �� ����.\n1) ��������� �� �߻. [��������������]\n2) ����� �������� �� �߻", 15);
				switch (choice(2))
				{
				case 1:
					system("cls");
					printstats(_player_);
					system("pause");
					break;

				case 2:
					system("cls");
					printprint("�� ����� �������� � �������...\n", 15);

					SetConsoleTextAttribute(circ, 4);
					printprint("�\b�\b��\b�\b��\b�\b��\b�\b� �\b#\b��\b�\b߻\b#\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b��\b�\b� �\b�\b��\b�\b� �\b�\b��\b�\b��\b�\b� �\b�\b� �\b�\b��\b�\b��\b�\b��\b�\b��\b�\b�...\n", 9);
					system("pause");
					SetConsoleTextAttribute(circ, 7);

					char real_class_2_3[50];
					strcpy_s(real_class_2_3, _player_.p_class);
					strcpy_s(_player_.p_class, "��");
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
			printprint("� ��� ���� �������, �� ��� �������� ����� ����� � �������� �����������.\n", 15);
			system("pause");
			break;

		case 3:
			system("cls");
			printprint("�� ������������ ���� ���������� ����.\n(+2 � �������,+2 � ���������������)\n", 15);
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
	printprint("��������� ���� ��������� �������������.\n", 15);
	system("pause");

	oddity_event_2_3();

}

void shapitmaster_2_3_4_1()
{
	printf("\n���� � ������ �������\n����������� ���� � ������� ������ � ������� ������� � �� ��������.\n����������: ������ ���� � ������ ������� ��������� �� ������ ����������.\n��� ����� ���������� � �������, � ����� �������� � ������� ���������,\n��� ���, ���� ��� �� �� ����� ��, ��� ���� ����� ���������� ������,\n����������� ��������� � ����������� ��������.\n");
	system("pause");
}

void sprechstalmeister_2_3_4_2()
{
	printf("\n���� � ������ �������\n����������� ���� � ������� ������ � ������� ������� � �� ��������.\n����������: ������ ���� � ������ ������� ��������� �� ������ ����������.\n��� ����� ���������� � �������, � ����� �������� � ������� ���������,\n��� ���, ���� ��� �� �� ����� ��, ��� ���� ����� ���������� ������,\n����������� ��������� � ����������� ��������.\n");
	system("pause");
}


// ������ 1/3 ��������� ��������
// �������������� �����������
void final_fight_2_3()
{
	system("cls");

	Player Boss_stage1;
	Boss_stage1.max_health = 38.f;
	Boss_stage1.health = 38.f;
	Boss_stage1.strength = 5;
	Boss_stage1.defense = 4;
	strcpy_s(Boss_stage1.p_class, "����������");
	strcpy_s(Boss_stage1.p_weapon, "������");


	Player Boss_stage2;
	Boss_stage2.max_health = 60.f;
	Boss_stage2.health = 60.f;
	Boss_stage2.strength = 25;
	Boss_stage2.defense = 15;
	strcpy_s(Boss_stage2.p_class, "�������������");
	strcpy_s(Boss_stage2.p_weapon, "������ �����");


	Player Boss_stage3;
	Boss_stage3.max_health = 90.f;
	Boss_stage3.health = 90.f;
	Boss_stage3.strength = 30;
	Boss_stage3.defense = 25;
	strcpy_s(Boss_stage3.p_class, "����� �������������");
	strcpy_s(Boss_stage3.p_weapon, "������ �����");

	switch (hero_2_3)
	{
	case defender:
		system("cls");
		printprint("����������: �� ���� �����.\n", 15);
		system("pause");
		fight(Boss_stage1);
		printprint("����������: ��� �����������, ��� �� ����� �������� ����������.\n", 15);
		system("pause");
		fight(Boss_stage1);
		printprint("����������: ��� �����������, ��� �� ����� �������� ����������.\n", 15);
		system("pause");
		fight(Boss_stage1);

		printprint("(�������������� ��������: +20 � �����, +10 � ����. ��������, +10 � ������)\n", 15);
		_player_.kind_evil += 10;
		_player_.max_health += 10;
		_player_.health += 10;
		_player_.defense += 10;
		system("pause");
		system("cls");
		printprint("���������� ��� � ������� � ����� ��������� �����.\n��� �� �������� ���������� ����� ����������� ��� �� ��, ��� �� ������ �� ������.\n", 15);
		system("cls");
		printprint("� ��� ������ ����� �����.\n", 15);
		system("pause");
		ending_2_3(1);
		break;
	case clown:
		fight(Boss_stage1);
		printprint("���������� ����������� �������.\n", 15);
		system("pause");
		fight(Boss_stage2);
		printprint("����� ���� ��� �� �������, � ������������ ������.\n", 15);
		system("pause");
		fight(Boss_stage3);
		printprint("(�������������� ��������: +20 � �����, +10 � ����. ��������, +10 � ������)\n", 15);
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
		printprint("���������� ����������� �������.\n", 15);
		system("pause");
		fight(Boss_stage2);
		printprint("���������� �� � �����-����, ������ ���养\n��: ��� ���� ��������� - �����? ����� ����� ������� �����?�\n���������� �� ������ �����.\n", 15);
		system("pause");
		fight(Boss_stage3);
		printprint("(�������������� ��������: +20 � �����, +10 � ����. ��������, +10 � ������)\n", 15);
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


		break; //��� ������ ����.
	}
}
/*
1. ��������
2. �������
3. ���� �����
4. ��������� -
5. ������ �����
6. ��������� ��� ������� ����� �����
*/
void ending_2_3(int story_code)
{
	system("cls");
	switch (story_code)
	{
	case 1:
		printprint("�� �������, ��� �� �� ��� �� �������� ����. �� ���� ����� ���� ������?\n1) ����� [����� ����]\n2) ����������� ������ ������ ���������.\n", 15);
		if (choice(2) == 1)
		{
			system("cls");
			printprint("�� ������� �������� �����, ��� � ������ ��������� ���� �����.\n", 15);
			system("pause");
			printstats(_player_);
			death();
		}
		else
		{
			system("cls");
			printprint("�� ������� ���������� �����������.\n", 15);
			system("pause");
			Begining();
		}
		break;

	case 2:
		printprint("������ �� ����� ������������� �����������.\n� �����-�� ������ ��� ���� �������� �������� ������� ����� �� ��� ��������.\n��� ����������, ��� �� ������� ����� ������� ���� ������. �� ��� ����������.\n����� � �������� ������ �� �����������...\n", 15);
		system("pause");
		system("cls");
		printprint("��� ������ ����� ���, ��� ����� �������� ������������ ������� ������ �����������.\n������ ��, ��� �� ����� ������� - ������������ � ��������� �� ����� ���������� ������ �� ������.\n", 15);
		system("pause");
		system("cls");
		death();
		break;

	case 3:
		printprint("�� ������ ���� ����������� ", 15);
		if (_player_.kind_evil > 0)
		{
			printprint("� �� ���������� ������ ��� ���� ���������.\n(+2000 � ������� (�������� ��� �����������))\n", 15);
			_player_.money += 2000;
			system("pause");
			system("cls");
			printprint("�������� ����� ����������� ���-�� ���?\n1) ��.\n2) ���.\n", 15);
			if (choice(2) == 1)
			{
				system("cls");
				printprint("�� ��������� ���� � ������������� �� ������ �����������.\n", 15);
				system("pause");
				system("cls");
				Begining();
			}
			system("cls");
			printprint("�� �������� ������������ �� ������ �����.\n(+0 � �������(����� ���� ���� ��� ��������))\n", 15);
			system("pause");
			system("cls");
			printstats(_player_);
			death();
		}

		printprint("� �� ���������� ������ ��� ���� ��� ��� ����� ��������.\n(+30000 � ������� (�������� ��� ����������� + ����� � ���������))\n", 15);
		_player_.money += 30000;
		system("pause");
		system("cls");
		printprint("�������� ����� ����������� ���-�� ���?\n1) ��.\n2) ���.\n", 15);
		if (choice(2) == 1)
		{
			system("cls");
			printprint("�� ��������� ���� � ������������� �� ������ �����������.\n", 15);
			system("pause");
			system("cls");
			Begining();
		}
		system("cls");
		printprint("�� �������� ������������ �� ������ �����.\n(+0 � �������(����� ���� ���� ��� ��������))\n", 15);
		system("pause");
		system("cls");
		printstats(_player_);
		death();

		break;

	case 4:
		break;

	case 5:
		printprint("�� �������� ��������� ������.\n1) ����� �� ���� ������ ��������� ������\n2) ������� ������ ����.\n3) ��������� � �������������.\n", 15);
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
		printprint("�� ����������� ����������� �������������.\n(���� ����� ������ ��������������)\n����:\n", 15);
		printstats(_player_);
		printprint("\n�����:\n", 15);
		_player_.max_health += 30;
		_player_.health += 30;
		_player_.strength += 30;
		_player_.defense += 10;
		_player_.max_stamina += 40;
		_player_.stamina += 40;
		_player_.kind_evil -= 10;
		_player_.charisma = +15;
		strcpy_s(_player_.p_class, "�������������");
		printstats(_player_);
		system("pause");
		system("cls");

		printprint("���������� ��� ������ �������� � ��������� ���.\n1) ����� [����� ����]\n2) ����������� ������ ������ ���������.\n", 15);
		if (choice(2) == 1)
		{
			system("cls");
			printprint("�� ������� �������� �����, ��� � ������ ��������� ���� �����.\n", 15);
			system("pause");
			printstats(_player_);
			death();
		}
		else
		{
			system("cls");
			printprint("�� ������� ���������� �����������.\n", 15);
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