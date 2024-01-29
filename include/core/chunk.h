#ifndef pranolox_chunk_h
#define pranolox_chunk_h

#include "core/common.h"
#include "types/value.h"

// OpCode is an enum of all the possible opcodes
// that can be used in the bytecode
// This Represents the Operation of the next instruction

typedef enum
{
  OP_CONSTANT,
  OP_RETURN,    // Return
  OP_NEGATE,    // - (constant) -> Before or After Constant, Can I treat This differently?
  OP_ADD,       // +
  OP_SUBTRACT,  // -
  OP_FACTORIAL, // (constant)! 4 + 3! or 4 + !3 -> Can I treat These Different?
  // What about (4+3)! or 4+3! -> Can I treat These Different?
  // This Would Be At the Level of the Lexican Analysis
  // Binary Operators -> +, -, *, /, &, |, ^, <<, >>, %, **
  OP_BIN_AND,         //&
  OP_BIN_OR,          // |
  OP_BIN_XOR,         // ^
  OP_BIN_LEFT_SHIFT,  // <<
  OP_BIN_RIGHT_SHIFT, // >>

  // Boolean Types
  OP_NOT, // !

  // Numbers ??
  OP_MODULUS,  // %
  OP_MULTIPLY, // *
  OP_DIVIDE,   // /
} OpCode;

/*
    Represents our Programs Instructions ??
    We will interpret byte by byte values of the code
    When executing it
*/
typedef struct
{
  int count;
  int capacity; // When Do We Grow Our Array
  uint8_t *code;
  ValueArray constants;
  int *lines;
} Chunk;

/**
    Now We Are Exposing Functions that operate on Chunks Here

    Some of these are essentially static methods

    The others maybe per instance methods
*/

#define CHUNK_INIT_CAPACITY 256

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
void freeChunk(Chunk *chunk);
int addConstant(Chunk *chunk, Value value);

#endif