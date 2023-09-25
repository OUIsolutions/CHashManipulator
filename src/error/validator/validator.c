int private_chash_check_type(CHash *element, unsigned short  expected_type){
    if(Chash_errors(element)){
        return 1;
    }

    if(element->private_type != expected_type){
        CHashObject *args_of_error   = newCHashObject(
                            "expected_type", newCHashString(
                                            private_Chash_convert_type(expected_type)
                                            )
                    )

        CHash_raise_error(element,
                          CHASH_WRONG_TYPE,
                          "element at #path# is #type# istead of #expected_type#  ",
                          args_of_error
        );
        return 1;
    }
    return 0;
}

int CHash_ensure_double(CHash *element){
    return private_chash_check_type(element,CHASH_DOUBLE);
}

int CHash_ensure_string(CHash *element){
    return private_chash_check_type(element,CHASH_STRING);
}


int CHash_ensure_object(CHash *element){
    return private_chash_check_type(element,CHASH_OBJECT);
}