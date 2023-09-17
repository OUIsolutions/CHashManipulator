
cJSON * privateCHash_dumps_json_object(CHashObject * object){
    return cJSON_CreateObject();
}

cJSON * privateCHash_dumps_json_array(CHashArray * array){
    long size = CHash_get_size(array);
    cJSON *element = cJSON_CreateArray();
    for(int i = 0; i < size; i++){
        CHashAny  *current  = CHashArray_get(array, i);
        cJSON *current_json = privateCHash_dumps_to_json_element(current);
        cJSON_AddItemToArray(element,current_json);
    }
    return element;
}


cJSON * privateCHash_dumps_to_json_element(CHashAny *element){
    int type = CHash_get_type(element);
    if(type == CHASH_OBJECT){
        return privateCHash_dumps_json_object(element);
    }
    if(type == CHASH_ARRAY){
        return privateCHash_dumps_json_array(element);
    }
    if(type == CHASH_STRING){
        char *value  = CHash_toString(element);
        return cJSON_CreateString(value);
    }
    if(type == CHASH_LONG){
        long value  = CHash_toLong(element);
        return cJSON_CreateNumber((double)value);
    }

    return cJSON_CreateNull();

}

char * CHash_dumps_to_json_string(CHashAny * element){
    cJSON * created = privateCHash_dumps_to_json_element(element);
    char * result  = cJSON_Print(created);
    cJSON_Delete(created);
    return result;
}
