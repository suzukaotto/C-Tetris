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
}

void board_print() {
	int x, y;
	
	// board print
	for (y=0; y<BOARD_Y+2; y++) {
		for (x=0; x<BOARD_X+2; x++)
			printf("%c", board[y][x]);
		printf("\n");
	}
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
}

void brick_print() {
	int x, y;
	for (y=0; y<BRICK_Y; y++) {
		for (x=0; x<BRICK_X; x++) {
			cursorPos(brick_pos[0]+x, brick_pos[1]+y);
			printf("%c", (tetromino[brick_form][brick_rotate][y][x]) ? '#' : '\0');
		}
	}
}

void block_down() {
	brick_pos[1] += 1;
}

int  brick_move(int x, int y, int rotate) {
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
	for (brick_x=0; brick_x<BRICK_X; brick_x++) {
		for (brick_y=0; brick_y<BRICK_Y; brick_y++) {
			cursorPos(20+brick_x, brick_y);
			printf("%d", tetromino[brick_form][brick_rotate][brick_y][brick_x]);
		}
	}
	
	// ######
		
	brick_pos[0] = vif_pos[0];
	brick_pos[1] = vif_pos[1];
	brick_rotate = vif_rotate;
}


