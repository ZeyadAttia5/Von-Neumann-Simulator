#include "../include/instruction.h"

char* decode (Instruction* instruction, int reg){
    
    instruction->opcode = (reg >> 28) && 15;
    switch (instruction->opcode)
    {
    case 0b0000:
        instruction->type="ADD";
        break;
    case 0b0001:
        instruction->type="SUB";
        break;
    case 0b0010:
        instruction->type="MUL";
        break;
    case 0b0011:
        instruction->type="MOVI";
        break;
    case 0b0100:
        instruction->type="JEQ";
        break;
    case 0b0101:
        instruction->type="AND";
        break;
    case 0b0110:
        instruction->type="XORI";
        break;
    case 0b0111:
        instruction->type="JMP";
        break;
    case 0b1000:
        instruction->type="LSL";
        break;
    case 0b1001:
        instruction->type="LSR";
        break;
    case 0b1010:
        instruction->type="MOVR";
        break;
    case 0b1011:
        instruction->type="MOVM";
        break;
    default:
    instruction->type="invalid";
        break;
    }

    char* instr_type = instruction->type;
    if( !strcmp(instr_type, "ADD") || !strcmp(instr_type, "SUB") || !strcmp(instr_type, "MUL") || !strcmp(instr_type, "AND") || !strcmp(instr_type, "LSL")|| !strcmp("LSL")){
        populate_R(instruction, reg);
    }
    else if(!strcmp(instr_type, "JMP")){
        populate_J(instruction, reg);
    }
    else{
        populate_I(instruction, reg);
    }

}

void populate_R(Instruction* instruction, int value ){

    instruction->r1 = (value >> 23) & 31;
    instruction->r2 = (value >> 18) & 31;
    instruction->r3 = (value >> 13) & 31;
    instruction->shamt = value & 8191;

}


void populate_I(Instruction* instruction, int value ){

    instruction->r1 = (value >> 23) & 31;
    instruction->r2 = (value >> 18) & 31;
    
    instruction->immediate = value & 262143;


}

void populate_J(Instruction* instruction, int value ){

    
    
    instruction->address = value & 268435455;


}