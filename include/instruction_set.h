#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include "instruction.h"

void mul(Instruction *instruction);
void movi(Instruction *instruction);
void jeq(Instruction * instruction);
void and (Instruction * instruction);

void add(Instruction *instruction);
void sub(Instruction *instruction);
void lsr(Instruction *instruction);
void movr(Instruction *instruction);
void movm(Instruction *instruction);

void xori(Instruction *instruction);
void lsl(Instruction *instruction);
void jmp(Instruction *instruction);


#endif
