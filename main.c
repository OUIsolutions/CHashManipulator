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
        if(CHash_get_type(current) == CHASH_LONG){
            printf("%ld\n", CHash_toLong(current));
        }

        if(CHash_get_type(current) == CHASH_ARRAY){
            long sub_size = CHash_get_size(current);
            for (int x =0; x < sub_size; x++){
                printf("%s\n", CHash_toString(CHashArray_get_at_index(current,x)));
            }
        }



    }

}