// R instruction format
// OpCode: ADD (0000)
// R1: register 5 (00101)
// R2: register 3 (00011)
// R3: register 12 (01100)
// SHAMT: 5 (0000000000101)
// Binary code: 00000010100011011000000000000101

// I instruction format
// OpCode: MOVI (0011)
// R1: register 5 (00101)
// R2: register 2 (00010)
// Immediate Value: 42 (000000000000101010)
// Binary code: 00110010100010000000000000101010

// R instruction format
// OpCode: MUL (0010)
// R1: register 1 (00001)
// R2: register 2 (00010)
// R3: register 5 (00101)
// SHAMT: 13 (0000000000101)
// Binary code: 0b00100000100010001010000000000000

// R instruction format
// OpCode: SUB (0001)
// R1: register 4 (00100)
// R2: register 6 (00110)
// R3: register 8 (01000)
// SHAMT: 7 (0000000000111)
// Binary code: 00010010000110010000000000000111

// I instruction format
// OpCode: JEQ (0100)
// R1: register 7 (00111)
// R2: register 9 (01001)
// Immediate Value: 25 (000000000000011001)
// Binary code: 01000011101001000000000000011001

// I instruction format
// OpCode: MOVI (0011)
// R1: register 1 (00001)
// R2: register 2 (00010)
// Immediate Value: 40960 (001010000000000000)
// Binary code: 00110000100010001010000000000000


// R instruction format
// OpCode: AND (0101)
// R1: register 3 (00011)
// R2: register 5 (00101)
// R3: register 2 (00010)
// SHAMT: 10 (0000000001010)
// Binary code: 01010001100101000100000000001010

#define test0 0b00000010100011011000000000000101
#define test1 0b00110010100010000000000000101010
#define test2 0b00100000100010001010000000000000
#define test3 0b00010010000110010000000000000111
#define test4 0b01000011101001000000000000011001
#define test5 0b00110000100010001010000000000000
#define test6 0b01010001100101000100000000001010


