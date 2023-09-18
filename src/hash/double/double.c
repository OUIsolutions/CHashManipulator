

double CHash_toDouble(CHash *element){
    if(element->type != CHASH_DOUBLE){
        return -1;
    }
    return element->value_double;
}

CHash * newCHashDouble(double value){
    CHash * self =  privatenewChash_raw();
    self->type = CHASH_DOUBLE;
    self->value_double = value;
    return self;
}

