#include <stdio.h>
#include <stdint.h> // Contains standard definitions like uint32_t

int main() {
    // Simulate a 32-bit STM32 GPIO Output Data Register (ODR)
    // Initially, let's say all pins (0 to 31) are LOW (0x00000000)
    uint32_t SIM_GPIO_ODR = 0x00000000;
    
    uint8_t LED_PIN = 5; // Your Nucleo's built-in LED is actually on PA5!

    printf("Initial Register Value: 0x%08X\n", SIM_GPIO_ODR);

    // 1. SET Bit 5 (Turn LED ON)
    SIM_GPIO_ODR |= (1 << LED_PIN);
    printf("(1 << %d) = 0x%08X\n", LED_PIN, (1 << LED_PIN));
    printf("After Setting Bit %d:  0x%08X (LED IS ON)\n", LED_PIN, SIM_GPIO_ODR);


    // 2. TOGGLE Bit 5 (Turn LED OFF)
    SIM_GPIO_ODR ^= (1 << LED_PIN);
    printf("After Toggling Bit %d: 0x%08X (LED IS OFF)\n", LED_PIN, SIM_GPIO_ODR);

    // 3. SET Bit 5 again
    SIM_GPIO_ODR |= (1 << LED_PIN);
    
    // 4. CLEAR Bit 5 (Turn LED OFF)
    SIM_GPIO_ODR &= ~(1 << LED_PIN);
    printf("After Clearing Bit %d: 0x%08X (LED IS OFF)\n", LED_PIN, SIM_GPIO_ODR);

    return 0;
}