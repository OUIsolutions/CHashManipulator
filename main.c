
#include "src/one.h"
#include "src/one.h"




CHashObject *create (){
    return newCHashObject(
        "age",newCHashDouble(26),
        "name",newCHashString("mateus")
    );
}


int main(){

    CHashObject *t = newCHashObject(
            "name", newCHashString("mateus"),
            "age", newCHashLong(26)
            );

    char *r = CHash_toString(CHashObject_get(t,"name"));
    privateCHashError  * e = privatenewCHashError(
            newCHashObject("a", newCHashString("aaaaaaa")),
            10,
            " the value of a= #a# "
    );

    printf("valor: %s\n",e->error_mensage->rendered_text);

}