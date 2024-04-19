#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

// private Memory struct
typedef struct Memory {
    int memory_block[MAX_NUMBER_OF_ROWS];
}Memory;

//static to ensure file scope.
//private Memory Instance 
static Memory memoryInstance;

// Global Access point for the memoryInstance
MemoryPtr createMemory(){
    static MemoryPtr mem = &memoryInstance;
    // printf("address is %p\n", mem);
    return mem;
}



// Write data to the memory block at the specified address
void write(MemoryPtr mem, int data, int addr) {
    if (addr >= MIN_NUMBER_OF_ROWS && addr < MAX_NUMBER_OF_ROWS) {
        mem->memory_block[addr] = data;
    } else {
        fprintf(stderr, "Error: Invalid memory access\n");
    }
}

// Read data from the memory block at the specified address
int read(MemoryPtr mem, int addr) {
    if (addr >= MIN_NUMBER_OF_ROWS && addr < MAX_NUMBER_OF_ROWS) {
        return mem->memory_block[addr];
    } else {
        fprintf(stderr, "Error: Invalid memory access\n");
        return -1; // or handle error in a suitable way
    }
}
