#include "Gomoku.h"
#include <conio.h>
#include <stdio.h>


Gomoku* Init(int width, int height)
{
	ScreenInit();

	Gomoku* tempGomoku = calloc(1, sizeof(Gomoku));
	tempGomoku->board = calloc(1, sizeof(Board));
	tempGomoku->board->width = width;
	tempGomoku->board->height = height;
	InitailizeBoard(tempGomoku->board);

	Vector2 initPos = { 1, 1 };
	tempGomoku->cursorPos = initPos;
	tempGomoku->continuable = 1;
	tempGomoku->turn = 0;

	return tempGomoku;
}




void Input(Gomoku* gomoku)
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 224: MoveCursor(gomoku); break;
			case 32:  SetStone(gomoku);	  break;
		}
	}
}




void SetStone(Gomoku* gomoku)
{
	if (!ExistStone(gomoku->board, gomoku->cursorPos))
	{
		Vector2 tempVec = gomoku->cursorPos;

		switch (gomoku->turn % 2)
		{
			case 0: gomoku->board->board[tempVec.y][tempVec.x].colorNumber = 8; 
				gomoku->board->board[tempVec.y][tempVec.x].type = STONEBLACK; break;

			case 1: gomoku->board->board[tempVec.y][tempVec.x].colorNumber = 7; 
				gomoku->board->board[tempVec.y][tempVec.x].type = STONEWHITE; break;
		}
		gomoku->board->board[tempVec.y][tempVec.x].img  = "¡Ü";
		++gomoku->turn;
	}
}




void GameExit(Gomoku* gomoku)
{
	free(gomoku->board);
	free(gomoku);
}




void DrawCursor(Gomoku* gomoku)
{
	Vector2 tempVec = gomoku->cursorPos;

	if (!ExistStone(gomoku->board, gomoku->cursorPos)) 
	{
		ScreenPrint(tempVec.x, tempVec.y, "¢Â");
	}
}




void MoveCursor(Gomoku* gomoku)
{
	Vector2 buff = { 0, 0 };

	switch (_getch())
	{
		case UP:	--buff.y; break;
		case DOWN:	++buff.y; break;
		case LEFT:	--buff.x; break;
		case RIGHT: ++buff.x; break;
	}
	int x = gomoku->cursorPos.x + buff.x;
	int y = gomoku->cursorPos.y + buff.y;

	if (!OutOfRange(gomoku->board, x, y))
	{
		Vector2 tempVec = { x,y };
		gomoku->cursorPos = tempVec;
	}
}	