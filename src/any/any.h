

typedef struct privateCHashAny{
    int type;
    void *value;
}privateCHashAny;

typedef privateCHashAny CHashObject;
typedef privateCHashAny CHashArray;
typedef privateCHashAny CHashInt;
typedef privateCHashAny CHashDouble;
typedef privateCHashAny CHashBool;
typedef privateCHashAny CHashVoid;
typedef privateCHashAny CHashString;

enum {
    CHashTypeUndefined,
    CHashTypeObject,
    CHashTypeArray,
    CHashTypeInt,
    CHashTypeDouble,
    CHashTypeBool,
    CHashTypeVoid,
    CHashTypeString
};



