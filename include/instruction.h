#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../include/BIT_MATH.h"
#include "stdio.h"
#include "string.h"




typedef struct Instruction
{

    char opcode : 4;
    char r1 : 5;
    char r2 : 5;
    char r3 : 5;
    int shamt : 13;
    int address : 28;
    int immediate : 18;
    char *type;

    int result;
} Instruction;

void decode_instruction(Instruction *instruction, int reg);

void populate_R(Instruction *instruction, int value);

void populate_I(Instruction *instruction, int value);

void populate_J(Instruction *instruction, int value);


void execute_instruction(Instruction *instruction);









#endif
