
#include "src/one.h"
#include "src/one.h"




CHashObject *create (){
    return newCHashObject(
        "age",newCHashDouble(26),
        "name",newCHashString("mateus")
    );
}


int main(){

    CHashObject *t = create();

    CHash *age = CHashObject_get(t,"age");
    CHash_raise_error(age,10,"value: #value# at #path# its not correct",NULL);

    //printf("error %s\n", CHash_get_error_menssage(age));
}