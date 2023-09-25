
#include "src/one.h"



CHashObject *create (){
    return privatenewCHashArray(
            newCHashLong(10),
            newCHashLong(10),
            NULL
    );

}

int main(){

    CHashArray *t = create();
    CHash_print(t);

    //CHash_free(t);

}