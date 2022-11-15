#include <stdlib.h>
#include "Board.h"
#include "Utility.h"


void InitailizeBoard(Board* board)
{
	for (int col = 0; col < board->height; ++col) {
		for (int row = 0; row < board->width; ++row) {

			int xOutLine = row == 0 || row == board->width - 1;
			int yOutLine = col == 0 || col == board->height - 1;

			board->board[col][row].colorNumber = 7;
			board->board[col][row].img = ((xOutLine || yOutLine) ? "¡á" : "¦«");
			board->board[col][row].type = ((xOutLine || yOutLine) ? WALL : EMPTY);
		}
	}
}



void DrawBoard(Board* board, Vector2 cursor) 
{
	for (int col = 0; col < board->height; ++col) {
		for (int row = 0; row < board->width; ++row) {

			SetColor(board->board[col][row].colorNumber);
			ScreenPrint(row, col, board->board[col][row].img);
		}
	}
	SetColor(7);
}




int ExistStone(Board* board, Vector2 pos) 
{
	int isStone = board->board[pos.y][pos.x].type == STONEBLACK;
	return isStone || (board->board[pos.y][pos.x].type == STONEWHITE);
}




int OutOfRange(Board* board, int x, int y) 
{
	int xOutLine = (x < 1 || x > board->width  - 2);
	int yOutLine = (y < 1 || y > board->height - 2);

	return xOutLine || yOutLine;
}