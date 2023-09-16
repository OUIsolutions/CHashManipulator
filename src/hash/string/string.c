

char * CHash_get_string(CHashArrayItem_OR_CHashKeyVal *element){
    CHashAny * raw = privateCHashAny_get_primitive(element);
    if(raw->raw_type != CHASH_STRING){
        return NULL;
    }
    return (char*)raw->value;
}

CHashString * newCHashString(char *value){
    return private_newCHashAny(CHASH_STRING, strdup(value));
}


