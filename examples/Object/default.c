#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *person = newCHashObject(
        "nothing",hash.newString("aaaaaaaaa")
    );

    obj.set_default(person,"name",hash.newString("default string"));
    char *name = obj.getString(person,"name");
    printf("%s\n",name);
    


    hash.free(person);

}