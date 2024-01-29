#include "core/vm.h"
#include "core/chunk.h"
#include "core/debug.h"

int main()
{

    initVM();

    Chunk chunk;

    initChunk(&chunk);

    writeChunk(&chunk, OP_CONSTANT, 123);

    writeChunk(&chunk, addConstant(&chunk, 1.2), 2);

    writeChunk(&chunk, OP_NEGATE, 123);

    // disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeVM();

    freeChunk(&chunk);

    return 0;
}