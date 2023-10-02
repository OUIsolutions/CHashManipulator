#include "src/one.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newLong(26),
            hash.newDouble(20),
            hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    //will remove the last element
    array.remove(element, 30);

    if(!hash.errors(element)){
        hash.print(element);

    }
    else{
        printf("%s",hash.get_error_menssage(element));

    }

    hash.free(element);

}