

typedef struct CHashArrayModule{

    CHashArray  *(*newArrayEmpty)();
    void (*append_once)(CHashArray *self, CHash *element);

    void  (*set)(CHashArrayOrObject *self, long index,CHash *element);
    void  (*remove)(CHashArrayOrObject *self, long index);
    CHash * (*get)(CHashArrayOrObject *self, long position);
    long (*find)(CHashArray *self, CHash *element);
    long (*find_Number)(CHashArray *self, double element);
    long (*find_Bool)(CHashArray *self, bool  element);
    long (*find_String)(CHashArray *self, const char *element);
    void (*foreach)(CHashArray *self,void  (*callback)(CHash *current));
    void (*foreach_with_args)(CHashArray *self,void  (*callback)(CHash *current,va_list args),...);
    CHashArray * (*map)(CHashArray *self,CHash* (*callback)(CHash *current));
    CHashArray * (*map_with_args)(CHashArray *self,CHash* (*callback)(CHash *current,va_list args),...);


    short (*get_type)(CHashArrayOrObject *self, long index);

    CHashArray * (*getArray)(CHashArrayOrObject * self, long index);
    CHashObject * (*getObject)(CHashArrayOrObject * self, long index);

    double (*getNumber)(CHashArrayOrObject * self, long index);
    bool (*getBool)(CHashArrayOrObject * self, long index);
    char  * (*getString)(CHashArrayOrObject * self, long index);
    CTextStack  * (*getStack)(CHashObject * self, long index);

}CHashArrayModule;

CHashArrayModule newCHashArrayModule();