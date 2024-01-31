#include <stdlib.h>

#include "core/chunk.h"
#include "core/memory.h"
#include <stddef.h>
#include "types/value.h"

void initChunk(Chunk *chunk)
{
    chunk->count = 0;
    chunk->capacity = CHUNK_INIT_CAPACITY;
    chunk->code = malloc(sizeof(uint8_t) * chunk->capacity);
    chunk->lines = malloc(sizeof(int) * chunk->capacity);
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line)
{

    if (chunk->capacity > chunk->count + 1)
    {

        chunk->code[chunk->count] = byte;
        chunk->lines[chunk->count] = line;
        chunk->count += 1;
    }
    else
    {
        chunk->capacity = GROW_CAPACITY(chunk->capacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, chunk->capacity, chunk->capacity);
        chunk->code[chunk->count] = byte;

        chunk->lines = GROW_ARRAY(int, chunk->lines, chunk->capacity, chunk->capacity);
        chunk->lines[chunk->count] = line;

        chunk->count += 1;

        // uint8_t *old_code = chunk->code;
        // chunk->code = malloc(sizeof(uint8_t) * chunk->capacity * 2);
        // chunk->capacity *= 2;
    }
}

void freeChunk(Chunk *chunk)
{
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
    freeValueArray(&chunk->constants);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
}

int addConstant(Chunk *chunk, Value value)
{
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}