
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
    

}