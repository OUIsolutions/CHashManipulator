



CHashObject  * newCHashObjectEmpty(){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_OBJECT;
    self->private_sub_elements = (CHash**)malloc(0);
    self->private_size = 0;
    return self;
}

CHashObject* privatenewCHashObject(void * sentinel, ...){
    CHash * self =  newCHashObjectEmpty();

    va_list args;
    va_start(args, sentinel);

    const int GETTING_KEY = 0;
    const int GETTING_VALUE = 1;


    int state = GETTING_KEY;
    char *key = NULL;

    while(true){
        void * current = va_arg(args,void*);
        
        if(!current){
            break;
        }

        if(state == GETTING_KEY){
            key = (char*)current;
            state = GETTING_VALUE;
            continue;
        }

        if(state == GETTING_VALUE){
            CHashObject_set_once(self, key, (CHash *) current);
            state = GETTING_KEY;

        }

    }
    
    va_end(args);

    return self;
}


CHash * privateCHashObject_get_by_key_or_null(CHashObject * self, const char *key){
    if(Chash_errors(self)){
        return NULL;
    }
    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        if(strcmp(current->private_key, key) == 0){
            return current;
        }
    }
    return NULL;
}


CHash * CHashObject_get_by_index(CHashObject * self, long index){
    if(Chash_errors(self)){
        return NULL;
    }

    return self->private_sub_elements[index];
}

char   * CHashObject_get_key_of_element(CHash *self){
    if(Chash_errors(self)){
        return NULL;
    }
    if(self->private_reference_type != PRIVATE_CHASH_KEYVAL){
        CHash_raise_error(self,CHASH_NOT_HAVE_KEY,"element of #path# does not have an key",NULL);
    }
    return self->private_key;
}

CHash * CHashObject_get(CHashObject * self, const char *key){

    if(CHash_ensure_Object(self)){
        return NULL;
    }


    CHash *element = privateCHashObject_get_by_key_or_null(self, key);

    if(element){
        return  element;
    }


    CHash_raise_error(self,
                      CHASH_ELEMENT_NOT_EXIST,
                      "element of key:#key# at #path# not exist",
                      newCHashObject("key", newCHashString(key))
     );

    return  NULL;
}

void  CHashObject_delete(CHashObject *self, const char *key){
    if(CHash_ensure_Object(self)){
        return ;
    }

    bool found = false;

    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        if(strcmp(current->private_key, key) == 0){
            CHash_free(current);
            found = true;
            self->private_size-=1;
        }

        if(found){
            self->private_sub_elements[i] = self->private_sub_elements[i + 1];
        }

    }
    
}
void  CHashObject_set_once(CHashObject * self, const char *key, CHash *element){
    if(CHash_ensure_Object(self)){
        return ;
    }
    CHashObject_delete(self, key);

    self->private_sub_elements = (CHash**) realloc(
            self->private_sub_elements,
            (self->private_size + 1) * sizeof(CHash**)
    );

    element->private_reference_type = PRIVATE_CHASH_KEYVAL;
    element->private_father = self;
    element->private_key = strdup(key);
    self->private_sub_elements[self->private_size]= element;
    self->private_size+=1;
}


CHashArray  * CHashObject_get_keys(CHashObject *self){
    if(CHash_ensure_Object(self)){
        return NULL;
    }

    CHashArray * keys = privatenewCHashArray(NULL);
    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        privateCHashArray_append(keys, newCHashString(current->private_key));
    }
    return keys;
}



void  privateCHashObject_set(CHashObject *self , ...){
    if(CHash_ensure_Object(self)){
        return ;
    }
    va_list args;

    va_start(args, NULL);

    const int GETTING_KEY = 0;
    const int GETTING_VALUE = 1;

    int state = GETTING_KEY;

    char *key =NULL;

    while (true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }

        if(state == GETTING_KEY){
            key = (char*)current;
            state = GETTING_VALUE;
            continue;
        }

        if(state == GETTING_VALUE){
            CHashObject_set_once(self, key, (CHash *) current);
         
            state = GETTING_KEY;
        }

    }
    va_end(args);
    
}