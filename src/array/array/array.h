
typedef CHashAny CHashArray;
typedef CHashAny CHashObject;

typedef struct privateCHashArray{
    long size;
    CHashAny *elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();

CHashObject * newCHashObject();


void CHashArray_append(CHashArray *self, CHashArrayItem *element);



