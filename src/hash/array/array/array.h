


typedef struct CHashArray{
    long size;
    CHashArrayItem **elements;
}CHashArray;


CHashArray  * newCHashArray();

int CHashArray_append(CHashArray *self, CHashAny *element);

CHashArrayItem *CHashArray_get(CHashArray  *self, long position);


