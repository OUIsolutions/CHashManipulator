

double CHash_toNumber(CHash *element){

    if(CHash_ensure_Number(element)){
        return -1;
    }
    return element->private_value_double;

}


CHash * newCHashNumber(double value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_NUMBER;
    self->private_value_double = value;
    return self;
}

