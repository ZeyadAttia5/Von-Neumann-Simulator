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

void jeq(Instruction *instruction)
{
    if ((read_register(instruction->r2) - read_register(instruction->r3)) == 0)
    {
        instruction->r1 = 32;
        instruction->result = read_register(32) + 1 + instruction->immediate;
    }
}

void and (Instruction * instruction)
{
    instruction->result = read_register(instruction->r2) & read_register(instruction->r3);
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
    instruction->result = LOGI_RSHIFT_REG(instruction->r2, instruction->shamt);
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
    instruction->result = read_register(instruction->r2) ^ instruction->immediate;
}

void lsl(Instruction *instruction)
{
    instruction->result = read_register(instruction->r2) << instruction->shamt;
}

void jmp(Instruction *instruction)
{
    // PC = PC|31:28| concatenated with address|27:0|

    // copy the first 4 bits of PC to the first 4 bits of the result
    int result = read_register(PC) & 0xF0000000;

    // copy the last 28 bits of the address to the last 28 bits of the result
    result |= instruction->address & 0x0FFFFFFF;

    // save the result in the instruction
    instruction->result = result;
}
