





char * CHash_toString(CHashArray *element){
    if(element->private_type != CHASH_STRING){
        return NULL;
    }
    return element->private_value_stack->rendered_text;
}

CHash * newCHashString(char *value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_STRING;
    self->private_value_stack = newCTextStack_string(value);
    return self;
}