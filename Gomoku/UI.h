#include "Gomoku.h"

void DrawGameInfo(Gomoku* gomoku);

void DrawBox(Vector2 pivot, Vector2 size);

void DrawTurn(int turn, Vector2 pivot);

void DrawStoneCount(int turn, Vector2 pivot, eCELLTYPE type);

void DrawCursor(Gomoku* gomoku);

void DrawPlayTime(Vector2 pivot);