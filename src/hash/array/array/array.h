


typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();

void private_CHashArray_print(CHashArray *array);


int CHash_append(ChashArray_OR_CHashObject *array, CHashAny *element);

CHashArrayItem * CHashArray_new_item(CHashArray *array);

