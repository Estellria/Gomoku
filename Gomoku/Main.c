#include "Gomoku.h"
#include "Observer.h"
#include <stdio.h>

void DrawWiner(int turn)
{
	switch (turn % 2)
	{
		case 1: printf("�浹�� �¸��Ͽ����ϴ�."); break;
		case 0: printf("�鵹�� �¸��Ͽ����ϴ�."); break;
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