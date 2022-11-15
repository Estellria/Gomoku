#pragma once
#include <Windows.h>

void gotoxy(int x, int y);

void ScreenInit();

void ScreenClear(int width, int height);

void SetColor(unsigned short color);

void ScreenPrint(int x, int y, char* string);

void ScreenFlipping();

void ScreenRelease();