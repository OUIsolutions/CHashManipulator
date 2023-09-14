

typedef struct CHashAny{
    int type;
    void *value;
}CHashAny;

CHashAny * privateCHashAny_new(int type, void *value);


typedef CHashAny CHashObject;
typedef CHashAny CHashKeyVal;
typedef CHashAny CHashArray;
typedef CHashAny CHashArrayItem;
typedef CHashAny CHashLong;
typedef CHashAny CHashDouble;
typedef CHashAny CHashBool;
typedef CHashAny CHashVoid;
typedef CHashAny CHashString;

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

int CHashGetType(CHashAny *element);

char  * CHashGetString(CHashAny *element);

long CHashGetLong(CHashAny *element);

double CHashGetDouble(CHashAny *element);

bool CHashGetBool(CHashAny *element);




