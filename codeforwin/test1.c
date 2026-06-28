#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool checkLSB(uint32_t number);
bool checkMSB(uint32_t number);
int getBit(uint32_t number, int bitPos);
uint32_t setBit(uint32_t number, int bitPos);
uint32_t clearBit(uint32_t number, int bitPos);
uint32_t toggleBit(uint32_t number, int bitPos);
int getHighestSetBit(uint32_t number);
uint32_t getHighestSetBitValue(uint32_t number);
int getLowestSetBit(uint32_t number);
uint32_t getLowestSetBitValue(uint32_t number);

int main(){
    uint32_t reg = 0x000000D5;
    int bitPos;
    
    printf("LSB set: %s\n", checkLSB(reg) ? "true" : "false");
    printf("MSB set: %s\n", checkMSB(reg) ? "true" : "false");
    
    bitPos = 4; //nth bit to get
    printf("The bit in position %d is: %d\n", bitPos, getBit(reg, bitPos));
    
    bitPos = 31; //nth bit to set
    printf("We set the bit in position %d, the new number is: 0x%08x\n", bitPos, setBit(reg, bitPos));

    bitPos = 0; //nth bit to clear
    printf("We clear the bit in position %d, the new number is: 0x%08x\n", bitPos, clearBit(reg, bitPos));

    bitPos = 31; //nth bit to toggle
    printf("We toggle the bit in position %d, the new number is: 0x%08x\n", bitPos, toggleBit(reg, bitPos));

    printf("The highest set bit is in position: %d, its value is: %d\n", getHighestSetBit(reg), getHighestSetBitValue(reg));
    printf("The lowest set bit is in position: %d, its value is: %d\n", getLowestSetBit(reg), getLowestSetBitValue(reg));

}

//1st question: Check if LSB is set or not
bool checkLSB(uint32_t number){
    return (number & (1U << 0));
}

//2nd question: Check if MSB is set or not
bool checkMSB(uint32_t number){
    return (number & (1U << 31));
}

//3rd question: Get specific bit of a number
int getBit(uint32_t number, int bitPos){
    return ((number >> bitPos) & 1);
}

//4th question: Set specific bit of a number
uint32_t setBit(uint32_t number, int bitPos){
    return (number | (1U << bitPos));
}

//5th question: Clear specific bit of a number
uint32_t clearBit(uint32_t number, int bitPos){
    return (number & ~(1U << bitPos));
}

//6th question: Toggle specific bit of a number
uint32_t toggleBit(uint32_t number, int bitPos){
    return (number ^ (1U << bitPos));
}

//7th question: Get highest set bit of a number
int getHighestSetBit(uint32_t number){

    int count = 0;
    if (number == 0) {
        return -1; 
    }
    //shift the number right until its equal to 1 (eg 000001), count shifts
    while (number > 1){
        number = number >> 1;
        count ++; 
    }
    return count;
}

uint32_t getHighestSetBitValue(uint32_t number){
    int position = getHighestSetBit(number);
    
    // If the original number was 0, it returned -1. 
    // We handle that safely by returning a value of 0.
    if (position == -1) {
        return 0; 
    }
    
    // Transform the position into the value
    return (1U << position); 
}

//8th question: Get lowest set bit of a number
int getLowestSetBit(uint32_t number){
    if (number == 0) {
        return -1; 
    }
    
    int count = 0;
    
    // As long as the lowest bit is 0, keep shifting right and counting
    while ((number & 1) == 0) {
        number = number >> 1;
        count++;
    }
    
    return count;
}

uint32_t getLowestSetBitValue(uint32_t number){
    int position = getLowestSetBit(number);
    
    // If the original number was 0, it returned -1. 
    // We handle that safely by returning a value of 0.
    if (position == -1) {
        return 0; 
    }
    
    // Transform the position into the value
    return (1U << position); 
}