
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
    CHash *new_element = privatenewChash_raw();
    //we dont copy references because the idea of an copy itss to externalize scopes
    new_element->type = self->type;
    new_element->size = self->size;

    if(self->type == CHASH_STRING){
        new_element->value_string = strdup(self->value_string);
    }
    if(self->type == CHASH_LONG){
        new_element->value_long = self->value_long;
    }
    if(self->type == CHASH_DOUBLE){
        new_element->value_double = self->value_double;
    }
    if(self->type == CHASH_BOOL){
        new_element->value_bool = self->value_bool;
    }
    if(self->type == CHASH_ARRAY ){
        new_element->sub_elements = malloc(0);

        for(int i =0; i < self->size;i++){
            CHash * copy = CHash_copy(CHashArray_get(self,i));
            CHashArray_append(new_element,copy);
        }

    }
    if(self->type == CHASH_OBJECT){
        new_element->sub_elements = malloc(0);

        for(int i =0; i < self->size;i++){
            CHash  * current = CHashObject_get_by_index(self,i);
            CHash *copy = CHash_copy(current);
            CHashObject_set(new_element,current->key,copy);
        }
    }
    return new_element;
}


CHash * newCHashNULL(){
    return privatenewChash_raw();
}
