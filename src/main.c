#include "register_set.h"
#include "instruction.h"
#include "memory.h"


//                -ADD-**1**--2--**3**
#define TEST_MUL 0b00100000100010001010000000000000

//                 -ADD-**1**--2--**imm**
#define TEST_MOVI 0b00110000100010001010000000000000

int main()
{
    
    // TESTING MUL instructions 4 * 3
    
    // populate registers 5 and 2
    write_register(5, 4);
    write_register(2, 3);
    
    
    // create instruction
    Instruction instruction;

    decode(&instruction, TEST_MOVI);
    execute(&instruction);

    printf("Instruction type: %s\n", instruction.type);
    printf("Instruction opcode: %d\n", instruction.opcode);
    printf("Instruction R1: %d\n", instruction.r1);
    printf("Instruction R2: %d\n", instruction.r2);
    printf("Instruction R3: %d\n", instruction.r3);
    printf("Instruction imm: %d\n", instruction.immediate);

    // check if the result is stored in R1
    printf("Register R1: %d\n", read_register(instruction.r1));



    
    return 0;
}
