

typedef struct privateCHashKeyVal{
    char *key;
    CHashAny *value;

}privateCHashKeyVal;

privateCHashKeyVal * privateCHashKeyVal_new(char *key);

char * CHash_get_key(CHashKeyVal *keyval);
