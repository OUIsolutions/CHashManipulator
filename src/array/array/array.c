

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

CHashArrayItem * CHashArray_new_item(CHashArray *self){
    privateCHashArray  *casted_self = (privateCHashArray*)(self->value);
    casted_self->elements = realloc(casted_self->elements,(casted_self->size +1) * sizeof(CHashAny**));
    CHashArrayItem *new_element  = privateCHashAny_new(
        PRIVATE_CHASH_ARRAY_ITEM,
        privateCHashArrayItem_new(casted_self->size)
    );
    casted_self->elements[casted_self->size] = new_element;
    casted_self->size+=1;
    return new_element;
}

