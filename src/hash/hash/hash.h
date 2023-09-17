
typedef struct CHash{

    int type;
    union {
        long index;
        char * key;
    };
    

}CHash;

