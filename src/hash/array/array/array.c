

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

int CHash_append(ChashArray_OR_CHashObject *iterable, CHashAny *element){

    privateCHashArray  *self = (privateCHashArray*)(iterable->value);
    self->elements = realloc(self->elements,(self->size +1) * sizeof(CHashAny**));

    if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM || element->raw_type == PRIVATE_CHASH_KEY_VAL){

        if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
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
        CHash_set(new_element, element);
        self->elements[self->size] = new_element;
    }


    self->size+=1;
    return 0;
}

CHashArrayItem_OR_CHashKeyVal  *CHash_get_from_index(ChashArray_OR_CHashObject *iterable, long position){


    long size = CHash_get_size(iterable);
    long converted_position = position;


    if(position < 0){
        converted_position = size + position;
    }

    if(converted_position < 0){
        converted_position = 0;
    }


    if(converted_position >=size){
        if(iterable->raw_type == CHASH_OBJECT){

        }

        CHashArrayItem *new_element  = privateCHashAny_new(
                PRIVATE_CHASH_ARRAY_ITEM,
                privateCHashArrayItem_new(CHash_get_size(iterable))
        );
        CHash_append(iterable, new_element);
        return new_element;
    }

    privateCHashArray  *self = (privateCHashArray*)(iterable->value);
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



