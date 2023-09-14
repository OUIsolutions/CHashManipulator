

enum {
    CHASH_NOT_EXIST,
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
    int type;
    void *value;
}CHashAny;

typedef  CHashAny ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool;

typedef CHashAny ChashArray_OR_CHashObject;
typedef CHashAny CHashArrayItem_OR_CHashKeyVal;
typedef CHashAny ChashArray_OR_CHashObject_OR_CHashString;
typedef CHashAny CHashArray;
typedef CHashAny CHashObject;
typedef CHashAny CHashString;

CHashAny * privateCHashAny_new(int type, void *value);

ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool * privateCHashAny_get_primitive(CHashAny *element);

long CHash_get_size(ChashArray_OR_CHashObject_OR_CHashString *self);

int CHash_set_item_value(CHashArrayItem_OR_CHashKeyVal *element, ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool *value);


void CHashPrint(CHashAny *element);







