#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "keys.h"
#include "object.h"
#include "func.h"

int game_delay = 1; // ms

int main() {
	cursorView(false);
	srand(time(NULL));
	
	board_init();
	brick_init();
	
	int fps_count = 0;
	char key;
	while (true) {
		bool is_brick_down = false;
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
		key = key_input();
		switch(key) {
			// brick left
			case ka:
			case kA:
				brick_move(-1, 0, 0);
				break;
			
			// brick right
			case kd:
			case kD:
				brick_move(1, 0, 0);
				break;
				
			// brick up
			case kw:
			case kW:
				brick_move(0, -1, 0);
				break;
				
			// brick down
			case ks:
			case kS:
				brick_move(0, 1, 0);
				is_brick_down = true;
				break;
			
			// brick rotate plus
			case kr:
			case kR:
				brick_move(0, 0, 1);
				break;
				
			// brick rotate minus
			case ke:
			case kE:
				brick_move(0, 0, -1);
				break;
			
			// brick harddrop
			case kSpace:
				brick_init();
				break;
			
			// display refresh
			case kz:
			case kZ:
				system_cls();
				break;
			
			// game pause
			case kEnter:
				game_pause();
				break;
			
			// game exit
			case kEsc:
				game_exit();
				break;
				
		}
		
		// block down
		if (fps_count%30==0 && !is_brick_down)
			block_down();
		
		// game delay
		Sleep(game_delay);
		
	}
	
	return 0;
}

