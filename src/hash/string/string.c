





char * CHash_toString(CHashArray *element){
    if(element->type != CHASH_LONG){
        return NULL;
    }
    return element->value_string;
}

CHash * newCHashString(char *value){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_STRING;
    self->value_string = value;
    return self;
}