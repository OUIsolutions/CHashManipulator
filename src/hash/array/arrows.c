

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
