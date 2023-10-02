
CHashArray  *newCHashArrayEmpty(){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_ARRAY;
    self->private_sub_elements = (CHash**)malloc(0);
    self->private_size = 0;
    return self;
}

CHashArray * privatenewCHashArray(void *sentinel, ...){
    CHash * self =  newCHashArrayEmpty();

    va_list args;
    va_start(args, sentinel);


    while(true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }
        
        CHash * current_element = (CHash*)current;
        CHashArray_append_once(self, current_element);
    }
    va_end(args);
    return self;
}

CHashArray * privatenewCHashStringArray(void *sentinel, ...){
    CHash * self =  newCHashArrayEmpty();

    va_list args;
    va_start(args, sentinel);


    while(true){
        char  * current = va_arg(args,char*);
        if(!current){
            break;
        }
        CHashArray_append_once(self, newCHashString(current));
    }
    va_end(args);
    return self;
}

void CHashArray_append_once(CHashArray *self, CHash *element){

    if(CHash_ensure_Array(self)){
        return ;
    }
    self->private_sub_elements = (CHash**) realloc(
            self->private_sub_elements,
            (self->private_size + 1) * sizeof(CHash**)
    );
    element->private_reference_type = PRIVATE_CHASH_ARRAY_ITEM;
    element->private_father = self;
    element->private_index = self->private_size;
    self->private_sub_elements[self->private_size]= element;
    self->private_size+=1;


}
void privateCHashArray_append(CHashArray *self, ...){

    if(CHash_ensure_Array(self)){
        return;
    }

    va_list args;
    va_start(args, self);
    while(true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }
        CHash * current_element = (CHash*)current;
        CHashArray_append_once(self, current_element);
    }
    va_end(args);

}
void CHashArray_delete(CHashArray *self, long index){

    if(CHash_ensure_Array(self)){
        return ;
    }
    CHash  *current = CHashArray_get(self,index);
    CHash_free(current);
    self->private_size-=1;

    for(int i = 0; i <  self->private_size;i++){
        self->private_sub_elements[i] = self->private_sub_elements[i + 1];

    }
}
long privateCHashArray_convert_index(CHashArray *self, long index){
    long formated_index = index;
    if(index < 0){
        formated_index = (long)self->private_size +index;
    }
    if(formated_index < 0|| formated_index>= self->private_size){
        CHash_raise_error(
                self,
                CHASH_NOT_VALID_INDEX,
                " index: #index# its not valid, at #path#",
                newCHashObject(
                        "index", newCHashLong(index)
                )
        );
        return -1;
    }
}
CHash * CHashArray_get(CHashArray *self, long index){

    if(CHash_ensure_Array(self)){
        return NULL;
    }
    long formated_index = privateCHashArray_convert_index(self,index);
    if(formated_index == -1){
        return NULL;
    }

    return self->private_sub_elements[formated_index];
}

CHashArray * CHashArray_getArray(CHashObject * self, long index){
    CHash *element = CHashArray_get(self,index);
    if(CHash_ensure_Array(element)){
        return NULL;
    }
    return  element;
}

CHashObject * CHashArray_getObject(CHashObject * self, long index){
    CHashObject *element = CHashArray_get(self,index);
    if(CHash_ensure_Object(element)){
        return NULL;
    }
    return element;
}

long CHashArray_getLong(CHashObject * self, long index){
    CHashObject *element = CHashArray_get(self,index);
    return CHash_toLong(element);
}

double CHashArray_getDouble(CHashObject * self, long index){
    CHashObject *element = CHashArray_get(self,index);
    return CHash_toDouble(element);
}

bool CHashArray_getBool(CHashObject * self, long index){
    CHashObject *element = CHashArray_get(self,index);
    return CHash_toBool(element);

}

char  * CHashArray_getString(CHashObject * self, long index){
    CHashObject *element = CHashArray_get(self,index);
    return CHash_toString(element);
}
