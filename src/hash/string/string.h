

char * CHash_toString(CHashArray *element);

CTextStack  *CHash_toStack(CHash *element);

CHash * newCHashStackString(CTextStack *element);

CHash * newCHashString(const char *value);