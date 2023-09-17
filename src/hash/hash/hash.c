
CHash * privatenewChash_raw(){
    CHash  *self = (CHash*) malloc(sizeof (CHash));
    *self = (CHash){0};
    return self;
}

void CHash_print(CHash *self){
    char * result = CHash_dumps_to_json_string(self);
    printf("%s",result);
    free(result);
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
