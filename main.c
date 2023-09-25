
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20),
            "c",newCHashArray(
                newCHashBool(true),
                newCHashDouble(2.4),
                CHASH_END
            ));

}

int main(){

    CHashArray *t = create();
    CHash_print(t);

    CHash_free(t);

}