

void CHashArray_foreach(CHashArray *self,void  (*callback)(CHash *current)){
    if(privateCHash_ensureArrayOrObject(self)){
        return;
    }
    long size = CHash_get_size(self);
    for(long i = 0; i < size;i++){
        CHash *current = CHashArray_get(self,i);
        callback(current);
    }
}
void CHashArray_foreach_with_args(CHashArray *self,void  (*callback)(CHash *current,va_list args),...){

    if(privateCHash_ensureArrayOrObject(self)){
        return;
    }
    long size = CHash_get_size(self);

    for(long i = 0; i < size;i++){
        va_list  args;
        va_start(args, NULL);
        CHash *current = CHashArray_get(self,i);
        callback(current,args);
        va_end(args);

    }

}
