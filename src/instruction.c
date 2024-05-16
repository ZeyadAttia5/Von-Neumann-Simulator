#include "instruction.h"
#include "register_set.h"
#include "memory.h"
#include "instruction_set.h"
#include "BIT_MATH.h"

/// @brief decode instruction
/// @param instruction pointer to instruction struct
/// @param instruction_value value fetched from memory
void decode_instruction(Instruction *instruction, int instruction_value)
{

    instruction->opcode = (((unsigned int) instruction_value) >> 28) & 0xF;

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
    case 11:
        instruction->type = "MOVM";
        break;
    default:
        instruction->type = "invalid";
        break;
    }

    char *instr_type = instruction->type;

    if (!strcmp(instr_type, "ADD") || !strcmp(instr_type, "SUB") || !strcmp(instr_type, "MUL") || !strcmp(instr_type, "AND") || !strcmp(instr_type, "LSL") || !strcmp(instr_type, "LSL"))
    {
        populate_R(instruction, instruction_value);
    }
    else if (!strcmp(instr_type, "JMP"))
    {
        populate_J(instruction, instruction_value);
    }
    else
    {
        populate_I(instruction, instruction_value);
    }
}

/// @brief Instruction R Format: Opcode(4) | R1(5) | R2(5) | R3(5) | Shamt(13)
/// @param instruction
/// @param instruction_value
void populate_R(Instruction *instruction, int instruction_value)
{

    char r1 = (instruction_value >> 23) & 31;
    int r2 = read_register((instruction_value >> 18) & 31);
    int r3 = read_register((instruction_value >> 13) & 31);

    char r1_addr = (instruction_value >> 23) & 31;
    char r2_addr = ((instruction_value >> 18) & 31);
    char r3_addr = ((instruction_value >> 13) & 31);
    int shamt = instruction_value & 8191;

    instruction->r1 = r1;
    instruction->r2 = r2;
    instruction->r3 = r3;

    instruction->r1_addr = r1_addr;
    instruction->r2_addr = r2_addr;
    instruction->r3_addr = r3_addr;
    instruction->shamt = shamt;

    // clear other fields
    instruction->address = -1;
    instruction->immediate = -1;
}

/// @brief Instruction I Format: Opcode(4) | R1(5) | R2(5) | Immediate(18)
/// @param instruction
/// @param instruction_value
void populate_I(Instruction *instruction, int instruction_value)
{
    int r1 = read_register((instruction_value >> 23) & 31);

    int r1_addr = (instruction_value >> 23) & 31;

    int r2 = read_register((instruction_value >> 18) & 31);

    int r2_addr = ((instruction_value >> 18) & 31);

    int immediate = instruction_value & 262143;

    // check if immediate valiue is negative
    if (GET_BIT(immediate, 17))
        immediate = immediate | 0xFFFC0000;

    instruction->r1 = r1;

    instruction->r2 = r2;

    instruction->r1_addr = r1_addr;

    instruction->r2_addr = r2_addr;

    instruction->immediate = immediate;

    if (!strcmp(instruction->type, "MOVI")) {
        instruction->result = immediate;
        instruction->r2_addr = 0;
    }

    // clear other fields
    instruction->address = -1;
    instruction->shamt = -1;
    instruction->r3 = -1;
}

/// @brief Instruction J Format: Opcode(4) | Address(28)
/// @param instruction
/// @param instruction_value
void populate_J(Instruction *instruction, int instruction_value)
{

    int address = instruction_value & 268435455;

    if (GET_BIT(address, 27))
        address *= -1;

    instruction->address = address;

    // clear other fields
    instruction->r1 = -1;
    instruction->r2 = -1;
    instruction->r3 = -1;
    instruction->r1_addr = -1;
    instruction->r2_addr = -1;
    instruction->r3_addr = -1;
    instruction->shamt = -1;
    instruction->immediate = -1;
}

/// @brief execute instruction
/// @param instruction
void execute_instruction(Instruction *instruction)
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
    else if (!strcmp(instr_type, "ADD"))
    {
        add(instruction);
    }
    else if (!strcmp(instr_type, "SUB"))
    {
        sub(instruction);
    }
    else if (!strcmp(instr_type, "LSR"))
    {
        lsr(instruction);
    }
    else if (!strcmp(instr_type, "MOVR"))
    {
        movr(instruction);
    }
    else if (!strcmp(instr_type, "MOVM"))
    {
        movm(instruction);
    }
    else if (!strcmp(instr_type, "AND"))
    {
        and(instruction);
    }
    else if (!strcmp(instr_type, "JEQ"))
    {
        jeq(instruction);
    }
    else if (!strcmp(instr_type, "JMP"))
    {
        jmp(instruction);
    }
    else if (!strcmp(instr_type, "XORI"))
    {
        xori(instruction);
    }
    else if (!strcmp(instr_type, "LSL"))
    {
        lsl(instruction);
    }
    else
    {

        printf("Invalid Instruction: %s\n", instr_type);
    }
}
