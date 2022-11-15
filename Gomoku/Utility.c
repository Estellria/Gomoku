#include "Utility.h"
#include <assert.h>
#include <wincon.h>
#include <stdint.h>
#include <stdio.h>

#pragma warning(disable:4996)


static int g_nScreenIndex;
static HANDLE g_hScreen[2];



void gotoxy(int x, int y)
{    
    COORD CursorPosition = { x, y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}



// 0 ~ 15 까지 색상 설정 가능
void SetColor(int color)
{
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}



void ScreenInit()
{
    CONSOLE_CURSOR_INFO cci;

    g_hScreen[0] = CreateConsoleScreenBuffer
    (GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    g_hScreen[1] = CreateConsoleScreenBuffer
    (GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(g_hScreen[0], &cci);
    SetConsoleCursorInfo(g_hScreen[1], &cci);
}




void ScreenFlipping()
{
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
    g_nScreenIndex = !g_nScreenIndex;
}




void ScreenClear(int width, int height)
{
    COORD Coord = { 1, 1 };
    DWORD dw;

    width *= 2;

    FillConsoleOutputCharacterW(g_hScreen[g_nScreenIndex], L' ', width * height, Coord, &dw);
}



void ScreenRelease()
{
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}



void ScreenPrint(int x, int y, char* string)
{
    DWORD dw;
    COORD CursorPosition = { x * 2, y };

    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}