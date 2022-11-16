#pragma once
#include "Gomoku.h"


static Vector2* bingoPosList;

Vector2* ListInit();

void CheckStones(Gomoku* gomoku);

void CheckBingo(Gomoku* gomoku, Vector2 pos, int condition, Vector2 offset);

void EndSet(Gomoku* gomoku, Vector2* posList);