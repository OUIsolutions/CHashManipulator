

typedef struct privateCHashKeyVal{
    char *key;
    CHashAny *value;

}privateCHashKeyVal;

privateCHashKeyVal * privateCHashKeyVal_new(const char *key);

CHashKeyVal  * newCHashKeyVal(const char *key, CHashAny *value);

char * CHash_get_key(CHashKeyVal *keyval);
