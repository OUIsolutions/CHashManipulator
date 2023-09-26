

typedef struct CHashArrayModule{

    CHashArray  *(*newArrayEmpty)();
    void (*append_once)(CHashArray *self, CHash *element);
    void  (*delete)(CHashArray *self, long index);
    CHash * (*get)(CHashArray *self, long position);


}CHashArrayModule;

CHashArrayModule newCHashArrayModule();