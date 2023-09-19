
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
    //printf("t: %ld\n",t);
    CHash *age = CHashObject_get(t,"age");
    CHash_raise_error(age,10,"value: #value# at #path# its not correct",NULL);

    //printf("first: %ld\n",age->private_first);

    printf("error %d\n", Chash_errors(t));
    CHash_free(t);

}