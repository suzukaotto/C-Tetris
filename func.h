#ifndef _FUNC_H
#define _FUNC_H

#include <stdbool.h>

char key_input();

void cursorPos(int x, int y);
void cursorView(bool visible);

int game_exit(void);
int game_pause(void);
void system_pasue(void);
void system_cls(void);


#endif
