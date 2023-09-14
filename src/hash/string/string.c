

char * CHash_get_string(CHashAny *element){
    CHashAny * raw = privateCHashAny_get_primitive(element);
    if(raw->type != CHASH_STRING){
        return 0;
    }
    return (char*)raw->value;
}

CHashString * newCHashString(char *value){
    return privateCHashAny_new(CHASH_STRING, strdup(value));
}

