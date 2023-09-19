

CHashObject* privatenewCHashObject(void * sentinel, ...){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_OBJECT;
    self->private_sub_elements = (CHash**)malloc(0);
    self->private_size = 0;

    va_list args;
    va_start(args, sentinel);

    const int GETTING_KEY = 0;
    const int GETTING_VALUE = 1;

    int state = GETTING_KEY;

    char *key;

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
            privateCHashObject_set_once(self, key, (CHash *) current);
            state = GETTING_KEY;
        }

    }

    return self;
}

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key){
    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        if(strcmp(current->private_key, key) == 0){
            return current;
        }
    }
    return NULL;
}

CHash * CHashObject_get_by_index(CHashObject * self, long index){
    return self->private_sub_elements[index];
}

CHash * CHashObject_get(CHashObject * self, const char *key){
    CHash *element = privateCHashObject_get_by_key(self,key);
    if(element){
        return  element;
    }
    self->private_sub_elements = (CHash**) realloc(
            self->private_sub_elements,
            (self->private_size + 1) * sizeof(CHash**)
    );

    element  =privatenewChash_raw();
    element->private_father = self;
    element->private_key = strdup(key);
    element->private_reference_type  = PRIVATE_CHASH_KEYVAL;
    self->private_sub_elements[self->private_size]=element;
    self->private_size+=1;

    return self;
}

void  CHashObject_delete(CHashObject *self, const char *key){
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
void  privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element){
    CHashObject_delete(self,key);

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
    CHashArray * keys = newCHashArray(NULL);
    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        CHashArray_append(keys, newCHashString(current->private_key));
    }
    return keys;
}

char * CHashObject_get_element_key(CHash *element){
    if(!element){
        return NULL;
    }
    return element->private_key;
}

void  privateCHashObject_set(CHashObject *self ,...){

    va_list args;

    va_start(args, NULL);

    const int GETTING_KEY = 0;
    const int GETTING_VALUE = 1;

    int state = GETTING_KEY;

    char *key;

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
            privateCHashObject_set_once(self, key, (CHash *) current);
         
            state = GETTING_KEY;
        }

    }
    va_end(args);
    
}