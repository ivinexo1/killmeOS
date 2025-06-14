#include "../include/keyboard.h"
#include "../include/ports.h"
#include "../include/isr.h"
#include "../include/vga.h"

int keybuffer[MAX_SIZE];
int shift_pressed = 0; // 0 - shift not pressed, 32 - shift pressed

void print_letter(uint8_t scancode) {
    switch (scancode) {
        case 0x0:
            printString("ERROR");
            break;
        case 0x1:
            //printString("ESC");
            break;
        case 0x2:
            printChar(shift_pressed ? '!' : '1');
            break;
        case 0x3:
            printChar(shift_pressed ? '@' : '2');
            break;
        case 0x4:
            printChar(shift_pressed ? '#' : '3');
            break;
        case 0x5:
            printChar(shift_pressed ? '$' : '4');
            break;
        case 0x6:
            printChar(shift_pressed ? '%' : '5');
            break;
        case 0x7:
            printChar(shift_pressed ? '^' : '6');
            break;
        case 0x8:
            printChar(shift_pressed ? '&' : '7');
            break;
        case 0x9:
            printChar(shift_pressed ? '*' : '8');
            break;
        case 0x0A:
            printChar(shift_pressed ? '(' : '9');
            break;
        case 0x0B:
            printChar(shift_pressed ? ')' : '0');
            break;
        case 0x0C:
            printChar(shift_pressed ? '_' : '-');
            break;
        case 0x0D:
            printChar(shift_pressed ? '+' : '=');
            break;
        case 0x0E:
            //printString("Backspace");
            break;
        case 0x0F:
            printString("   ");
            break;
        case 0x10:
            printChar(shift_pressed ? 'Q' : 'q');
            break;
        case 0x11:
            printChar(shift_pressed ? 'W' : 'w');
            break;
        case 0x12:
            printChar(shift_pressed ? 'E' : 'e');
            break;
        case 0x13:
            printChar(shift_pressed ? 'R' : 'r');
            break;
        case 0x14:
            printChar(shift_pressed ? 'T' : 't');
            break;
        case 0x15:
            printChar(shift_pressed ? 'Y' : 'y');
            break;
        case 0x16:
            printChar(shift_pressed ? 'U' : 'u');
            break;
        case 0x17:
            printChar(shift_pressed ? 'I' : 'i');
            break;
        case 0x18:
            printChar(shift_pressed ? 'O' : 'o');
            break;
        case 0x19:
            printChar(shift_pressed ? 'P' : 'p');
            break;
        case 0x1A:
            printChar(shift_pressed ? '{' : '[');
            break;
        case 0x1B:
            printChar(shift_pressed ? '}' : ']');
            break;
        case 0x1C:
            //printString("ENTER");
            printChar('\n'); // <-- mozno toto bude better ale nechce mi zase fungovat ./makeNrun.sh vo WSL
            break;
        case 0x1D:
            printString("LCtrl"); //Namiesto pisania by to mali byt shortcuts.. to asi budeme moct robit pomocou key buffera + check pri switchcase ze sa nedrzi ctrl
            break;
        case 0x1E:
            printChar(shift_pressed ? 'A' : 'a');
            break;
        case 0x1F:
            printChar(shift_pressed ? 'S' : 's');
            break;
        case 0x20:
            printChar(shift_pressed ? 'D' : 'd');
            break;
        case 0x21:
            printChar(shift_pressed ? 'F' : 'f');
            break;
        case 0x22:
            printChar(shift_pressed ? 'G' : 'g');
            break;
        case 0x23:
            printChar(shift_pressed ? 'H' : 'h');
            break;
        case 0x24:
            printChar(shift_pressed ? 'J' : 'j');
            break;
        case 0x25:
            printChar(shift_pressed ? 'K' : 'k');
            break;
        case 0x26:
            printChar(shift_pressed ? 'L' : 'l');
            break;
        case 0x27:
            printChar(shift_pressed ? ':' : ';');
            break;
        case 0x28:
            printChar(shift_pressed ? '"' : '\'');
            break;
        case 0x29:
            printChar(shift_pressed ? '~' : '`');
            break;
        case 0x2A:
            //printString("LShift");
            shift_pressed = 32;
            break;
        case 0x2B:
            printString("\\");
            break;
        case 0x2C:
            printChar(shift_pressed ? 'Z' : 'z');
            break;
        case 0x2D:
            printChar(shift_pressed ? 'X' : 'x');
            break;
        case 0x2E:
            printChar(shift_pressed ? 'C' : 'c');
            break;
        case 0x2F:
            printChar(shift_pressed ? 'V' : 'v');
            break;
        case 0x30:
            printChar(shift_pressed ? 'B' : 'b');
            break;
        case 0x31:
            printChar(shift_pressed ? 'N' : 'n');
            break;
        case 0x32:
            printChar(shift_pressed ? 'M' : 'm');
            break;
        case 0x33:
            printChar(shift_pressed ? '<' : ',');
            break;
        case 0x34:
            printChar(shift_pressed ? '>' : '.');
            break;
        case 0x35:
            printChar(shift_pressed ? '?' : '/');
            break;
        case 0x36:
            //printString("Rshift");
            break;
        case 0x37:
            printString("*"); // Numpad multiply
            break;
        case 0x38:
            //printString("LAlt");
            break;
        case 0x39:
            printString(" ");
            break;
        default:
            // 'keuyp' event corresponds to the 'keydown' + 0x80
            // it may still be a scancode we haven't implemented yet, or
            // maybe a control/escape sequence 
            if (scancode <= 0x7f) {
                printString("Unknown key down");
            } else if (scancode <= 0x39 + 0x80) {
                if(scancode == 0x2A + 0x80) {
                    shift_pressed = 0; // reset shift on key up
                }
                //printString("key up ");
                //print_letter(scancode - 0x80);
            } else printString("Unknown key up");
            break;
    }
}

void keyboard_callback(registers_t *regs) {
    uint8_t scancode = inb(0x60);
    print_letter(scancode);
    //printChar('\n'); nechces radsej dat ze new line iba ked sa stlaci enter?
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback);
}

