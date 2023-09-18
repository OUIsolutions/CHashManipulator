

CHashArray * privatenewCHashArray(void *sentinel,...){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_ARRAY;
    self->sub_elements = malloc(0);
    self->size = 0;

    va_list args;
    va_start(args, sentinel);

    while(true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }

        CHash * current_element = (CHash*)current;
        CHashArray_append(self,current_element);
    }
    return self;
}

void CHashArray_append(CHashArray *self,CHash *element){

    self->sub_elements = (CHash**) realloc(
            self->sub_elements,
            (self->size +1) * sizeof(CHash**)
    );
    element->reference_type = PRIVATE_CHASH_ARRAY_ITEM;
    element->father = self;
    element->index = self->size;
    self->sub_elements[self->size]= element;
    self->size+=1;

}

CHash * CHashArray_get(CHashArray *self, long index){
    return self->sub_elements[index];
}