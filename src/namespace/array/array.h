

typedef struct CHashArrayModule{

    CHashArray  *(*newArrayEmpty)();
    void (*append_once)(CHashArray *self, CHash *element);

    void  (*set)(CHashArrayOrObject *self, long index,CHash *element);
    void  (*remove)(CHashArrayOrObject *self, long index);
    CHash * (*get)(CHashArrayOrObject *self, long position);
    long (*find)(CHashArray *self, CHash *element);
    long (*find_cleanning_element)(CHashArray *self, CHash *element);

    short (*get_type)(CHashArrayOrObject *self, long index);

    CHashArray * (*getArray)(CHashArrayOrObject * self, long index);
    CHashObject * (*getObject)(CHashArrayOrObject * self, long index);

    double (*getNumber)(CHashArrayOrObject * self, long index);
    bool (*getBool)(CHashArrayOrObject * self, long index);
    char  * (*getString)(CHashArrayOrObject * self, long index);

}CHashArrayModule;

CHashArrayModule newCHashArrayModule();