
#include "src/one.h"



CHashObject *create (){
    return newCHashArray(
            newCHashLong(10),
            newCHashLong(10),
            CHASH_END
    );

}

int main(){

    CHashArray *t = create();
    CHashArray_append(t, newCHashString("aaaaaaa"),CHASH_END);
    CHash_print(t);

    CHash_free(t);

}