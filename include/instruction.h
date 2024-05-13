#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../include/BIT_MATH.h"
#include "stdio.h"
#include "string.h"




typedef struct Instruction
{

    char opcode : 4;
    unsigned char r1 : 5;
    unsigned char r2 : 5;
    unsigned char r3 : 5;
    int shamt : 13;
    int address : 28;
    int immediate : 18;
    char *type;

    int result;
} Instruction;

void decode_instruction(Instruction *instruction, int instruction_value);

void populate_R(Instruction *instruction, int instruction_value);

void populate_I(Instruction *instruction, int instruction_value);

void populate_J(Instruction *instruction, int instruction_value);


void execute_instruction(Instruction *instruction);









#endif
