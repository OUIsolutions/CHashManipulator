
cJSON * privateCHash_dumps_json_object(CHashObject * object){
    return cJSON_CreateObject();
}

cJSON * privateCHash_dumps_json_array(CHashArray * array){
    long size = array->size;
    cJSON *element = cJSON_CreateArray();
    for(int i = 0; i < size; i++){
        CHashArray *current  = CHashArray_get(array, i);
        cJSON *current_json = privateCHash_dumps_to_json_element(current);
        cJSON_AddItemToArray(element,current_json);
    }
    return element;
}


cJSON * privateCHash_dumps_to_json_element(CHash *element){
    int type = element->type;

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

char * CHash_dumps_to_json_string(CHash * element){
    cJSON * created = privateCHash_dumps_to_json_element(element);
    char * result  = cJSON_Print(created);
    cJSON_Delete(created);
    return result;
}
