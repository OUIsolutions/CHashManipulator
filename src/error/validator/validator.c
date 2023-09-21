
int CHash_ensure_double(CHash *element){
    if(Chash_errors(element)){
        return 1;
    }

    if(element->private_type != CHASH_DOUBLE){
        CHash_raise_error(element,
         CHASH_WRONG_TYPE,
         "value: #value# of at #path# its not a double ", NULL
         );
        return 1;
    }
    return 0;
}