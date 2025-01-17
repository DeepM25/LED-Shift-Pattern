#include <reg51.h>

void delay(unsigned int count) {
    unsigned int i;
    for(i = 0; i < count; i++);
}

void main() {
    unsigned char x = 0x01; // Start with the first bit set
    unsigned char y;

    P1 = 0x00; // Initialize port P1 to 0 (turn off all LEDs)

    while(1) {
        for(y = 0; y < 8; y++) {
            P1 = x;           // Output current value of x to Port 1
            delay(60000);     // Delay to make the LED visible
            x = x << 1;       // Shift the active bit left
        }
        
        // After completing one full loop (from 0x01 to 0x80), reset x to 0x01 to restart
        x = 0x01;
    }
}
