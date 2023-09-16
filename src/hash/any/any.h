

enum {
    CHASH_NULL,
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
    int raw_type;
    void *value;
}CHashAny;




CHashAny * private_newCHashAny(int type, void *value);









