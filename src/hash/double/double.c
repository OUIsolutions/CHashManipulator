

double CHash_toDouble(CHash *element){

    if(CHash_ensure_Double(element)){
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

