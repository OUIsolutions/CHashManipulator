
#include "CHashManipulator.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20),
            hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    //will set  the last element
    array.set_long(element,0,10);
    array.set_string(element,1,"aaaaaaa");
    array.set_bool(element,2,true);
    array.set_double(element,3,2.3);

    CHash_protected(element){
        hash.print(element);

    }

    CHash_catch(element){
        printf("%s",hash.get_error_menssage(element));

    }

    hash.free(element);

}