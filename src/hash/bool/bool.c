

bool CHash_parse_toBool(CHash *element){
    if(element->private_type != CHASH_BOOL){
        return false;
    }
    return element->private_value_bool;
}

CHash * newCHashBool(bool value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_BOOL;
    self->private_value_bool = value;
    return self;
}

