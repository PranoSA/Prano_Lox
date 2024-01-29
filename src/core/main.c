#include "core/common.h"
#include "core/chunk.h"
#include "core/debug.h"
#include "core/vm.h"

int main(int argc, const char *argv[])
{
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  writeChunk(&chunk, OP_CONSTANT, 123);
  double constant = 1.2;
  int value_index = addConstant(&chunk, constant);
  // writeChunk(&chunk, addConstant(&chunk, 1.2), 2);
  writeChunk(&chunk, value_index, 123);
  writeChunk(&chunk, OP_NEGATE, 123);
  writeChunk(&chunk, OP_RETURN, 155);
  // int constant = addConstant(&chunk, 1.2);
  //  writeChunk(&chunk, OP_CONSTANT, 1);
  //  writeChunk(&chunk, constant, 2);

  // writeChunk(&chunk, OP_RETURN, 5);

  // disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);

  return 0;
}