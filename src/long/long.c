

long CHash_get_long(CHashAny *element){
    CHashAny * raw = privateCHashAny_get_primitive(element);
    if(raw->type != CHASH_LONG){
        return 0;
    }
    return *(long*)raw->value;
}



CHashLong * newCHashLong(long value){
    long *value_p = malloc(sizeof (long ));
    *value_p = value;
    return privateCHashAny_new(CHASH_LONG,value_p);
}

