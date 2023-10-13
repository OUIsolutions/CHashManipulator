
#include "../../../../CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;


int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *elements = newCHashObject(
            "test",hash.newString("aaa")
    );
    double value = obj.getNumber_converting(elements,"test");
    CHash_protected(elements){
        printf("%lf\n",value);
    }
    CHash_catch(elements){
        char *menssage = hash.get_error_menssage(elements);
        printf("%s\n",menssage);
    }

    hash.free(elements);



}