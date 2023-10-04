int private_chash_check_type(CHash *element, unsigned short  expected_type){
    if(Chash_errors(element)){
        return 1;
    }

    if(element->private_type != expected_type){

        CHash_raise_error(element,
                          CHASH_WRONG_TYPE,
                          "element at #path# is #type# instead of #expected_type#  ",
                          newCHashObject(
                                  "expected_type", newCHashString(
                                  private_Chash_convert_type(expected_type)
                                )
                          )
        );
        return 1;
    }
    return 0;
}

int CHash_ensure_Double(CHash *element){
    return private_chash_check_type(element,CHASH_DOUBLE);
}

int CHash_ensure_String(CHash *element){
    return private_chash_check_type(element,CHASH_STRING);
}
int CHash_ensure_Long(CHash *element){
    return private_chash_check_type(element,CHASH_LONG);

}
int CHash_ensure_Bool(CHash *element){
    return private_chash_check_type(element,CHASH_BOOL);
}

int CHash_ensure_Object(CHash *element){
    return private_chash_check_type(element,CHASH_OBJECT);
}

int CHash_ensure_Array(CHash *element){
    return private_chash_check_type(element,CHASH_ARRAY);
}
int privateCHash_ensureArrayOrObject(CHash *element){
    if(Chash_errors(element)){
        return 1;
    }

    if(element->private_type != CHASH_OBJECT && element->private_type != CHASH_ARRAY){
        CHash_raise_error(element,
                          CHASH_WRONG_TYPE,
                          "element at #path# is #type# instead of array or object  ",
                          NULL
        );
        return 1;
    }
    return 0;

}
