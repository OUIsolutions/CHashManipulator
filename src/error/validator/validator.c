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

int CHash_ensure_minDouble(CHash *element,double  min){
    double  value = CHash_toDouble(element);
    if(Chash_errors(element)){
        return 1;
    }
    if(value < min){
        CHash_raise_error(
                element,
                CHASH_LOWER_NUMBER,
                "element at #path# of value #value# its lower than #number#",
                newCHashObject("number", newCHashDouble(min))
        );
        return 1;
    }
    return 0;
}
int CHash_ensure_minDouble_by_key(CHash *object,const char *key,double min){
    CHash * current = CHashObject_get(object,key);
    return CHash_ensure_minDouble(current,min);
}

int CHash_ensure_minDouble_by_index(CHash *array,long index,double min){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_minDouble(current,min);
}



int CHash_ensure_maxDouble(CHash *element,double  max){
    double  value = CHash_toDouble(element);
    if(Chash_errors(element)){
        return 1;
    }
    if(value < max){
        CHash_raise_error(
                element,
                CHASH_LOWER_NUMBER,
                "element at #path# of value #value# its lower than #number#",
                newCHashObject("number", newCHashDouble(max))
        );
        return 1;
    }
    return 0;
}

int CHash_ensure_maxDouble_by_key(CHash *object,const char *key, double  max){
    CHash * current = CHashObject_get(object,key);
    return CHash_ensure_maxDouble(current,max);
}

int CHash_ensure_maxDouble_by_index(CHash *array,long index,double  max){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_maxDouble(current,max);
}

int CHash_ensure_Long(CHash *element){
    return private_chash_check_type(element,CHASH_LONG);

}

int CHash_ensure_long_by_key(CHash *object , const char *key){
    CHash *current = CHashObject_get(object,key);
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
    CHash *current = CHashObject_get(object,key);
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
