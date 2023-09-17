

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
    privateCHashArrayItem * new_element = privateCHashArrayItem_new(self->size);
    new_element->value = element;

    CHashAny *new_element_any  = privateCHashAny_new(
            PRIVATE_CHASH_ARRAY_ITEM,
                new_element
    );

    self->elements[self->size] = new_element_any;

    self->size+=1;
    return 0;
}

CHashAny * CHashArray_get(CHashArray *array, long position){

    CHashAny *raw = privateCHashAny_get_primitive(array);

    long size = CHash_get_size(raw);
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
        CHashArray_append(raw, new_element);
        return new_element;
    }

    privateCHashArray  *self = (privateCHashArray*)(raw->value);
    return self->elements[converted_position];
}





