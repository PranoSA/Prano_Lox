
/**
 * @brief
 *
 * First Test:
 * Add Over 256 elements to the chunk
 * And Check if capacity grows to 512
 *
 */

#include <stdio.h>

#include "core/chunk.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{

    Chunk chunk;
    initChunk(&chunk);

    uint8_t *initial_chunk_pointer = chunk.code;

    void *random_malloc = malloc(sizeof(uint8_t) * 256);

    // Check Properly 0 and 266
    if (chunk.capacity == 256)
    {
        printf("Test Passed\n");
    }
    else
    {
        printf("Test Failed\n");
        printf("Expected: 256, Got %d\n", chunk.capacity);
    }

    // Check if Properly 0 coutn
    if (chunk.count == 0)
    {
        printf("Test Passed\n");
    }
    else
    {
        printf("Test Failed\n");
        printf("Expected: 0, Got %d\n", chunk.count);
    }

    for (int i = 0; i < 258; i++)
    {
        writeChunk(&chunk, 1, 1);
    }

    if (chunk.capacity == 512)
    {
        printf("Test Passed\n");
    }
    else
    {
        printf("Test Failed\n");
        printf("Expected: 512, Got %d\n", chunk.capacity);
    }

    // Make sure that the pointer to the chunk is different
    // after the capacity grows
    if (initial_chunk_pointer != chunk.code)
    {
        printf("Test Passed\n");
        printf("Initial: %d, Got %d\n", (int)initial_chunk_pointer, (int)chunk.code);
    }
    else
    {
        printf("Test Failed\n");
        printf("Expected: %d, Got %d\n", (int)initial_chunk_pointer, (int)chunk.code);
    }

    // chunk_destroy(chunk);

    return 0;
}