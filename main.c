#include "src/one.h"





CHashObject *create (){
    return newCHashObject(
        "age",newCHashLong(26),
        "name",newCHashString("mateus")
    );
}


int main(){

    CHashObject *t = newCHashArray(
        newCHashDouble(2.4),
        newCHashLong(2),
                newCHashDouble(2.4),
        newCHashDouble(2.4),
        newCHashString("aaaaaaaaaa")

    );
    
    CHashObject *t2 = newCHashObject(
        "age",newCHashLong(27),
        "internal", CHash_copy(t)
    );

    CHash_print(t2);    
    CHash_free(t);
    CHash_free(t2);

}