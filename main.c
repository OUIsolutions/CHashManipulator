#include "src/one.h"




CHashObject *create (){
    return newCHashObject(
        "age",newCHashDouble(26),
        "name",newCHashString("mateus")
    );
}


int main(){

    CHashObject *t = newCHashArray(
            newCHashDouble(21),
            newCHashString("aaaaaaaa"),
            newCHashDouble(21)
    );
    CHashObject *t2 = newCHashArray(
            newCHashDouble(21),
            newCHashString("aaaaaaaa"),
            newCHashDouble(20)
    );
    CHash_print(t);
    CHash_free(t);

}