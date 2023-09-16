

privateCHashKeyVal * privateCHashKeyVal_new(const char *key){
    privateCHashKeyVal * self = (privateCHashKeyVal*) malloc(sizeof (privateCHashKeyVal));
    *self = (privateCHashKeyVal){0};
    self->key = strdup(key);
    self->value = privateCHashAny_new(CHASH_NULL,NULL);
    return self;
}


char * CHash_get_key(CHashKeyVal *keyval){
    if(keyval->type != PRIVATE_CHASH_KEY_VAL){
        return NULL;
    }
    privateCHashKeyVal  *element = (privateCHashKeyVal*)keyval->value;
    return element->key;
}
