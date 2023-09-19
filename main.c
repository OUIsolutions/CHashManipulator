
#include "src/one.h"
#include "src/one.h"




CHashObject *create (){

    return newCHashArray(
        newCHashObject(
                "age",newCHashDouble(26),
                "name",newCHashString("mateus")
            )
    );
}


int main(){

    CHashObject *t = create();
    //printf("t: %ld\n",t);

    CHash *e1  = CHashArray_get(t,0);
    CHash *age = CHashObject_get(e1,"age");

    CHash_raise_error(age,10,"value: #value# at #path# its not correct",NULL);
    //CHash_print(age);
    if( Chash_errors(t)){
    printf("error %s\n",CHash_get_error_menssage(t));

    }
    CHash_free(t);

}