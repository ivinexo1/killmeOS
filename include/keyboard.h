#pragma once
#include "../include/isr.h"
void keyboard_callback(registers_t *);

void init_keyboard();

// bude storovat inputy z keyboardu na pouzitie v shelly
// vysvetli mi preco nie su arrays dynamic v c a musia mat defined size
// 80 indexes lebo to je pocet chars v riadku

extern int keybuffer[80];
extern int keybuffer_size;