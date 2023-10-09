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

    CHashArray *element = newCHashObject(
            "a",hash.newNumber(1),
            "b",hash.newString("aaa"),
            "c", newCHashArray(newCHashString("aaaaaa")),
            "d",hash.newNULL()
            );

    CHash *a = obj.get(element,"a");
    hash.set(a,hash.newString("aaaaaaaaa"));

    CHash *b = obj.get(element,"b");
    hash.set(b,hash.newNumber(21));

    CHash  *c = obj.get(element,"c");
    hash.set(c,newCHashArray(newCHashString("aaaaaaa")));

    CHash  *d  = obj.get(element,"d");
    hash.set(d, newCHashObject("aa",hash.newNumber(20)));

    CHash_protected(element){
        CHash_print(element);
    }
    hash.free(element);

}