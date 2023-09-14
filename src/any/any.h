

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
typedef  CHashAny ChashPrimitive;

CHashAny * privateCHashAny_new(int type, void *value);

ChashPrimitive * privateCHashAny_get_primitive(CHashAny *element);

typedef CHashAny CHashArrayItem_OR_CHashKeyVal;

int CHash_set_value(CHashArrayItem_OR_CHashKeyVal *element, CHashAny *value);

void CHashPrint(CHashAny *element);

long CHash_get_size(CHashAny *self);






