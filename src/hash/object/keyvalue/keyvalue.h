

typedef struct privateCHashKeyVal{
    char *key;
    CHashAny *value;

}privateCHashKeyVal;

privateCHashKeyVal * privateCHashKeyVal_new(const char *key);

char * CHash_get_key(CHashKeyVal *keyval);
