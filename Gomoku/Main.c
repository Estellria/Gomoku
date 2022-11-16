#include "Gomoku.h"
#include "UI.h"


int main()
{
	Gomoku* gomoku = Init(19, 19);
	Vector2* list = ListInit();

	while (gomoku->continuable)
	{
		ScreenClear(40, 40);
		DrawBoard(gomoku->board, gomoku->cursorPos);

		Input(gomoku);
		DrawGameInfo(gomoku);
		CheckStones(gomoku);
		DrawCursor(gomoku);
		ScreenFlipping();
		Sleep(20);
	}
	DrawResult(list, gomoku->turn);
	GameExit(gomoku);
}