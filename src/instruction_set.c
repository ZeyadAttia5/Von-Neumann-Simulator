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

void jeq (Instruction * instruction)
{
    if((read_register(instruction->r1) - read_register(instruction->r2))==0){
    instruction->result = read_register(32)+1+instruction->immediate;
    }
}

void and (Instruction * instruction)
{
    instruction->result = read_register(instruction->r2) & read_register(instruction->r3);
}
