

enum {
    CHASH_UNDEFINED,
    CHASH_OBJECT,
    CHASH_ARRAY,
    CHASH_LONG,
    CHASH_DOUBLE,
    CHASH_BOOL,
    CHASH_STRING,
    PRIVATE_CHASH_KEY_VAL,
    PRIVATE_CHASH_ARRAY_ITEM
};

typedef struct CHashAny{
    int type;
    void *value;
}CHashAny;

CHashAny * privateCHashAny_new(int type, void *value);

CHashAny * privateCHashAny_get_value_from_keyvall_or_array_item(CHashAny *element);

void CHash_set(CHashAny *element,CHashAny *value);






