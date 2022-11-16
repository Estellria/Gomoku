#include "Gomoku.h"
#include "Observer.h"
#include "UI.h"


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
		DrawGameInfo(gomoku);
		ScreenFlipping();
		Sleep(20);
	}
	DrawResult(gomoku->turn, bingoPosList);
	GameExit(gomoku);
}