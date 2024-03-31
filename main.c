#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "object.h"
#include "func.h"

int game_delay = 30; // ms

int main() {
	cursorView(false);
	srand(time(NULL));
	
	board_init();
	brick_init();
	int fps = 0;
	while (true) {
		cursorPos(0, 0);
		
		board_print();
		
		
	}
	
	return 0;
}

