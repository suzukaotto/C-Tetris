#include "func.h"

#include <windows.h>
#include <conio.h>

char key_input() {
	char key = NULL;
	if (kbhit())
		key = getch();
		
	return key;
}

void cursorPos(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursorView(bool visible) {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = (visible) ? TRUE : FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void system_cls() {
	system("cls");
}
