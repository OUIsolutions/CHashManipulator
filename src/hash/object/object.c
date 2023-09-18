

CHashObject* privatenewCHashObject(void * sentinel, ...){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_OBJECT;
    self->sub_elements = malloc(0);
    self->size = 0;

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
    for(int i =0;i < self->size; i ++){
        CHash * current = self->sub_elements[i];
        if(strcmp(current->key,key)==0){
            return current;
        }
    }
    return NULL;
}
CHash * CHashObject_get_by_index(CHashObject * self, long index){
    return self->sub_elements[index];
}

CHash * CHashObject_get(CHashObject * self, const char *key){
    CHash *element = privateCHashObject_get_by_key(self,key);
    if(element){
        return  element;
    }
    self->sub_elements = (CHash**) realloc(
            self->sub_elements,
            (self->size +1) * sizeof(CHash**)
    );

    element  =privatenewChash_raw();
    element->father = self;
    element->key = strdup(key);
    element->reference_type  = PRIVATE_CHASH_KEYVAL;
    self->sub_elements[self->size]=element;
    self->size+=1;
}

int privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element){
    CHash *old_element = privateCHashObject_get_by_key(self,key);

    if(old_element){
        //implement free here
    }

    self->sub_elements = (CHash**) realloc(
            self->sub_elements,
            (self->size +1) * sizeof(CHash**)
    );

    element->reference_type = PRIVATE_CHASH_KEYVAL;
    element->father = self;
    element->key = strdup(key);
    self->sub_elements[self->size]= element;
    self->size+=1;
}
