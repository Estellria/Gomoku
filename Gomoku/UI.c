#include "UI.h"
#include <string.h>
#include <stdio.h>
#include <time.h>



void DrawGameInfo(Gomoku* gomoku)
{
	Board* tBoard = gomoku->board;
	Vector2 pivot = Vector(tBoard->width + 1, 2);
	DrawBox(pivot, Vector(13, 10));

	DrawTurn(gomoku->turn, Vector(pivot.x + 1, pivot.y + 2));

	DrawStoneCount(gomoku->turn, Vector(pivot.x + 1, pivot.y + 4), STONEBLACK);
	DrawStoneCount(gomoku->turn, Vector(pivot.x + 1, pivot.y + 5), STONEWHITE);

	DrawPlayTime(Vector(pivot.x + 1, pivot.y + 7));

	ScreenPrint(pivot.x + 3, pivot.y - 2, "���� ���� ��Ȳ");
}






void DrawBox(Vector2 pivot, Vector2 size)
{
	for (int col = pivot.y; col < pivot.y + size.y; ++col)
	{
		for (int row = pivot.x; row < pivot.x + size.x; ++row)
		{
			int yOutLine = (col == pivot.y || col == pivot.y + size.y - 1);
			int xOutLine = (row == pivot.x || row == pivot.x + size.x - 1);

			if (xOutLine || yOutLine)
			{
				ScreenPrint(row, col, "��");
			}
		}
	}
}




void DrawWiner(Gomoku* gomuku)
{
	ScreenRelease();

	switch (gomuku->turn % 2)
	{
		case 1: printf("�浹�� �¸��Ͽ����ϴ�."); break;
		case 0: printf("�鵹�� �¸��Ͽ����ϴ�."); break;
	}
}





void DrawStoneCount(int turn, Vector2 pivot, eCELLTYPE type)
{
	char msg[30];
	char stoneTypeMsg[10];

	int count = (turn / 2) + (type == STONEBLACK ? turn % 2 : 0);
	strcpy_s(stoneTypeMsg, 10, type == STONEBLACK ? "�浹" : "�鵹");

	sprintf_s(msg, 30, "%s ��   : %d", stoneTypeMsg, count);
	ScreenPrint(pivot.x, pivot.y, msg);
}





void DrawTurn(int turn, Vector2 pivot)
{
	char turnMsg[20] = "���� ���� : ";
	strcat_s(turnMsg, 20, (turn % 2 ? "�鵹" : "�浹"));

	ScreenPrint(pivot.x, pivot.y, turnMsg);
}





void DrawCursor(Gomoku* gomoku)
{
	Vector2 tempVec = gomoku->cursorPos;

	if (!ExistStone(gomoku->board, gomoku->cursorPos))
	{
		ScreenPrint(tempVec.x, tempVec.y, "��");
	}
}





void DrawPlayTime(Vector2 pivot)
{
	int timeValue = (int)(clock() / CLOCKS_PER_SEC);
	int minute = timeValue / 60;
	int seconde = timeValue % 60;

	char timeString[50];
	sprintf_s(timeString, 50, "���� �ð� : %d�� %d��", minute, seconde);
	ScreenPrint(pivot.x, pivot.y, timeString);
}