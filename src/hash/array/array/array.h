


typedef struct privateCHashArray{
    long size;
    CHashArrayItem **elements;
}privateCHashArray;

privateCHashArray * privateChashArray_new();

CHashArray  * newCHashArray();

void private_CHashArray_print(CHashArray *array);


int CHash_append_value_to_Array_OR_Object(ChashArray_OR_CHashObject *array, CHashAny *element);

CHashArrayItem_OR_CHashKeyVal  *CHash_get_item_from_position(ChashArray_OR_CHashObject *array,long position);


CHashArrayItem * CHashArray_new_item(CHashArray *array);

