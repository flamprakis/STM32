#include <stdio.h>
#include <stdint.h>

int main() {
    // This variable simulates a flag that changes when your sensor 
    // finishes a measurement. In a real system, hardware or an 
    // interrupt would flip this to 1 in the background.
    volatile uint8_t measurement_ready = 0; 

    printf("Triggering ultrasound sensor...\n");
    printf("Waiting for echo pulse to complete...\n");

    // ---- YOUR TASK ----
    // If a compiler optimizes this code, it will look at the loop below,
    // see that 'measurement_ready' is never altered inside the body of the loop,
    // and optimize it into an infinite loop.
    //
    // Fix the variable declaration above so the compiler is forced to 
    // read its true value from memory every single time.
    
    while (measurement_ready == 0) {
        // Line up and wait for the hardware signal.
        // In a simulated desktop environment, this loop actually runs forever 
        // because we don't have real interrupts firing here, but we want to 
        // make sure the syntax is correct for your real STM32.
    }

    printf("Data received! Calculating distance...\n");
    return 0;
}