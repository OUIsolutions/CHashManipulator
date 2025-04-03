
#include "CHashManipulatorOne.c"



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

    array.append_string(element,"test1");
    array.append_long(element,10);
    array.append_double(element,2.5);
    array.append_bool(element,true);

    if(!hash.errors(element)){
        hash.print(element);

    }
    else{
        printf("%s",hash.get_error_menssage(element));

    }

    hash.free(element);

}