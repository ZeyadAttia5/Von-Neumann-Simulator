#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "register_set.h"
#include "instruction.h"
#include "memory.h"


//                -ADD-**1**--2--**3**
#define TEST_MUL 0b00100000100010001010000000000000

//                 -ADD-**1**--2--**imm**
#define TEST_MOVI 0b00110000100010001010000000000000


/**
 * Splits a string into an array of substrings based on a delimiter.
 *
 * @param a_str The string to be split.
 * @param a_delim The delimiter character used to split the string.
 * @return A dynamically allocated array of strings representing the substrings.
 *         The last element of the array is set to NULL to indicate the end of the list.
 *         The caller is responsible for freeing the memory allocated for the array and its elements.
 */
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/**
 * Trims leading and trailing whitespace from a string.
 *
 * @param str The string to be trimmed.
 * @return A pointer to the trimmed string.
 */
char *trimwhitespace(char *str)
{
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

int convertOpcodeStrToBin(char *opcodeStr)
{
    int opcode;

    if(strcmp(opcodeStr, "ADD") == 0) return 0b0000;
    else if(strcmp(opcodeStr, "SUB") == 0) return 0b0001;
    else if(strcmp(opcodeStr, "MUL") == 0) return 0b0010;
    else if(strcmp(opcodeStr, "MOVI") == 0) return 0b0011;
    else if(strcmp(opcodeStr, "JEQ") == 0) return 0b0100;
    else if(strcmp(opcodeStr, "AND") == 0) return 0b0101;
    else if(strcmp(opcodeStr, "XORI") == 0) return 0b0110;
    else if(strcmp(opcodeStr, "JMP") == 0) return 0b0111;
    else if(strcmp(opcodeStr, "LSL") == 0) return 0b1000;
    else if(strcmp(opcodeStr, "LSR") == 0) return 0b1001;
    else if(strcmp(opcodeStr, "MOVR") == 0) return 0b1010;
    else if(strcmp(opcodeStr, "MOVM") == 0) return 0b1011;
    else return -1;
   
}

/**
 * Converts a register string to an integer representation.
 * 
 * @param regStr The register string to convert.
 * @return The integer representation of the register string.
 */
int convertRegStrToInt(char *regStr)
{
    if(strcmp(regStr, "PC") == 0) return 33;
    
    int regNo = atoi(regStr + 1);
    
    return regNo;
}

/**
 * Parses an array of tokens and generates an instruction based on the tokens.
 * The generated instruction is then written to the specified memory address.
 *
 * @param tokens An array of tokens to be parsed.
 * @param memoryAddress The memory address where the generated instruction will be written.
 */
void parseTokens(char** tokens, const int memoryAddress)
{
    if (tokens)
    {
        
        int instruction = 0;
         
        
        char *token = trimwhitespace(*(tokens));
        int opcode = convertOpcodeStrToBin(token);
        
        instruction |= (opcode << 28);

        token = trimwhitespace(*(tokens + 1));
            

        // check if instruction is R or I format

        if (opcode != 7)
        {

            int r1 = convertRegStrToInt(token);
            instruction |= (r1 << 23);
            
            
            token = trimwhitespace(*(tokens + 2));
            int r2 = convertRegStrToInt(token);
            instruction |= (r2 << 18);
            
            token = trimwhitespace(*(tokens + 3));
            if (opcode == 3 || opcode == 4 || opcode == 6 || opcode == 10 || opcode == 11)
            {
                int immediate = atoi(token);
                instruction |= immediate;
                
            }
            else
            {
                int r3 = convertRegStrToInt(token);
                instruction |= (r3 << 13);
                
                token = trimwhitespace(*(tokens + 2));
                int shamt = atoi(token);

                instruction |= shamt;
                
            }

        }
        else
        {
            int jumpAdress = atoi(token);
            instruction |= jumpAdress;
        }
        
        
        
        write_memory(instruction, memoryAddress);

        
        
        free(tokens);
    }
    
}

/**
 * Reads an assembly file and parses its tokens.
 * 
 * @param assemblyFilePath The path to the assembly file.
 */
void readAssemblyFile(char* assemblyFilePath)
{
    // Open a file in read mode
    FILE *fptr = fopen(assemblyFilePath, "r");

    char *line = NULL;

    size_t len = 0;

    ssize_t read;

    int memoryAddress = 0;

    // Read the file line by line
    while ((read = getline(&line, &len, fptr)) != -1) 
    {
       // split line by space
       char** tokens = str_split(line, ' ');

       // parse tokens
       parseTokens(tokens, memoryAddress);

       memoryAddress++;

    }

}

int main()
{
    


    // TESTING MUL instructions 4 * 3
    
    // populate registers 5 and 2
    write_register(5, 4);
    write_register(2, 3);
    
    
    // create instruction
    Instruction instruction;

    write_memory(TEST_MUL, 0);
    int test_mul = read_memory(0);
    printf("%d\n",test_mul);
    printf("%d\n",TEST_MUL);

    // decode(&instruction, TEST_MOVI);
    decode(&instruction, TEST_MUL);
    execute(&instruction);

    printf("Instruction type: %s\n", instruction.type);
    printf("Instruction opcode: %d\n", instruction.opcode);
    printf("Instruction R1: %d\n", instruction.r1);
    printf("Instruction R2: %d\n", instruction.r2);
    printf("Instruction R3: %d\n", instruction.r3);
    printf("Instruction imm: %d\n", instruction.immediate);
    printf("Instruction result: %d\n", instruction.result);    
    // check if the result is stored in R1
    printf("Register R1: %d\n", read_register(instruction.r1));


    
    
    return 0;
}
