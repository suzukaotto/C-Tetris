#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "keys.h"
#include "object.h"
#include "func.h"

int GAME_DELAY = 10;  // ms
int DROP_TIME  = 20;

void game_play();
void game_tutorial();

int main() {
	char key;
	while (1) {
		printf("T E T R I S");
		printf("\n\n");
		
		printf("1. Play \n");
		printf("2. How to play? \n");
		printf("3. Exit \n");
		
		printf("> ");
		key = getch();
		
		system_cls();
		switch(key) {
			case k1:
				game_play();
				break;
			
			case k2:
				game_tutorial();
				break;
			
			case kEnter:
				break;
			
			default:
				exit(0);
				
		}
		system_cls();
	}
	
	game_play();
}

void game_tutorial() {
	printf("방 향 키: WASD  \n");
	printf("회    전: R     \n");
	printf("하드드롭: SPACE \n");
	printf("게임리셋: G     \n");
	printf("일시중지: P     \n");
	printf("니 기 기: ESC   \n");
	
	printf("\n\n\n\n\n");
	
	
	system_pause();
	system_cls();
}

void game_play() {
	cursorView(false);
	srand(time(NULL));
	
	board_init();
	brick_init();
	
	unsigned int fps_count = 0;
	
	while (true) {
		bool brick_down = true;
		
		// FPS count
		fps_count += 1;
		
		// board print
		cursorPos(0, 0);
		board_print();
		
		// brick print
		printf("FPS_Count : %d \n", fps_count);
		printf("form=%d, rota=%d (x=%d, y=%d) \n", brick_form+1, brick_rotate+1, brick_pos[0], brick_pos[1]);
		brick_print();
		
		// key control
		char key = key_input();
		switch(key) {
			// brick move
			case ka:
			case kA:
				brick_move(-1, 0, 0);
				break;
			
			case kd:
			case kD:
				brick_move(1, 0, 0);
				break;
			
			case kw:
			case kW:
				brick_move(0, -1, 0);
				break;
			
			case ks:
			case kS:
				brick_move(0, 1, 0);
//				brick_down = false;
				break;
			
			// brick rotate
			case kr:
			case kR:
				brick_move(0, 0, 1);
				break;
			
			// brick harddrop
			case kSpace:
				brick_harddrop();
				break;
			
			// display refresh
			case kz:
			case kZ:
				system_cls();
				break;
			
			// reset game
			case kg:
			case kG:
				game_reset();
				break;
			
			// game pause
			case kp:
			case kP:
				game_pause();
				break;
			
			// game exit
			case kEsc:
				if (game_exit())
					return;
				break;
				
		}
		
		// brick down
		if (fps_count%DROP_TIME==0 && brick_down)
			brick_move(0, 1, 0);
		
		board_break();
		cursorPos(20, 15);
		printf("SCORE: %d", 0);
		
		// game delay
		Sleep(GAME_DELAY);
		
	}
	
	return;
}

