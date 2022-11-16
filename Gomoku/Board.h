#pragma once
#include "Cell.h"
#include "Utility.h"
#include "Vector2.h"

typedef struct __board
{
	CELL board[21][21];

	int width;
	int height;
}Board;


void InitailizeBoard(Board* board);
void DrawBoard(Board* board);

int ExistStone(Board* board, Vector2 pos);
int OutOfRange(Board* board, int x, int y);

eCELLTYPE GetCellType(Vector2 pos);