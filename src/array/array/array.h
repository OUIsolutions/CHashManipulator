
typedef CHashAny CHashArray;
typedef CHashAny CHashObject;

typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();

int CHashArray_append(CHashArray *array, CHashAny *element);


void private_CHashArray_print(CHashArray *array);

CHashArrayItem * CHashArray_new_item(CHashArray *array);
