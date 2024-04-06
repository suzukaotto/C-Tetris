#include "func.h"
#include "object.h"

#include <windows.h>
#include <conio.h>
#include "keys.h"

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

void game_reset(void) {
	board_init();
	brick_init();
	game_score = 0;
}

int game_pause(void) {
	int view_x = 20;
	int view_y = 5;
	
	// map blur
	int x, y;
	cursorPos(0, 0);
	for (y=0; y<BOARD_Y+2; y++) {
		for (x=0; x<BOARD_X+2; x++)
			printf("#");
		printf("\n");
	}
	
	// text print
	cursorView(true);
	cursorPos(view_x, view_y);
	printf("Game Pause . . . ");
	cursorPos(view_x, view_y+1);
	printf("Press any key to continue . . . ");	
	
	getch();
	cursorView(false);
	system_cls();
	
	return 0;
}

int game_exit(void) {
	int view_x = 20;
	int view_y = 5;
	
	cursorView(true);
	cursorPos(view_x, view_y);
	printf("Are you sure game byebye?");
	cursorPos(view_x, view_y+1);
	printf("Press any key to continue. [EXIT: Y]: ");
	
	char key = getch();
	cursorView(false);
	
	if (key == ky || key == kY)
		return 1;
	
	system_cls();
	
	return 0;
}

void system_pause(void) {
	system("pause");
	return;
}

void system_cls(void) {
	system("cls");
	return;
}
