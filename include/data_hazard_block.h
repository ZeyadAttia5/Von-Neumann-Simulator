#ifndef DATA_HAZARD_H
#define DATA_HAZARD_H

#include "instruction.h"

// function bta5od 3 Intructions w bt synchronize 3la el data hazard
void data_hazard(Instruction* curr_instruction, Instruction* prev_decoded, Instruction* prev_executed);



#endif