#include "core/memory.h"

#include <stdlib.h>

#include <stddef.h>

void *reallocate(void *prev_array, int old_size, int new_size)
{

    free(prev_array); // Shouldn't This Take in a size ??

    void *new_array = malloc(new_size);

    return new_array;
}