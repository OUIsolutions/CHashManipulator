

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

typedef  CHashAny CHashPrimitive;
typedef CHashAny ChashArray_OR_CHashObject;
typedef CHashAny CHashArrayItem_OR_CHashKeyVal;
typedef CHashAny CHashArray;
typedef CHashAny CHashObject;
typedef CHashAny CHashString;

CHashAny * privateCHashAny_new(int type, void *value);

CHashPrimitive * privateCHashAny_get_primitive(CHashAny *element);





void CHashPrint(CHashAny *element);

long CHash_get_size(CHashAny *self);






