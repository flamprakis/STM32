#include <stdio.h>
#include <stdint.h>

int main() {
    // ====================================================================
    // TASK 1: BIT MASKING & SETTING
    // Target: Configure Pin 6 of GPIOA as an Output pin.
    // To do this, Bit 13 must become 0, and Bit 12 must become 1.
    // ====================================================================
    uint32_t SIM_GPIOA_MODER = 0x00004000; // Currently, Bit 14 is set (just as an example)

    // 1. CLEAR Bit 13 (Set it to 0)
    SIM_GPIOA_MODER &= ~(1 << 13);
    SIM_GPIOA_MODER |= (1 << 12);

    // This print statement will verify your logic. 
    // If done correctly, Bit 13 will be 0 and Bit 12 will be 1.
    printf("MODER Value: 0x%08X\n", SIM_GPIOA_MODER);


    // ====================================================================
    // TASK 2: BIT CHECKING
    // Target: Check if Pin 6 (Bit 6) is HIGH.
    // ====================================================================
    uint32_t SIM_GPIOA_IDR = 0x00000000; // Simulated input register with Pin 6 High (0x40 = 0b01000000)

    // 3. Write an if-statement checking if Bit 6 is set using AND (&)

    if (SIM_GPIOA_IDR & (1<<6) ) {
        printf("Echo Pin is HIGH!\n");
    } else {
        printf("Echo Pin is LOW.\n");
    }
    

    return 0;
}