
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20),
            "c",newCHashObject(
               "c1", newCHashBool(true),
               "c2", newCHashDouble(2.4)
            )
    );

}

int main(){

    CHashArray *t = create();
    CHash_print(t);

    CHash_free(t);

}