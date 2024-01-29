#include "core/chunk.h"

#include "types/value.h"

#include "core/memory.h"

#include <assert.h>

/**
 * @brief
 *
 * Add OP_CONST To the chunk
 * And Check If that is the content of the chunk
 *
 */

void writeAndReadChunkTest()
{
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN, 1);

    // Check if the chunk contains the OP_RETURN
    printf("%d\n", chunk.code[0]);
    assert(chunk.code[0] == OP_RETURN);

    // Check if the chunk contains the line
    assert(chunk.lines[0] == 1);

    // Check if the chunk contains the count
    assert(chunk.count == 1);

    // Check if the chunk contains the capacity
    assert(chunk.capacity == CHUNK_INIT_CAPACITY);

    // Now Write a constant to the chunk
    int constant = addConstant(&chunk, 1.2);

    // Check if the chunk contains the constant
    assert(chunk.constants.values[0] == 1.2);

    // Check if the chunk contains the constant
    assert(chunk.constants.count == 1);

    // Add Op Code to the chunk
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 2);

    // Check if the chunk contains the OP_CONSTANT
    assert(chunk.code[1] == OP_CONSTANT);

    // Check if the chunk contains the line
    assert(chunk.lines[1] == 1);

    // Check if the chunk contains the count
    assert(chunk.count == 3);

    // Chec if constant index is correct
    int index = chunk.code[2];
    assert(1.2 == chunk.constants.values[index]);

    freeChunk(&chunk);
}

int main(int argc, const char *argv[])
{
    writeAndReadChunkTest();
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN, 1);
    return 0;
}