#include "src/one.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;
CTextNamespace ctext;

int main(){
    
    int r = 0;
    t1:
    printf("%ld\n",r);
    if(r < 20){
            r+=1;
            goto t1;
    }
    
    
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    ctext = newCTextNamespace();



}