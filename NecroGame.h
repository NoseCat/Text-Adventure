#pragma once
#ifndef _NECROGAME
#define _NECROGAME

const int GlobalRows = 3;
const int GlobalColomns = 3;

void BoardPrint(bool Board[GlobalColomns][GlobalRows]);
int ChooseTile();
void ApplyChoice(int input, bool Board[GlobalColomns][GlobalRows]);
bool WinCheck(bool Board[GlobalColomns][GlobalRows]);
void ClearBoard(bool Board[GlobalColomns][GlobalRows]);
int NecroGame();

#endif