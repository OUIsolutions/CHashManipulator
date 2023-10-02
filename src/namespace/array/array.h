

typedef struct CHashArrayModule{

    CHashArray  *(*newArrayEmpty)();
    void (*append_once)(CHashArray *self, CHash *element);
    void  (*delete)(CHashArrayOrObject *self, long index);
    CHash * (*get)(CHashArrayOrObject *self, long position);
    short (*get_type)(CHashArrayOrObject *self, long index);

    CHashArray * (*getArray)(CHashArrayOrObject * self, long index);
    CHashObject * (*getObject)(CHashArrayOrObject * self, long index);
    long (*getLong)(CHashArrayOrObject * self, long index);
    double (*getDouble)(CHashArrayOrObject * self, long index);
    bool (*getBool)(CHashArrayOrObject * self, long index);
    char  * (*getString)(CHashArrayOrObject * self, long index);

}CHashArrayModule;

CHashArrayModule newCHashArrayModule();