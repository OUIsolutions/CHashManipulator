

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

CHashObject * newCHashObject(){
    privateCHashArray  *self = privateChashArray_new();
    return privateCHashAny_new(CHASH_OBJECT,self);
}

void CHashArray_append(CHashArray *self, CHashAny *element){


}
