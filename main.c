#include "src/one.h"

CHashArray  * create(){
    CHashArray  *t = newCHashArray();
    CHashArray_append(t, newCHashLong(20));
    CHashArray_append(t, newCHashLong(20));
    CHashArray_append(t, newCHashLong(20));

    CHashArray  *t2 = newCHashArray();
    CHashArray_append(t2, newCHashString("aaaaaaaaaa"));
    CHashArray_append(t2, newCHashString("aaaaaaaaaa"));

    CHashArray_append(t,t2);
    return t;

}



int main(){

    CHashArray *value = create();
    long size = CHash_get_size(value);
    for(int i = 0; i < size; i++){
        CHashAny  *current = CHashArray_get_at_index(value,i);
        int type = CHash_get_type(current);
        printf("type %d\n",type);
        if(type == CHASH_LONG){
            printf("%ld", CHash_toLong(current));
        }
        if(type == CHASH_ARRAY){
            long sub_size = CHash_get_size(current);
            for(int i =0; i < sub_size; i++){
                CHashAny  *sub_current = CHashArray_get_at_index(current,i);
                char *value = CHash_toString(sub_current);
                printf("%s",value);
            }
        }

    }

}