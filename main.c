#include "src/one.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHashObject *create (){
    return newCHashArray(
            newCHashLong(10),
            newCHashString("aaa")
            );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *profile = create();
    CHashArray_switch(profile,0,1);

    hash.print(profile);
    hash.free(profile);

}