#ifndef pranolox_memory_h 
#define pranolox_memory_h

#include <stddef.h>

#define GROW_CAPACITY(capacity) \
    (capacity*2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type)*oldCount, sizeof(type)*newCount)

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

void* reallocate(void* pointer, int oldSize, int newSize);

#endif 