

typedef struct CHashArrayModule{

    CHashArray  *(*newArrayEmpty)();
    void (*append_once)(CHashArray *self, CHash *element);
    void  (*delete)(CHashArray *self, long index);
    CHash * (*get)(CHashArray *self, long position);
    short (*get_type)(CHashArray *self, long index);

    CHashArray * (*getArray)(CHashObject * self, long index);
    CHashObject * (*getObject)(CHashObject * self, long index);
    long (*getLong)(CHashObject * self, long index);
    double (*getDouble)(CHashObject * self, long index);
    bool (*getBool)(CHashObject * self, long index);
    char  * (*getString)(CHashObject * self, long index);

}CHashArrayModule;

CHashArrayModule newCHashArrayModule();