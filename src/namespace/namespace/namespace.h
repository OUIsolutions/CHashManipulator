

typedef struct CHashNamespace{

    CHash * (*newBool)(bool value);
    bool (*toBool)(CHash *element);


    CHash * (*newDouble)(double value);
    double  (*toDouble)(CHash *element);


    CHash * (*newLong)(long value);
    long (*toLong)(CHash *element);


    CHash * (*newStackString)(CTextStack *element);
    CTextStack  *(*toStack)(CHash *element);


    CHash * (*newString)(const char *value);
    char * (*toString)(CHashArray *element);

    CHashObjectModule  object;
    CHashArrayModule array;
    
}CHashNamespace;

CHashNamespace newCHashNamespace();