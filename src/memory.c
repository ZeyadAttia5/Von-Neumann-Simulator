#include "../include/memory.h"
#include "../include/BIT_MATH.h"
#include <stdlib.h>
#include <stdio.h>

// private Memory struct
typedef struct Memory
{
    int memory_block[MAX_NUMBER_OF_ROWS];
} Memory;





// Write data to the memory block at the specified address
void write_memory(int data, int addr)
{
    if (mem == NULL)
    {
        fprintf(stderr, "Error: Memory is NULL\n");
        return;
    }

    if (addr >= MIN_NUMBER_OF_ROWS && addr < MAX_NUMBER_OF_ROWS)
    {
        mem->memory_block[addr] = data;
    }
    else
    {
        fprintf(stderr, "Error: Invalid memory access\n");
    }
}

// Read data from the memory block at the specified address
int read_memory(int addr)
{
    if (mem == NULL)
    {
        fprintf(stderr, "Error: Memory is NULL\n");
        return -1;
    }

    if (addr >= MIN_NUMBER_OF_ROWS && addr < MAX_NUMBER_OF_ROWS)
    {
        return mem->memory_block[addr];
    }
    else
    {
        fprintf(stderr, "Error: Invalid memory access\n");
        return -2; // or handle error in a suitable way
    }
}

// Write data to the memory block at the specified address
void set_bit(int row, int col)
{
    if (mem == NULL)
    {
        fprintf(stderr, "Error: Memory is NULL\n");
        return;
    }

    if (row >= MIN_NUMBER_OF_ROWS && row < MAX_NUMBER_OF_ROWS)
    {
        if (col >= MIN_NUMBER_OF_COLS && col < MAX_NUMBER_OF_COLS)
        {
            SET_BIT(mem->memory_block[row], col);
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid memory access\n");
    }
}

void clr_bit(int row, int col)
{
    if (mem == NULL)
    {
        fprintf(stderr, "Error: Memory is NULL\n");
        return;
    }
    if (row >= MIN_NUMBER_OF_ROWS && row < MAX_NUMBER_OF_ROWS)
    {
        if (col >= MIN_NUMBER_OF_COLS && col < MAX_NUMBER_OF_COLS)
        {
            CLR_BIT(mem->memory_block[row], col);
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid memory access\n");
    }
}

// Read data from the memory block at the specified address
int read_bit(int row, int col)
{
    if (row >= MIN_NUMBER_OF_ROWS && row < MAX_NUMBER_OF_ROWS)
    {
        if (col >= MIN_NUMBER_OF_COLS && col < MAX_NUMBER_OF_COLS)
        {
            return GET_BIT(mem->memory_block[row], col);
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid memory access\n");
        return -1; // or handle error in a suitable way
    }
}