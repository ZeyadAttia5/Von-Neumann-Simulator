#include "../include/memory.h"
#include "stdio.h"

int main()
{

    MemoryPtr mem = createMemory();
    write(mem, 31, 12);
    int x = read(mem, 12);
    printf("The value stored in mem1 is %d\n", x);


    MemoryPtr mem2 = createMemory();
    write(mem2, 32, 12);
    int x2 = read(mem2, 12);
    printf("The value stored in mem2 is %d\n", x2);

    int x1 = read(mem, 12);
    printf("The value stored in mem1 is %d\n", x1);

    set_bit(mem, 1, 0);
    printf("The value stored in mem1 is %d\n", read(mem, 1));

    
    
    // MemoryPtr mem3;
    // write(mem3, 31, 12);
    // int x3 = read(mem3, 12);
    // printf("The value stored in mem2 is %d\n", x3);

    // singleton
    //  First-Class Abstarct Data Type
}