
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

    CHashObject *t = create();
    //printf("t: %ld\n",t);
    CHash *e1  = CHashObject_get(t,"a");
    

    CHash *age = CHashObject_get(e1,"age");


    CHash_raise_error(age,10,"value: #value# at #path# its not correct",NULL);
    //CHash_print(age);
    printf("error %d\n",sizeof(CHash));

    if( Chash_errors(t)){

    }
    CHash_free(t);

}