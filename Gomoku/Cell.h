#pragma once
#include <Windows.h>

typedef enum __celltype
{
	EMPTY,
	STONEBLACK,
	STONEWHITE,
	WALL
}eCELLTYPE;


typedef struct __cell
{
	int colorNumber;
	char* img;

	eCELLTYPE type;
}CELL;