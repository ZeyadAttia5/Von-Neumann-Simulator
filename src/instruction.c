#include "instruction.h"
#include "register_set.h"

/// @brief decode instruction
/// @param instruction pointer to instruction struct
/// @param reg value fetched from memory
/// @return
char *decode(Instruction *instruction, int reg)
{

    instruction->opcode = (reg >> 28) & 15;
    switch (instruction->opcode)
    {
    case 0b0000:
        instruction->type = "ADD";
        break;
    case 0b0001:
        instruction->type = "SUB";
        break;
    case 0b0010:
        instruction->type = "MUL";
        break;
    case 0b0011:
        instruction->type = "MOVI";
        break;
    case 0b0100:
        instruction->type = "JEQ";
        break;
    case 0b0101:
        instruction->type = "AND";
        break;
    case 0b0110:
        instruction->type = "XORI";
        break;
    case 0b0111:
        instruction->type = "JMP";
        break;
    case 0b1000:
        instruction->type = "LSL";
        break;
    case 0b1001:
        instruction->type = "LSR";
        break;
    case 0b1010:
        instruction->type = "MOVR";
        break;
    case 0b1011:
        instruction->type = "MOVM";
        break;
    default:
        instruction->type = "invalid";
        break;
    }

    char *instr_type = instruction->type;
    if (!strcmp(instr_type, "ADD") || !strcmp(instr_type, "SUB") || !strcmp(instr_type, "MUL") || !strcmp(instr_type, "AND") || !strcmp(instr_type, "LSL") || !strcmp(instr_type, "LSL"))
    {
        populate_R(instruction, reg);
    }
    else if (!strcmp(instr_type, "JMP"))
    {
        populate_J(instruction, reg);
    }
    else
    {
        populate_I(instruction, reg);
    }
}

/// @brief Instruction R Format: Opcode(4) | R1(5) | R2(5) | R3(5) | Shamt(13)
/// @param instruction
/// @param value
void populate_R(Instruction *instruction, int value)
{

    char r1 = (value >> 23) & 31;
    char r2 = (value >> 18) & 31;
    char r3 = (value >> 13) & 31;
    int shamt = value & 8191;

    instruction->r1 = r1;
    instruction->r2 = r2;
    instruction->r3 = r3;
    instruction->shamt = shamt;

    // clear other fields
    instruction->address = 0;
    instruction->immediate = 0;
}

/// @brief Instruction I Format: Opcode(4) | R1(5) | R2(5) | Immediate(18)
/// @param instruction
/// @param value
void populate_I(Instruction *instruction, int value)
{

    int r1 = (value >> 23) & 31;
    int r2 = (value >> 18) & 31;
    int immediate = value & 262143;

    instruction->r1 = r1;
    instruction->r2 = r2;

    instruction->immediate = immediate;

    // clear other fields
    instruction->address = 0;
    instruction->shamt = 0;
}

/// @brief Instruction J Format: Opcode(4) | Address(28)
/// @param instruction
/// @param value
void populate_J(Instruction *instruction, int value)
{

    instruction->address = value & 268435455;

    // clear other fields
    instruction->r1 = 0;
    instruction->r2 = 0;
    instruction->r3 = 0;
    instruction->shamt = 0;
    instruction->immediate = 0;
}

/// @brief execute instruction
/// @param instruction
void execute(Instruction *instruction)
{
    char *instr_type = instruction->type;

    if (!strcmp(instr_type, "MUL"))
    {
        mul(instruction);
    }
    else if (!strcmp(instr_type, "MOVI"))
    {
        movi(instruction);
    }
    else
    {
        printf("Invalid Instruction\n");
    }
}

void mul(Instruction *instruction)
{
    int result = read_register(instruction->r2) * read_register(instruction->r3);
    write_register(instruction->r1, result);
}

void movi(Instruction *instruction)
{
    write_register(instruction->r1, instruction->immediate);
}
