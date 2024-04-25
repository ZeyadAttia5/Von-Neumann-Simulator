#include <stdio.h>


/// @brief Private Register File
typedef struct Register_File
{

    // 32 registers
    int reg[32];

    // Program Counter
    int pc;

} Register_File;


/// @brief Singleton Register File
static Register_File reg;

/// @brief read the value from the register_no
/// @param register_no 
/// @return 
int read_register(int register_no)
{
    if (register_no < 0 || register_no > 32)
    {
        fprintf(stderr, "Invalid register number\n");
        return -1;
    }

    if (register_no == 0)
    {
        // R0 is always 0
        return 0;
    }
    if (register_no == 32)
    {
        // PC register
        return reg.pc;
    }
    else
    {
        return reg.reg[register_no];
    }
}

/// @brief write the write_value to the register_no
/// @param register_no 
/// @param write_value 
void write_register(int register_no, int write_value)
{

    if (register_no < 0 || register_no > 32)
    {
        fprintf(stderr, "Invalid register number\n");
        // return -1;
    }

    if (register_no == 0)
    {
        // R0 is always 0; cant be overwritten
        return;
    }
    if (register_no == 32)
    {
        // PC register
        reg.pc = write_value;
    }
    else
    {
        reg.reg[register_no] = write_value;
    }
}