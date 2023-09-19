
void privateCHashArray_append_once(CHashArray *self, CHash *element){
    if(Chash_errors(self)){return;}

    self->private_sub_elements = (CHash**) realloc(
            self->private_sub_elements,
            (self->private_size + 1) * sizeof(CHash**)
    );
    element->private_reference_type = PRIVATE_CHASH_ARRAY_ITEM;
    element->private_father = self;
    element->private_error = self->private_error;
    element->private_index = self->private_size;
    self->private_sub_elements[self->private_size]= element;
    self->private_size+=1;


}

CHashArray * privatenewCHashArray(void *sentinel,...){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_ARRAY;
    self->private_sub_elements = (CHash**)malloc(0);
    self->private_size = 0;

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
    if(Chash_errors(self)){return;}

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
void CHashArray_delete(CHashArray *self, long index){
    if(Chash_errors(self)){return;}

    CHash  *current = CHashArray_get(self,index);
    CHash_free(current);
    self->private_size-=1;

    for(int i = 0; i <  self->private_size;i++){
        self->private_sub_elements[i] = self->private_sub_elements[i + 1];

    }
}
CHash * CHashArray_get(CHashArray *self, long index){
    if(Chash_errors(self)){
        return NULL;
    }

    return self->private_sub_elements[index];
}