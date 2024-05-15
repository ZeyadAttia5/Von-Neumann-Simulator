#include "../include/data_hazard_block.h"

void data_hazard(Instruction* curr_instruction, Instruction* prev_decoded, Instruction* prev_executed)
{

    // true, don't forward ->  modifying $0 register
    if (curr_instruction->r1 == 0 || 
    (curr_instruction->r2 != prev_decoded->r1 && curr_instruction->r2 != prev_executed->r1 
    && curr_instruction->r3 != prev_decoded->r1 && curr_instruction->r3 != prev_executed->r1))
    {
        // no data hazard because R0 is hardwired
        // do nothing
    }
    else
    {

        
        if (curr_instruction->r3_addr == prev_executed->r1_addr)
        {   
            curr_instruction->r3 = prev_executed->result;
        }
        
        
        if (curr_instruction->r3 == prev_decoded->r1)
        {   
            curr_instruction->r3 = prev_decoded->result;
        }

        if (curr_instruction->r2 == prev_executed->r1 )
        {
            curr_instruction->r2 = prev_executed->result;
        }

        if (curr_instruction->r2 == prev_decoded->r1)
        {
            curr_instruction->r2 = prev_decoded->result;
        }
    }
}

