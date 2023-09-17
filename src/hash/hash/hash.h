
typedef struct CHash{

    int type;
    union {
        long index;
        char * key;
    };

    union {
        char * value_string;
        double value_double;
        long value_long;
    };
    

}CHash;

