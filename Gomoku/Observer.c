#include "Observer.h"
#include <stdlib.h>


void CheckStones(Gomoku* gomoku)
{
	for (int y = 1; y < gomoku->board->height - 1; ++y) {
		for (int x = 1; x < gomoku->board->width - 1; ++x) {

			if (gomoku->board->board[y][x].type == EMPTY) continue;
			
			int safeLeft = (x - 4 > 0);
			int safeRight = (x + 4 < gomoku->board->width - 1);
			int safeBottom = (y + 4 < gomoku->board->height - 1);

			CheckBingo(gomoku, Vector(x, y), (safeLeft && safeBottom), Vector(-1, 1));
			CheckBingo(gomoku, Vector(x, y), (safeRight && safeBottom), Vector(1, 1));
			CheckBingo(gomoku, Vector(x, y), safeRight, Vector(1, 0));
			CheckBingo(gomoku, Vector(x, y), safeBottom, Vector(0, 1));
		}
	}
}






void CheckBingo(Gomoku* gomoku, Vector2 pos, int condition, Vector2 sign)
{
	if (condition && gomoku->continuable)
	{
		Vector2 posList[5] = { pos, 0 };
		eCELLTYPE pivotType = tempBoard->board[pos.y][pos.x].type;

		for (int i = 1; i < 5; ++i)
		{
			int x = pos.x + sign.x * i;
			int y = pos.y + sign.y * i;
			posList[i] = Vector(x, y);

			if (pivotType != tempBoard->board[y][x].type) return;
		}
		EndSet(gomoku, posList);
	}
}






void EndSet(Gomoku* gomoku, Vector2* posList)
{
	gomoku->continuable = 0;
	int size = sizeof(Vector2) * 5;
	memcpy_s(bingoPosList, size, posList, size);
}
