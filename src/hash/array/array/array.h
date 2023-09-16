


typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();


int privateCHashArray_append(CHashArray *array, CHashAny *element);

CHashAny *privateCHashArray_get_at_index(CHashArray *array, long position);


