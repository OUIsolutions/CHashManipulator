

typedef struct CHashNamespace{

    CHash * (*newBool)(bool value);
    bool (*toBool)(CHash *element);

    double  (*toDouble)(CHash *element);
    CHash * (*newDouble)(double value);

    long (*toLong)(CHash *element);
    CHash * (*newLong)(long value);


    


}CHashNamespace;

CHashNamespace newCHashNamespace();