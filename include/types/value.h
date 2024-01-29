#ifndef pranolox_value 
#define pranolox_value

typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
    VAL_OBJ,
    VAL_UTF8_STRING,
    VAL_UTF16_STRING,
    VAL_UTF32_STRING,
    VAL_BYTE_STRING,
    VAL_ARRAY,
    VAL_MAP,
    VAL_SET,
} ValueType;


typedef double Value;

typedef struct {
    int capacity;
    int count; 
    Value *values; //Change This Later To Be More General 
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif