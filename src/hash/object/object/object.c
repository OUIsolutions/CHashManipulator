

CHashObject * newCHashObject(){
    privateCHashArray  *self = privateChashArray_new();
    return privateCHashAny_new(CHASH_OBJECT,self);
}

CHashKeyVal * CHashObject_get_by_key(CHashObject * object, const char *key){
    long size = CHash_get_size(object);
    for(int i = 0; i < size; i ++){
        CHashKeyVal  *element = CHash_get_from_index(object,i);
        char *current_key = CHash_get_key(element);
        if(current_key){
            if(strcmp(current_key,key) ==0){
                return element;
            }
        }
    }


}
