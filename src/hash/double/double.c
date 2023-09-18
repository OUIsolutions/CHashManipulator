

double CHash_toDouble(CHash *element){
    if(element->private_type != CHASH_DOUBLE){
        return -1;
    }
    return element->private_value_double;
}

CHash * newCHashDouble(double value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_DOUBLE;
    self->private_value_double = value;
    return self;
}

