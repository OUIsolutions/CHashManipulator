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

    CHashArray_delete(t,0);
    CHash_print(t);
    CHash_free(t);

}