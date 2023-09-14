
typedef CHashAny CHashArray;
typedef CHashAny CHashObject;

typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();


CHashArrayItem * CHashArray_new_item(CHashArray *self);



