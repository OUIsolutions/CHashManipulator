

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
    CHash * (*newNULL)();

    void (*print)(CHash *self);
    CHashArray * (*get_path)(CHash *self);
    CHash * (*copy)(CHash *self);

    bool (*errors)(CHash *self);
    void (*raise_error)(CHash *self,int error_code,const char *error_menssage, CHash *args);


    bool (*equals)(CHash *element1, CHash *element2);

    long (*get_size)(CHash *self);

    void (*free)(CHash *self);

    CHashObjectModule  object;
    CHashArrayModule array;

}CHashNamespace;

CHashNamespace newCHashNamespace();