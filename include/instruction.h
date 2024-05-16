#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../include/BIT_MATH.h"
#include "stdio.h"
#include "string.h"




typedef struct Instruction
{

    unsigned char opcode : 4;
    int r1;
    int r2;
    int r3;
    int r1_addr;
    int r2_addr;
    int r3_addr;
    int shamt : 13;
    int address : 28;
    int immediate : 18;
    char *type;
    int pc;
    int result;
} Instruction;

void decode_instruction(Instruction *instruction, int instruction_value);

void populate_R(Instruction *instruction, int instruction_value);

void populate_I(Instruction *instruction, int instruction_value);

void populate_J(Instruction *instruction, int instruction_value);


void execute_instruction(Instruction *instruction);









#endif
