
void privateCHashArray_append_once(CHashArray *self, CHash *element){

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
        privateCHashArray_append_once(self, current_element);
    }
    va_end(args);
    return self;
}

void privateCHashArray_append(CHashArray *self, CHashArray *element, ...){
    privateCHashArray_append_once(self, element);

    va_list args;
    va_start(args, NULL);

    while(true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }
        CHash * current_element = (CHash*)current;
        privateCHashArray_append_once(self, current_element);
    }
    va_end(args);

}

CHash * CHashArray_get(CHashArray *self, long index){
    return self->sub_elements[index];
}