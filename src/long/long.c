

long CHashGetLong(CHashAny *element){
    return *(long*)element->value;
}


CHashLong * newCHashLong(long value){
    long *value_p = malloc(sizeof (long ));
    *value_p = value;
    return privateCHashAny_new(CHASH_LONG,value_p);
}

