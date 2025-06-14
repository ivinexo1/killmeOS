#include "../include/keyboard.h"
#include "../include/ports.h"
#include "../include/isr.h"
#include "../include/vga.h"

int keybuffer[80] = {0};
int keybuffer_size = 0;

void print_letter(uint8_t scancode) {
    switch (scancode) {
        case 0x0:
            printString("ERROR");
            break;
        case 0x1:
            printString("ESC");
            break;
        case 0x2:
            printString("1");
            break;
        case 0x3:
            printString("2");
            break;
        case 0x4:
            printString("3");
            break;
        case 0x5:
            printString("4");
            break;
        case 0x6:
            printString("5");
            break;
        case 0x7:
            printString("6");
            break;
        case 0x8:
            printString("7");
            break;
        case 0x9:
            printString("8");
            break;
        case 0x0A:
            printString("9");
            break;
        case 0x0B:
            printString("0");
            break;
        case 0x0C:
            printString("-");
            break;
        case 0x0D:
            printString("="); // 'Shift + =' => '+'
            break;
        case 0x0E:
            //printString("Backspace");
            break;
        case 0x0F:
            printString("   "); // tab
            break;
        case 0x10:
            printString("q");
            break;
        case 0x11:
            printString("w");
            break;
        case 0x12:
            printString("e");
            break;
        case 0x13:
            printString("r");
            break;
        case 0x14:
            printString("t");
            break;
        case 0x15:
            printString("y");
            break;
        case 0x16:
            printString("u");
            break;
        case 0x17:
            printString("i");
            break;
        case 0x18:
            printString("o");
            break;
        case 0x19:
            printString("p");
            break;
        case 0x1A:
            printString("[");
            break;
        case 0x1B:
            printString("]");
            break;
        case 0x1C:
            //printString("ENTER");
            printChar('\n'); // <-- mozno toto bude better ale nechce mi zase fungovat ./makeNrun.sh vo WSL
            break;
        case 0x1D:
            //printString("LCtrl"); //Namiesto pisania by to mali byt shortcuts.. to asi budeme moct robit pomocou key buffera + check pri switchcase ze sa nedrzi ctrl
            break;
        case 0x1E:
            printString("a");
            break;
        case 0x1F:
            printString("s");
            break;
        case 0x20:
            printString("d");
            break;
        case 0x21:
            printString("f");
            break;
        case 0x22:
            printString("g");
            break;
        case 0x23:
            printString("h");
            break;
        case 0x24:
            printString("j");
            break;
        case 0x25:
            printString("k");
            break;
        case 0x26:
            printString("l");
            break;
        case 0x27:
            printString(";");
            break;
        case 0x28:
            printString("'");
            break;
        case 0x29:
            printString("`");
            break;
        case 0x2A:
            //printString("LShift");
            break;
        case 0x2B:
            printString("\\");
            break;
        case 0x2C:
            printString("z");
            break;
        case 0x2D:
            printString("x");
            break;
        case 0x2E:
            printString("c");
            break;
        case 0x2F:
            printString("v");
            break;
        case 0x30:
            printString("b");
            break;
        case 0x31:
            printString("n");
            break;
        case 0x32:
            printString("m");
            break;
        case 0x33:
            printString(",");
            break;
        case 0x34:
            printString(".");
            break;
        case 0x35:
            printString("/");
            break;
        case 0x36:
            //printString("Rshift");
            break;
        case 0x37:
            printString("*");
            break;
        case 0x38:
            //printString("LAlt");
            break;
        case 0x39:
            printString(" ");
            break;
        // default:
        //     /* 'keuyp' event corresponds to the 'keydown' + 0x80
        //      * it may still be a scancode we haven't implemented yet, or
        //      * maybe a control/escape sequence */
        //     if (scancode <= 0x7f) {
        //         printString("Unknown key down");
        //     } else if (scancode <= 0x39 + 0x80) {
        //         //printString("key up ");
        //         //print_letter(scancode - 0x80);
        //     } else printString("Unknown key up");
        //     break;
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

