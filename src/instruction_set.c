#include "instruction.h"
#include "register_set.h"
#include "instruction_set.h"

void mul(Instruction *instruction)
{
    instruction->result = read_register(instruction->r2) * read_register(instruction->r3);
}

void movi(Instruction *instruction)
{
    instruction->result = instruction->immediate;
}
void add(Instruction *instruction)
{
    instruction->result = read_register(instruction->r2) + read_register(instruction->r3);
}
void sub(Instruction *instruction)
{
    instruction->result = read_register(instruction->r2) - read_register(instruction->r3);
}
void lsr(Instruction *instruction)
{
    instruction->result = LOGI_RSHIFT_REG(instruction->r2,instruction->shamt);
}

void movr(Instruction *instruction)
{

    instruction->result = instruction->r2 + instruction->immediate;
    
    // must wait for memory in instruction cycle
}

void movm(Instruction *instruction)
{

    instruction->result = instruction->r2 + instruction->immediate;

    // must wait for memory in instruction cycle
}
