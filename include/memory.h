#ifndef MEMORY_H
#define MEMORY_H

#define MAX_NUMBER_OF_ROWS 2048
#define MIN_NUMBER_OF_ROWS 0

#define MAX_NUMBER_OF_COLS 32
#define MIN_NUMBER_OF_COLS 0

typedef struct Memory* MemoryPtr;


// public Memory struct
// typedef struct Memory {
//     int memory_block[MAX_NUMBER_OF_ROWS];
// }Memory;


int read(MemoryPtr mem, int addr);
void write(MemoryPtr mem, int data, int addr);

void set_bit(MemoryPtr mem, int row, int col);
void clr_bit(MemoryPtr mem, int row, int col);
int read_bit(MemoryPtr mem, int row, int col);
MemoryPtr createMemory();

#endif