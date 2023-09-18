





char * CHash_toString(CHashArray *element){
    if(element->private_type != CHASH_STRING){
        return NULL;
    }
    return element->private_value_string;
}

CHash * newCHashString(char *value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_STRING;
    self->private_value_string = strdup(value);
    return self;
}