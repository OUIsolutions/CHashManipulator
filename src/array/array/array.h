


typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();

int CHash_append(ChashArray_OR_CHashObject *array, CHashAny *element);

long CHash_get_size(ChashArray_OR_CHashObject *self);

void private_CHashArray_print(CHashArray *array);

CHashArrayItem * CHashArray_new_item(CHashArray *array);
