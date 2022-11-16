#pragma once
#include "Utility.h"
#include "Board.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77



typedef struct __gomoku 
{
	int turn;
	int continuable;
	Vector2 cursorPos;
	Board* board;

}Gomoku;



Gomoku* Init(int width, int heigth);

void Input(Gomoku* gomoku);

void SetStone(Gomoku* gomoku);

void GameExit(Gomoku* gomoku);

void MoveCursor(Gomoku* gomoku);

void DrawResult(Vector2* bingoList, int turn);

void DrawBingoStones(Vector2* bingoList);

void DrawWiner(int turn);