#include "../include/register_set.h"
#include "stdio"
#define NUM_REGISTERS 31
#define TOTAL_REGISTERS 33
#define ZERO 0

typedef struct register_set{
    const int r0 = ZERO;
    
    int registers[NUM_REGISTERS];

    int pc;
} register_set;

static register_set register_set_instance;

int read_register(int register_no){
    if (register_no < ZERO || register_no > TOTAL_REGISTERS){
        fprintf(stderr, "Register index must be between 0 & 33");
        return -1;
    }
    if(register_no == TOTAL_REGISTERS) return register_set_instance.pc;

    if(register_no == ZERO) return register_set_instance.rZERO;

    return register_set_instance.registers[register_no];
}


void write_register(int register_no, int write_value){
    if (register_no < ZERO || register_no > TOTAL_REGISTERS){
        fprintf(stderr, "Register index must be between 0 & 33");
        return;
    }

    if(register_no == ZERO){ 
        register_set_instance.zero = value;
        
    }

    if(register_no == TOTAL_REGISTERS) register_set_instance.pc = value;

    else register_set_instance[register_no] = value;
}





