

typedef struct CHashNamespace{

    CHash * (*newBool)(bool value);
    bool (*toBool)(CHash *element);

    double  (*toDouble)(CHash *element);
    CHash * (*newDouble)(double value);


}CHashNamespace;

CHashNamespace newCHashNamespace();