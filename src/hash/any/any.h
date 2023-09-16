

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

typedef  CHashAny ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL;

typedef CHashAny ChashArray_OR_CHashObject;
typedef CHashAny CHashArrayItem_OR_CHashKeyVal;
typedef CHashAny ChashArray_OR_CHashObject_OR_CHashString;
typedef CHashAny CHashArray;
typedef CHashAny CHashArrayItem;
typedef CHashAny CHashObject;
typedef CHashAny CHashKeyVal;
typedef CHashAny CHashString;


CHashAny * privateCHashAny_new(int type, void *value);

ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL * privateCHashAny_get_primitive(CHashAny *element);

long CHash_get_size(ChashArray_OR_CHashObject_OR_CHashString *element);

int CHash_get_type(CHashAny *element);

int CHash_set(CHashArrayItem_OR_CHashKeyVal *element, ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL *value);


void CHashPrint(CHashAny *element);







