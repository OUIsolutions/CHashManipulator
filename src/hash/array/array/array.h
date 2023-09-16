


typedef struct CHashArray{
    long size;
    CHashArrayItem **elements;
}CHashArray;


CHashArray  * newCHashArray();

void private_CHashArray_print(CHashArray *array);

int CHashArray_append(CHashArray *array, CHashAny *element);

CHashArrayItem_OR_CHashKeyVal  *CHashArray_get(ChashArray_OR_CHashObject *iterable, long position);


