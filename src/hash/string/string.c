





char * CHash_to_string(CHashArray *element){
    if(CHash_ensure_string(element)){
        return NULL;
    }

    return element->private_value_stack->rendered_text;
}

CTextStack  *CHash_to_Stack(CHash *element){
    if(CHash_ensure_string(element)){
        return NULL;
    }
    if(element->private_type != CHASH_STRING){
        return NULL;
    }
    return element->private_value_stack;
}

CHash * newCHashStackString(CTextStack *element){

    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_STRING;
    self->private_value_stack = element;
    return self;
}

CHash * newCHashString(const char *value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_STRING;
    self->private_value_stack = newCTextStack_string(value);
    return self;
}