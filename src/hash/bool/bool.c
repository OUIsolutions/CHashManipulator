

bool CHash_toBool(CHash *element){
    if(element->type != CHASH_BOOL){
        return -1;
    }
    return element->value_bool;
}

CHash * newCHashBool(bool value){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_BOOL;
    self->value_bool = value;
    return self;
}

