

long CHash_toLong(CHash *element){
    if(element->type != CHASH_LONG){
        return -1;
    }
    return element->value_long;
}

CHash * newCHashLong(long value){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_ARRAY;
    self->value_long = value;
    return self;
}

