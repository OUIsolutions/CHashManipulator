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

int CHash_ensure_Number(CHash *element){
    return private_chash_check_type(element, CHASH_NUMBER);
}
int CHash_ensure_Number_by_key(CHash *object, const char *key){
    CHash *element = CHashObject_get(object,key);
    return CHash_ensure_Number(element);
}
int CHash_ensure_Number_by_index(CHash *array, long index){
    CHash  *element = CHashArray_get(array,index);
    return CHash_ensure_Number(element);
}

int CHash_ensure_min(CHash *element, double  min){
    double  value = CHash_toNumber(element);
    if(Chash_errors(element)){
        return 1;
    }
    if(value < min){
        CHash_raise_error(
                element,
                CHASH_LOWER_NUMBER,
                "element at #path# of value #value# its lower than #number#",
                newCHashObject("number", newCHashNumber(min))
        );
        return 1;
    }
    return 0;
}
int CHash_ensure_min_by_key(CHash *object, const char *key, double min){
    CHash * current = CHashObject_get(object,key);
    return CHash_ensure_min(current, min);
}

int CHash_ensure_min_by_index(CHash *array, long index, double min){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_min(current, min);
}



int CHash_ensure_max(CHash *element, double  max){
    double  value = CHash_toNumber(element);
    if(Chash_errors(element)){
        return 1;
    }
    if(value > max){
        CHash_raise_error(
                element,
                CHASH_LOWER_NUMBER,
                "element at #path# of value #value# its lower than #number#",
                newCHashObject("number", newCHashNumber(max))
        );
        return 1;
    }
    return 0;
}

int CHash_ensure_max_by_key(CHash *object, const char *key, double  max){
    CHash * current = CHashObject_get(object,key);
    return CHash_ensure_max(current, max);
}

int CHash_ensure_max_by_index(CHash *array, long index, double  max){
    CHash *current = CHashArray_get(array,index);
    return CHash_ensure_max(current, max);
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

int CHash_ensure_only_keys(CHashObject *object, CHashStringArray *keys){
    long size = CHash_get_size(object);
    for(long i = 0; i < size; i++){
        char *current_key = CHashObject_get_key_by_index(object,i);
        if(CHashArray_find_String(keys, current_key) == -1){
            CHash_raise_error(
                    object,
                    CHASH_INVALID_KEY,
                    "key: #key# at #path#  its not inside #keys#",
                    newCHashObject(
                            "key", newCHashString(current_key),
                            "keys",keys
                    )
            );
            return 1;
        }
    }
    return 0;
}
int CHash_ensure_only_keys_cleaning_args(CHashObject *object, CHashStringArray *keys){
    int result = CHash_ensure_only_keys(object,keys);
    CHash_free(keys);
    return result;
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

int CHash_ensure_min_size(CHash *iterable,long min){
    long size = CHash_get_size(iterable);
    if(size < min){
        CHash_raise_error(
                iterable,
                CHASH_HIGHER_THAN_MIN,
                "the element at #path# its lower than #min# ",
                newCHashObject(
                        "min", newCHashNumber(min)
                )
        );
        return 1;
    }
    return  0;
}

int CHash_ensure_min_size_by_key(CHash  *object, const char *key,long min){
    CHash  *element = CHashObject_get(object,key);
    return CHash_ensure_min_size(element,min);
}

int CHash_ensure_min_size_by_index(CHash  *array, long index,long min){
    CHash *element = CHashArray_get(array,index);
    return CHash_ensure_min_size(element,min);
}

int CHash_ensure_max_size(CHash *iterable,long max){
    long size = CHash_get_size(iterable);
    if(size > max){

        CHash_raise_error(
                iterable,
                CHASH_HIGHER_THAN_MIN,
                "the element at #path# its higher than #max# ",
                newCHashObject(
                        "max", newCHashNumber(max)
                )
        );

        return 1;
    }
    return  0;
}

int CHash_ensure_max_size_by_key(CHash  *object, const char *key,long max){
    CHash  *element = CHashObject_get(object,key);
    return CHash_ensure_max_size(element,max);
}

int CHash_ensure_max_size_by_index(CHash  *array, long index,long max){
    CHash *element = CHashArray_get(array,index);
    return CHash_ensure_max_size(element,max);
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
