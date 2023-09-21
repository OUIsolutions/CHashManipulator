int private_chash_check_type(CHash *element, unsigned short  expected_type,char *expected_type_str){
    if(Chash_errors(element)){
        return 1;
    }

    if(element->private_type != expected_type){
        CHash_raise_error(element,
                          CHASH_WRONG_TYPE,
                          "value: #value# of at #path# its not #type# ",
                          newCHashObject("type", newCHashString(expected_type_str))
                          );
        return 1;
    }
    return 0;
}

int CHash_ensure_double(CHash *element){
    return private_chash_check_type(element,CHASH_DOUBLE,"double");
}

int CHash_ensure_string(CHash *element){
    return private_chash_check_type(element,CHASH_STRING,"string");
}


