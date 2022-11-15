#include "Observer.h"


void CheckStones(Gomoku* gomoku)
{
	for (int y = 1; y < gomoku->board->height - 1; ++y) {
		for (int x = 1; x < gomoku->board->width - 1; ++x) {

			if (gomoku->board->board[y][x].type == EMPTY) continue;
			
			int safeX = (x + 4 < gomoku->board->width - 1);
			int safeY = (y + 4 < gomoku->board->height - 1);

			CheckBingo(gomoku, Vector(x, y), (x - 4 > 0 && safeY), Vector(-1, 1));
			CheckBingo(gomoku, Vector(x, y), (safeX && safeY), Vector(1, 1));
			CheckBingo(gomoku, Vector(x, y), safeX, Vector(1, 0));
			CheckBingo(gomoku, Vector(x, y), safeY, Vector(0, 1));
		}
	}
}






void CheckBingo(Gomoku* gomoku, Vector2 pos, int condition, Vector2 sign)
{
	if (condition)
	{
		Board* tempBoard = gomoku->board;
		eCELLTYPE pivotType = tempBoard->board[pos.y][pos.x].type;

		for (int i = 1; i < 5; ++i)
		{
			int x = pos.x + sign.x * i;
			int y = pos.y + sign.y * i;

			if (pivotType != tempBoard->board[y][x].type) 
			{
				return;
			}
		}
		gomoku->continuable = 0;
	}
}
