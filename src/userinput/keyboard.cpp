#include "keyboard.h"

    bool isLeftShiftPressed;
    bool isRightShiftPressed;

    bool Keyboard::shifted;
    bool Keyboard::ctrl_down;
    bool Keyboard::alt_down;
    bool Keyboard::fn_down;
    bool Keyboard::caps_lock;
    bool Keyboard::scroll_lock;
    bool Keyboard::num_lock;

void HandleKeyboard(uint8_t scancode){

    // if(scancode = 89){
    //     GlobalRenderer->CursorPosition = {0, 0};
    // }

    switch (scancode){
        case LeftShift:
            isLeftShiftPressed = true;
            return;
        case LeftShift + 0x80:
            isLeftShiftPressed = false;
            return;
        case RightShift:
            isRightShiftPressed = true;
            return;
        case RightShift + 0x80:
            isRightShiftPressed = false;
            return;
        case Enter:
            GlobalRenderer->Next();
            return;
        case Spacebar:
            GlobalRenderer->PutChar(' ');
            return;
        case BackSpace:
            GlobalRenderer->ClearChar();
            return;
        case 0x2E:
            if(Keyboard::ctrl_down){
                //CTRL + C
                //TODO Make it return false if its not down. 
                GlobalRenderer->Print("CTRL C ");
                
            }

        // Caps Lock
		case 0x3A: Keyboard::caps_lock = !Keyboard::caps_lock; return;
        // Num Lock
        case 0x45: Keyboard::num_lock = !Keyboard::num_lock; return;
        // Scroll Lock
		case 0x46: Keyboard::scroll_lock = !Keyboard::scroll_lock; return;
        case 0x9D: Keyboard::ctrl_down = false;
        //case 0xAA: Keyboard::shifted = false;
        //case 0xB6: Keyboard::shifted = false;
        case 0xB8: Keyboard::alt_down = false;
        case 0x1D:
            Keyboard::ctrl_down = true; return;
    }

    char ascii = QWERTYKeyboard::Translate(scancode, isLeftShiftPressed | isRightShiftPressed);

    if (ascii != 0){
        GlobalRenderer->PutChar(ascii);
    }

}

void Keyboard::Initialize(){
    Keyboard::num_lock = false;
	Keyboard::caps_lock = false;
	Keyboard::scroll_lock = false;
	Keyboard::alt_down = false;
	Keyboard::ctrl_down = false;
	Keyboard::fn_down = false;
}