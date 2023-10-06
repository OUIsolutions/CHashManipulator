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
int CHash_ensure_Double_by_key(CHash *object,const char *key){
    CHashObject *current = CHashObject_get(object,key);
    return CHash_ensure_Double(current);
}

int CHash_ensure_Double_by_index(CHash *array,long index){
    CHashArray *current = CHashArray_get(array,index);
    return CHash_ensure_Double(current);
}



int CHash_ensure_Long(CHash *element){
    return private_chash_check_type(element,CHASH_LONG);

}

int CHash_ensure_long_by_key(CHash *object , const char *key){
    CHashObject *current = CHashObject_get(object,key);
    return CHash_ensure_Long(current);
}

int CHash_ensure_long_by_index(CHash *array , long index){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_Long(current);
}

int CHash_ensure_Bool(CHash *element){
    return private_chash_check_type(element,CHASH_BOOL);

}

int CHash_ensure_Bool_by_key(CHash *object , const char *key){
    CHashObject *current = CHashObject_get(object,key);
    return CHash_ensure_Bool(current);
}

int CHash_ensure_Bool_by_index(CHash *array , long index){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_Bool(current);
}

int CHash_ensure_String(CHash *element){
    return private_chash_check_type(element,CHASH_STRING);
}
int CHash_ensure_String_by_key(CHash *object , const char *key){
    CHashObject *current = CHashObject_get(object,key);
    return CHash_ensure_String(current);
}
int CHash_ensure_String_by_index(CHash *array , long index){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_String(current);
}

int CHash_ensure_Object(CHash *element){
    return private_chash_check_type(element,CHASH_OBJECT);
}
int CHash_ensure_Object_by_key(CHash *object , const char *key){
    CHashObject *current = CHashObject_get(object,key);
    return CHash_ensure_Object(current);
}
int CHash_ensure_Object_by_index(CHash *array , long index){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_Object(current);
}

int CHash_ensure_Array(CHash *element){
    return private_chash_check_type(element,CHASH_ARRAY);
}
int CHash_ensure_Array_by_key(CHash *object , const char *key){
    CHashObject *current = CHashObject_get(object,key);
    return CHash_ensure_Array(current);
}

int CHash_ensure_Array_by_index(CHash *array , long index){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_Array(current);
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
