#include "src/one.h"





CHashObject *create (){
    return newCHashObject(
        "age",newCHashDouble(26),
        "name",newCHashString("mateus")
    );
}


int main(){

    CHashObject *t = create();
    
    CHashObject *t2 = newCHashObject(
        "age",newCHashLong(27),
        "internal", CHash_copy(t)
    );

    CHash_print(t);    
    CHash_free(t);
    CHash_free(t2);

}