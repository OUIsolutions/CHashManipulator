

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

typedef CHashAny CHashIterable;
typedef CHashAny CHashArray;
typedef CHashAny CHashObject;


CHashAny * privateCHashAny_new(int type, void *value);

CHashAny * privateCHashAny_get_primitive(CHashAny *element);

long CHash_get_size(CHashIterable *element);

int CHash_get_type(CHashAny *element);

int CHash_set(CHashAny *element, CHashAny *value);








