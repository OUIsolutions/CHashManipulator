
#include "src/one.h"
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(

        "a", newCHashObject(
                "age",newCHashDouble(26),
                "name",newCHashString("mateus")
            )
    );
}

int main(){

    CHashObject *t = newCHashLong(20);
    
    CHash_free(t);

}