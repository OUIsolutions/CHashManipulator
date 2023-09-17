

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


int CHashArray_append(CHashArray *array, CHashAny *element){

    privateCHashArray  *self = (privateCHashArray*)(array->value);
    self->elements = realloc(self->elements,(self->size +1) * sizeof(CHashAny**));

    CHashAny *new_element  = privateCHashAny_new(
            PRIVATE_CHASH_ARRAY_ITEM,
            privateCHashArrayItem_new(self->size)
    );
    CHash_set(new_element, element);
    self->elements[self->size] = new_element;

    self->size+=1;
    return 0;
}

CHashAny * CHashArray_get_at_index(CHashArray *array, long position){

    long size = CHash_get_size(array);
    long converted_position = position;


    if(position < 0){
        converted_position = size + position;
    }

    if(converted_position < 0){
        converted_position = 0;
    }


    if(converted_position >=size){
        CHashAny *new_element  = privateCHashAny_new(
                PRIVATE_CHASH_ARRAY_ITEM,
                privateCHashArrayItem_new(size)
        );
        CHashArray_append(array, new_element);
        return new_element;
    }

    privateCHashArray  *self = (privateCHashArray*)(array->value);
    return self->elements[converted_position];
}





