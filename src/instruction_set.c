#include "instruction.h"
#include "register_set.h"
#include "instruction_set.h"

void mul(Instruction *instruction)
{
    instruction->result = instruction->r2 * instruction->r3;
}

void movi(Instruction *instruction)
{
    instruction->result = instruction->immediate;
}

void jeq (Instruction * instruction)
{
    
    if((instruction->r2 - instruction->r1) == 0){
        instruction->r1 = (unsigned char)(32 & 0x20);
        instruction->result = instruction->pc+instruction->immediate;
    }
}

void and (Instruction * instruction)
{
    instruction->result = instruction->r2 & instruction->r3;
}

void add(Instruction *instruction)
{
    
    instruction->result = instruction->r2 + instruction->r3;
}
void sub(Instruction *instruction)
{
    instruction->result = instruction->r2 - instruction->r3;
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
