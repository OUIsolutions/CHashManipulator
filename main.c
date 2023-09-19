
#include "src/one.h"
#include "src/one.h"




CHashObject *create (){
    return newCHashObject(
        "age",newCHashDouble(26),
        "name",newCHashString("mateus")
    );
}


int main(){

    privateCHashError *e = privatenewCHashError(
        newCHashObject("a",newCHashLong(10)),
        10,
        "value of #a#"
    );

    privateCHashError_free(e);

}