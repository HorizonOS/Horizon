#pragma once
#include <stdint.h>
#include "kbScancodeTranslation.h"
#include "../BasicRenderer.h"

void HandleKeyboard(uint8_t scancode);

class Keyboard {

public:
	static void Initialize();
	static bool shifted;
	static bool ctrl_down;
	static bool alt_down;
	static bool fn_down;
	static bool caps_lock;
	static bool scroll_lock;
	static bool num_lock;
};