





char * CHash_toString(CHashArray *element){
    if(CHash_ensure_String(element)){
        return NULL;
    }

    return element->private_value_stack->rendered_text;
}

CTextStack  *CHashtoStack(CHash *element){
    if(CHash_ensure_String(element)){
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