#include "src/one.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;
CTextStackModule  stack;

int main(){

    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    stack = newCTextStackModule();



}