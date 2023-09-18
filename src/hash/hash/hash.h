
typedef struct CHash{

    int type;
    int reference_type;
    struct CHash *father;
    //these is the reference system
    long size;

    union {
        long index;
        char * key;
    };
    //these is the values sysstem
    union {
        char * value_string;
        double value_double;
        long value_long;
        bool value_bool;
        struct CHash **sub_elements;
    };

}CHash;

enum{
    CHASH_NULL,
    CHASH_ARRAY,
    CHASH_OBJECT,
    CHASH_LONG,
    CHASH_STRING
};
enum {
    PRIVATE_CHASH_NOT_A_REFERENCE,
    PRIVATE_CHASH_ARRAY_ITEM,
    PRIVATE_CHASH_KEYVAL
};

typedef CHash CHashArray;
typedef CHash CHashObject;


CHash * privatenewChash_raw();

void CHash_print(CHash *self);

CHashArray * CHash_get_path(CHash *self);

void CHash_free(CHash *self);

CHash * newCHashNULL();