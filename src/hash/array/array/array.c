

privateCHashArray * privateChashArray_new(){
    privateCHashArray * self = (privateCHashArray*)malloc(sizeof (privateCHashArray));
    self->size = 0;
    self->elements = malloc(0);
    return self;
}

CHashArray  * newCHashArray(){
    privateCHashArray  *self = privateChashArray_new();
    return privateCHashAny_new(CHASH_ARRAY,self);
}

int CHash_append(ChashArray_OR_CHashObject *array, CHashAny *element){

    privateCHashArray  *self = (privateCHashArray*)(array->value);
    self->elements = realloc(self->elements,(self->size +1) * sizeof(CHashAny**));

    if(element->type == PRIVATE_CHASH_ARRAY_ITEM || element->type == PRIVATE_CHASH_KEY_VAL){

        if(element->type == PRIVATE_CHASH_ARRAY_ITEM){
            privateCHashArrayItem   *casted = (privateCHashArrayItem*)element->value;
            casted->position = self->size;
        }

        self->elements[self->size] = element;

    }

    else{
        CHashArrayItem *new_element  = privateCHashAny_new(
                PRIVATE_CHASH_ARRAY_ITEM,
                privateCHashArrayItem_new(self->size)
        );
        CHash_set_value_to_ArrayItem_OR_KeyVal(new_element, element);
        self->elements[self->size] = new_element;
    }


    self->size+=1;
    return 0;
}

CHashArrayItem_OR_CHashKeyVal  *CHash_get_item_from_position(ChashArray_OR_CHashObject *array,long position){


    long size = CHash_get_size(array);
    long converted_position = position;


    if(position < 0){
        converted_position = size + position;
    }

    if(converted_position < 0){
        converted_position = 0;
    }


    if(converted_position >=size){
        CHashArray * new_element = CHashArray_new_item(array);
        return new_element;
    }

    privateCHashArray  *self = (privateCHashArray*)(array->value);
    return self->elements[converted_position];


}

void private_CHashArray_print(CHashArray *array){
    privateCHashArray  *self = (privateCHashArray*)(array->value);
    for(int i = 0 ; i < self->size;i++){
        CHashAny *current = self->elements[i];
        ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL *raw = privateCHashAny_get_primitive(current);
        CHashPrint(raw);
    }

}


CHashArrayItem * CHashArray_new_item(CHashArray *array){
    CHashArrayItem *new_element  = privateCHashAny_new(
            PRIVATE_CHASH_ARRAY_ITEM,
            privateCHashArrayItem_new(CHash_get_size(array))
    );
    CHash_append(array, new_element);
    return new_element;
}

