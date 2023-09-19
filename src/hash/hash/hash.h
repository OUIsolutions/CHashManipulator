
typedef struct CHash{

    int private_type;
    int private_reference_type;
    struct CHash *private_father;
    long private_size;

    //these is the reference system
    union {
        long private_index;
        char * private_key;
    };
    //these is the values sysstem
    union {
        char * private_value_string;
        double private_value_double;
        long private_value_long;
        bool private_value_bool;
        struct CHash **private_sub_elements;
    };

}CHash;

enum{
    CHASH_NULL,
    CHASH_ARRAY,
    CHASH_OBJECT,
    CHASH_LONG,
    CHASH_DOUBLE,
    CHASH_BOOL,
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

CHash * CHash_copy(CHash *self);

void CHash_free(CHash *self);

bool CHash_equals(CHash *element1, CHash *element2);


CHash * newCHashNULL();