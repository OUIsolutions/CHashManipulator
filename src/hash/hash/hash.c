
CHash * privatenewChash_raw(){
    CHash  *self = (CHash*) malloc(sizeof (CHash));
    *self = (CHash){0};
    return self;
}

void CHash_print(CHash *self){
    char * result = CHash_dump_to_json_string(self);
    printf("%s\n",result);
    free(result);
}

CHashArray * CHash_get_path(CHash *self){

    if(self->reference_type == PRIVATE_CHASH_NOT_A_REFERENCE){
        return  newCHashArray(NULL);
    }

    CHashArray  *path = CHash_get_path(self->father);

    if(self->reference_type == PRIVATE_CHASH_ARRAY_ITEM){
        CHashArray_append(path, newCHashLong(self->index));;
    }

    if(self->reference_type == PRIVATE_CHASH_KEYVAL){
        CHashArray_append(path, newCHashString(self->key));
    }
    return path;

}
void CHash_free(CHash *self){

    if(self->reference_type == PRIVATE_CHASH_KEYVAL){
        free(self->key);
    }

    if(self->type == CHASH_STRING){
        free(self->value_string);
    }

    if(self->type == CHASH_OBJECT || self->type == CHASH_ARRAY){
        long size = self->size;
        for(int i = 0; i < size; i++){
            CHash * current = self->sub_elements[i];
            CHash_free(current);
        }
        free(self->sub_elements);
    }


    free(self);
}

CHash * CHash_copy(CHash *self){
    
    if(self->type == CHASH_STRING){
        return newCHashString(self->value_string);
    }
    
    if(self->type == CHASH_LONG){
        return newCHashLong(self->value_long);
    }

    if(self->type == CHASH_DOUBLE){
        return newCHashDouble(self->value_double);
    }
    
    if(self->type == CHASH_BOOL){
        return newCHashBool(self->value_bool);
    }

    if(self->type == CHASH_ARRAY ){
        CHash * new_element  = newCHashArray(NULL);

        for(long i =0; i < self->size;i++){
            CHash * copy = CHash_copy(CHashArray_get(self,i));
            CHashArray_append(new_element,copy);
        }
        return new_element;

    }
    if(self->type == CHASH_OBJECT){
        CHash * new_element  = newCHashObject(NULL);

        for(long  i =0; i < self->size;i++){
            CHash  * current = CHashObject_get_by_index(self,i);
            CHash *copy = CHash_copy(current);

            CHashObject_set(new_element,current->key,copy);
        }
        return new_element;
    }


    return newCHashNULL();
}


CHash * newCHashNULL(){
    return privatenewChash_raw();
}
