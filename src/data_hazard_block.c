#include "../include/data_hazard_block.h"

void data_hazard(Instruction* curr_instruction, Instruction* prev_decoded, Instruction* prev_executed)
{

    // true, don't forward ->  modifying $0 register
    if (curr_instruction->r1_addr == 0 ||
    (curr_instruction->r2_addr != prev_decoded->r1_addr && curr_instruction->r2_addr != prev_executed->r1_addr
    && curr_instruction->r3_addr != prev_decoded->r1_addr && curr_instruction->r3_addr != prev_executed->r1_addr
    && prev_decoded->r2_addr == prev_executed->r1_addr && prev_decoded->r3_addr == prev_executed->r1_addr))
    {
        // no data hazard because R0 is hardwired
        // do nothing
    }
    else
    {



        if (curr_instruction->r3_addr != 0 && curr_instruction->r3_addr == prev_executed->r1_addr && (!strcmp(curr_instruction->type, "ADD") || !strcmp(curr_instruction->type, "SUB") || !strcmp(curr_instruction->type, "MUL") || !strcmp(curr_instruction->type, "AND") || !strcmp(curr_instruction->type, "LSL") || !strcmp(curr_instruction->type, "LSL")) )
        {
            curr_instruction->r3 = prev_executed->result;

        }

        if (curr_instruction->r3_addr != 0 && curr_instruction->r3_addr == prev_decoded->r1_addr && (!strcmp(curr_instruction->type, "ADD") || !strcmp(curr_instruction->type, "SUB") || !strcmp(curr_instruction->type, "MUL") || !strcmp(curr_instruction->type, "AND") || !strcmp(curr_instruction->type, "LSL") || !strcmp(curr_instruction->type, "LSL")) )
        {   
            curr_instruction->r3 = prev_decoded->result;

        }

        if (curr_instruction->r2_addr != 0 && curr_instruction->r2_addr == prev_executed->r1_addr && curr_instruction->type != NULL && prev_executed->type != NULL && strcmp(curr_instruction->type, "MOVI"))
        {
            curr_instruction->r2 = prev_executed->result;
        }


        if (curr_instruction->r2_addr != 0 && curr_instruction->r2_addr == prev_decoded->r1_addr && curr_instruction->type != NULL && prev_decoded->type != NULL && strcmp(curr_instruction->type, "MOVI") )
        {
            curr_instruction->r2 = prev_decoded->result;
        }

        if (curr_instruction->r1_addr != 0 && curr_instruction->r1_addr == prev_executed->r1_addr && curr_instruction->type != NULL && prev_executed->type != NULL && !strcmp(curr_instruction->type, "MOVM"))
        {
            curr_instruction->r1 = prev_executed->result;
        }

        if (curr_instruction->r1_addr != 0 && curr_instruction->r1_addr == prev_decoded->r1_addr && curr_instruction->type != NULL && prev_decoded->type != NULL && !strcmp(curr_instruction->type, "MOVM"))
        {
            curr_instruction->r1 = prev_decoded->result;
        }


    }
}

