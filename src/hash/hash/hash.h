
typedef struct CHash{

    int type;
    int reference_type;
    struct CHash *father;
    //these is the reference system
    union {
        long index;
        char * key;
        long size;
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
    CHASH_ARRAY,
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