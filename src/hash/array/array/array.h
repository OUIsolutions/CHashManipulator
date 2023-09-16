


typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();


int CHash_append(CHashArray *iterable, CHashAny *element);

CHashArrayItem_OR_CHashKeyVal  *CHash_get_from_index(ChashArray_OR_CHashObject *iterable, long position);


