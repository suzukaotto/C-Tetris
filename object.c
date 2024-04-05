#include "object.h"
#include "func.h"

#include <time.h>

char board[BOARD_Y+2][BOARD_X+2];

void board_init() {
    int x, y;

    for (x=0; x<BOARD_X+2 ; x++)
        board[0][x] = BOARD_WALL;

    for (y=1; y<BOARD_Y+1; y++) {
        board[y][0] = BOARD_WALL;
        for (x=1; x<BOARD_X+1; x++)
        	board[y][x] = BOARD_BG;
        board[y][BOARD_X+1] = BOARD_WALL;
    }

    for (x=0; x<BOARD_X+2; x++)
        board[BOARD_Y+1][x] = BOARD_WALL;
    
    return;
}

void board_print() {
	int x, y;
	
	// board print
	for (y=0; y<BOARD_Y+2; y++) {
		for (x=0; x<BOARD_X+2; x++)
			printf("%c", board[y][x]);
		printf("\n");
	}
	
	return;
}

int board_break() {
	int x, y, i;
	int score = 0;
	
	for (y = BOARD_Y; y > 0; y--) {
		bool line_full = true;
		
		for (x = 1; x < BOARD_X + 1; x++)
			if (board[y][x] != BOARD_BRICK)
				line_full = false;
		
		if (line_full) {
			score += LINE_SCORE;
			for (x = 1; x < BOARD_X + 1; x++)
				board[y][x] = BOARD_BG;
			
			for (i = y - 1; i > 0; i--) {
				for (x = 1; x < BOARD_X + 1; x++) {
					board[i + 1][x] = board[i][x];
				}
			}
		}
	}
	
	return score;
}


char tetromino[7][4][4][4] = {
	// O Tetromino
	{
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	
	// I Tetromino
	{
		{
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0}
		}
	},
	
	// T Tetromino
	{
		{
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	},
	
	// L Tetromino
	{
		{
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	},
	
	// J Tetromino
	{
		{
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0}
		}
	},
	
	// S Tetromino
	{
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 0}
		}
	},
	
	// Z Tetromino
	{
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		}
	}	
};

void brick_init() {
	brick_pos[0]      = 4; // X
	brick_pos[1]      = 1; // Y
	brick_form   = rand()%BRICK_MAX_FORM;
	brick_rotate = rand()%BRICK_MAX_ROTATE;
	
	return 0;
}

void brick_print() {
	char fill_sign =  '@';
	char space_sign = '\0';
	
	int x, y;
	for (y=0; y<BRICK_Y; y++) {
		for (x=0; x<BRICK_X; x++) {
			cursorPos(brick_pos[0]+x, brick_pos[1]+y);
			printf("%c", (tetromino[brick_form][brick_rotate][y][x]) ? fill_sign : space_sign);
		}
	}
	
	return 0;
}

void brick_set() {
	int board_x, board_y;
	for (board_y=0; board_y<BRICK_X; board_y++) {
		for (board_x=0; board_x<BRICK_Y; board_x++) {			
			// if not board bg 
			if (tetromino[brick_form][brick_rotate][board_y][board_x])
				board[brick_pos[1]+board_y][brick_pos[0]+board_x] = BOARD_BRICK;
		}
	}
}

int brick_move(int x, int y, int rotate) {
	static drop_stack = 0;
	
	int vif_pos[2] = {brick_pos[0], brick_pos[1]};
	int vif_rotate = brick_rotate;
	
	vif_pos[0] = brick_pos[0] + x;
	vif_pos[1] = brick_pos[1] + y;
	
	if ((rotate+brick_rotate) >= BRICK_MAX_ROTATE)
		vif_rotate = 0;
	else
		vif_rotate = brick_rotate + rotate;
	
	// block verify code
	int board_x, board_y;
	int brick_x, brick_y;
	for (board_y=0; board_y<BRICK_X; board_y++) {
		for (board_x=0; board_x<BRICK_Y; board_x++) {
			// if not board bg 
			if (tetromino[brick_form][vif_rotate][board_y][board_x] && !(board[vif_pos[1]+board_y][vif_pos[0]+board_x] == BOARD_BG)) {
				drop_stack += 1;
				
				// DEBUG_MODE
				if (DEBUG_MODE) {
					cursorPos(45, 0);
					printf("DSTACK=%d", drop_stack);
				}
				
				if (drop_stack >= MAX_DROP_STACK) {
					drop_stack = 0;
					brick_set();
					brick_init();
					
					return 4;
				}
				
				return 1;
			}
		}
	}
	// ######
	
	if (x == 0)
		drop_stack = 0;
	
	brick_pos[0] = vif_pos[0];
	brick_pos[1] = vif_pos[1];
	brick_rotate = vif_rotate;
	return 0;
}

void brick_harddrop() {
	int rst;
	while (1) {
		rst = brick_move(0, 1, 0);
		if (rst == 4)
			return 0;
	}
}

