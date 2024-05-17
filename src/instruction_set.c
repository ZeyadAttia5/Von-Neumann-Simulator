#include "instruction.h"
#include "register_set.h"
#include "instruction_set.h"

void mul(Instruction *instruction)
{
    instruction->result = instruction->r2 * instruction->r3;
}

void movi(Instruction *instruction)
{
    if (instruction->r1_addr == 0)
        instruction->result = 0;
    else
        instruction->result = instruction->immediate;

}

void jeq(Instruction *instruction)
{

    if((instruction->r2 - instruction->r1) == 0){
        instruction->r1_addr = PC;
        instruction->result = instruction->pc + instruction->immediate + 1;
        instruction->will_branch = 1;

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
    instruction->result = LOGI_RSHIFT_REG(instruction->r2, instruction->shamt);
    printf("lsr, r1: %d, r2: %d, r3: %d, result: %d, r1_addr: %d, immediate: %d, shamt: %d, r1_addr: %d\n", instruction->r1, instruction->r2, instruction->r3, instruction->result, instruction->r1_addr, instruction->immediate, instruction->shamt, instruction->r1_addr);

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

// Function to perform XOR immediate operation
void xori(Instruction *instruction)
{
    instruction->result = instruction->r2 ^ instruction->immediate;
}

void lsl(Instruction *instruction)
{
    instruction->result = instruction->r2 << instruction->shamt;

}

void jmp(Instruction *instruction)
{

    // PC = PC|31:28| concatenated with address|27:0|

    // copy the first 4 bits of PC to the first 4 bits of the result
    int result = instruction->pc & 0xF0000000;

    // copy the last 28 bits of the address to the last 28 bits of the result
    result |= instruction->address & 0x0FFFFFFF;

    instruction->r1_addr = PC;

    // save the result in the instruction
    instruction->result = result;


}
