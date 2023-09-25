
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20),
            NULL
    );

}

int main(){

    CHashArray *t = create();
    CHash_print(t);

    CHash_free(t);

}