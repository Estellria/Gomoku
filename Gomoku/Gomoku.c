#include "Gomoku.h"
#include "Observer.h"
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
		gomoku->board->board[tempVec.y][tempVec.x].img  = "●";
		++gomoku->turn;
	}
}




void GameExit(Gomoku* gomoku)
{
	free(bingoPosList);
	free(gomoku->board);
	free(gomoku);
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





void DrawResult(Vector2* bingoList, int turn) 
{
	DrawBingoStones(bingoList);
	Sleep(2500);

	ScreenRelease();
	DrawWiner(turn);
}




void DrawBingoStones(Vector2* bingoList)
{
	ScreenFlipping();
	SetColor(12);

	for (int i = 0; i < 5; ++i)
	{
		int x = bingoList[i].x;
		int y = bingoList[i].y;
		ScreenPrint(x, y, "●");
	}

	ScreenFlipping();
	SetColor(7);
}




void DrawWiner(int turn)
{
	switch (turn % 2)
	{
		case 1: printf("흑돌이 승리하였습니다."); break;
		case 0: printf("백돌이 승리하였습니다."); break;
	}
}