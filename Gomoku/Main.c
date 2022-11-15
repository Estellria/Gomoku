#include "Gomoku.h"
#include "Observer.h"
#include <stdio.h>

void DrawWiner(int turn)
{
	switch (turn % 2)
	{
		case 1: printf("흑돌이 승리하였습니다."); break;
		case 0: printf("백돌이 승리하였습니다."); break;
	}
}





int main()
{
	Gomoku* gomoku = Init(19, 19);

	while (gomoku->continuable)
	{
		ScreenClear(40, 40);
		DrawBoard(gomoku->board, gomoku->cursorPos);

		Input(gomoku);
		CheckStones(gomoku);
		DrawCursor(gomoku);
		ScreenFlipping();
		Sleep(5);
	}
	ScreenRelease();
	DrawWiner(gomoku->turn);
	GameExit(gomoku);
}