

CHashObject * newCHashObject(){
    privateCHashArray  *self = privateChashArray_new();
    return privateCHashAny_new(CHASH_OBJECT,self);
}

int CHashObject_set(CHashObject * object,const char *key, CHashAny *element){

    CHashAny *current = privateCHashObject_get_by_key(object,key);
    if(current){
        CHash_set(current,element);
        return 0;
    }

    privateCHashArray  *self = (privateCHashArray*)(object->value);
    self->elements = realloc(self->elements,(self->size +1) * sizeof(CHashAny**));

    privateCHashKeyVal  *created_key_val = privateCHashKeyVal_new(key);
    CHashAny * keyval = privateCHashAny_new(PRIVATE_CHASH_KEY_VAL,created_key_val);
    CHash_set(keyval,element);
    self->elements[self->size] = keyval;

    self->size+=1;
    return 0;
}

CHashAny * privateCHashObject_get_by_key(CHashObject * object, const char *key){
    long size = CHash_get_size(object);
    for(int i = 0; i < size; i ++){
        CHashAny  *element = CHashArray_get_at_index(object, i);
        char *current_key = CHash_get_key(element);
        if(current_key){
            if(strcmp(current_key,key) ==0){
                return element;
            }
        }
    }
    return NULL;
}


CHashAny * CHashObject_get_by_key(CHashObject * object, const char *key){

    CHashAny * current = privateCHashObject_get_by_key(object,key);
    if(current){
        return current;
    }

    //if not exist create an new key and returns it
    privateCHashArray  *self = (privateCHashArray*)(object->value);
    self->elements = realloc(self->elements,(self->size +1) * sizeof(CHashAny**));
    privateCHashKeyVal  *created_key_val = privateCHashKeyVal_new(key);
    current = privateCHashAny_new(PRIVATE_CHASH_KEY_VAL,created_key_val);
    self->elements[self->size] = current;
    self->size+=1;
    return current;
}



