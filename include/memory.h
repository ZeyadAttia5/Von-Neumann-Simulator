#ifndef MEMORY_H
#define MEMORY_H

#define MAX_NUMBER_OF_ROWS 2048
#define MIN_NUMBER_OF_ROWS 0

#define MAX_NUMBER_OF_COLS 32
#define MIN_NUMBER_OF_COLS 0


int read_memory(int addr);
void write_memory(int data, int addr);

void set_bit(int row, int col);
void clr_bit(int row, int col);
int read_bit(int row, int col);


#endif