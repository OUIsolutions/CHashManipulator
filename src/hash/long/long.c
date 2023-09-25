

long CHash_toLong(CHash *element){
    if(CHash_ensure_long(element)){
        return -1;
    }

    if(element->private_type != CHASH_LONG){
        return -1;
    }
    return element->private_value_long;
}

CHash * newCHashLong(long value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_LONG;
    self->private_value_long = value;
    return self;
}

