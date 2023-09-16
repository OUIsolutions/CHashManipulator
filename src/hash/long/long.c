

long CHash_get_long(CHashArrayItem_OR_CHashKeyVal *element){
    CHashAny * raw = privateCHashAny_get_primitive(element);
    if(raw->raw_type != CHASH_LONG){
        return 0;
    }

    return *(long*)raw->value;

}



CHashLong * newCHashLong(long value){
    long *value_p = malloc(sizeof (long ));
    *value_p = value;
    return privateCHashAny_new(CHASH_LONG,value_p);
}

