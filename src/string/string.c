

char * CHash_get_string(CHashAny *element){
    CHashAny * raw = privateCHashAny_get_value_from_keyvall_or_array_item(element);
    if(raw->type != CHASH_STRING){
        return 0;
    }
    return (char*)raw->value;
}

CHashString * newCHashString(char *value){
    return privateCHashAny_new(CHASH_STRING, strdup(value));
}

