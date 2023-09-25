

typedef struct CHashNamespace{

    CHash * (*newBool)(bool value);
    CHash * (*newDouble)(double value);
    CHash * (*newLong)(long value);
    CHash * (*newStackString)(CTextStack *element);
    CHash * (*newString)(const char *value);


}CHashNamespace;

CHashNamespace newCHashNamespace();