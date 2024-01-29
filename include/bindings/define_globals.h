

typedef struct {
    // Global Functions Tables 

    // Global Class Tables 

    // 
} Environment;


// What is the Environment and how is it set by function 

// What is the "Environment Exactyl??"
// Global Environment


void SetGlobalData(char * key, void * (*func)(void *), void * data));

typedef struct {
    //Dynamic Array 
    Value * args;
} FunctionArguments;