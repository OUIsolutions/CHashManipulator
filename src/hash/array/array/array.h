


typedef struct privateCHashArray{
    long size;
    CHashAny **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();


int privateCHashArray_append(CHashArray *array, CHashAny *element);

CHashAny *CHashArray_get(CHashArray *array, long position);


