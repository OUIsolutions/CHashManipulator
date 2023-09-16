

CHashArray * privateChashArray_new(){
    CHashArray * self = (CHashArray*)malloc(sizeof (CHashArray));
    self->size = 0;
    self->elements = malloc(0);
    return self;
}

CHashArray  * newCHashArray(){
    CHashArray  *self = privateChashArray_new();
    return private_newCHashAny(CHASH_ARRAY, self);
}

int CHash_append(ChashArray_OR_CHashObject *iterable, CHashAny *element){

    CHashArray  *self = (CHashArray*)(iterable->value);
    self->elements = realloc(self->elements,(self->size +1) * sizeof(CHashAny**));

    if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM || element->raw_type == PRIVATE_CHASH_KEY_VAL){

        if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
            CHashArrayItem   *casted = (CHashArrayItem*)element->value;
            casted->position = self->size;
        }

        self->elements[self->size] = element;

    }

    else{
        CHashArrayItem *new_element  = private_newCHashAny(
                PRIVATE_CHASH_ARRAY_ITEM,
                private_newCHashArrayItem(self->size)
        );
        CHash_set(new_element, element);
        self->elements[self->size] = new_element;
    }


    self->size+=1;
    return 0;
}

CHashArrayItem_OR_CHashKeyVal  *CHashArray_get(ChashArray_OR_CHashObject *iterable, long position){


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

        CHashArrayItem *new_element  = private_newCHashAny(
                PRIVATE_CHASH_ARRAY_ITEM,
                private_newCHashArrayItem(CHash_get_size(iterable))
        );
        CHash_append(iterable, new_element);
        return new_element;
    }

    CHashArray  *self = (CHashArray*)(iterable->value);
    return self->elements[converted_position];

}

void private_CHashArray_print(CHashArray *array){
    CHashArray  *self = (CHashArray*)(array->value);
    for(int i = 0 ; i < self->size;i++){
        CHashAny *current = self->elements[i];
        ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL *raw = privateCHashAny_get_primitive(current);
        CHashPrint(raw);
    }

}



