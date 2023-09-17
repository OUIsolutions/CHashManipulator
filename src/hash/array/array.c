

CHashArray * newCHashArray(){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_ARRAY;
    self->sub_elements = malloc(0);
    self->size = 0;
    return self;
}
void CHashArray_append(CHashArray *self,CHash *element){

    self->sub_elements = (CHash**) realloc(
            self->sub_elements,
            (self->size +1) * sizeof(CHash**)
    );
    element->reference_type = PRIVATE_CHASH_ARRAY_ITEM;
    element->index = self->size;
    self->sub_elements[self->size]= element;

    self->size+=1;


}

CHash * CHashArray_get(CHashArray *self, long index){
    return self->sub_elements[index];
}