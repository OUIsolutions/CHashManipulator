

char * CHash_toString(CHashAny *element){


    CHashAny * raw = privateCHashAny_get_primitive(element);
    if(!raw){
        return NULL;
    }

    if(raw->raw_type != CHASH_STRING){
        return NULL;
    }
    return (char*)raw->value;
}

CHashAny * newCHashString(char *value){
    return privateCHashAny_new(CHASH_STRING, strdup(value));
}


