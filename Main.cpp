#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <Time.h>

#include "text2_2.h"
#include "text2_1.h"
//#include "func1.h"
#include "func2.h"
#include "func3.h"
//Player _player_;
#include "Opening.h" 
#include "NecroGame.h"
#include "Krestiki.h"
#include "Reighn.h"
int main()
{
	system("chcp 1251 > nul");
	srand(time(0));

	printprint("все было так просто...", 15);
	//Reighn();
	//tunnel_2();
	//printstats(_player_);
	//NecroGame();
	NameEnter();
	//krestiki();
}