

bool CHash_toBool(CHash *element){
    if(CHash_ensure_Bool(element)){
        return false;
    }
    return element->private_value_bool;
}
void CHash_set_Bool(CHash *self, bool value){
    if(CHash_ensure_Bool(self)){
        return;
    }
    privateCHash_free_values(self);
    self->private_value_bool = value;
}


CHash * newCHashBool(bool value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_BOOL;
    self->private_value_bool = value;
    return self;
}

