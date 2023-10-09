
#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashObject *person = newCHashObject(
            "name",hash.newString("aaaaaaaaa")
    );

    int custom_code = 500;
    validator.raise_error_by_key(
            person,
            "name",
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1",hash.newString("aaaa")));

    CHash_catch(person){
        short  code = hash.get_error_code(person);
        char *menssage=  hash.get_error_menssage(person);
        CHash *args = hash.get_error_args(person);

        printf("code: %d\n",code);
        printf("menssage: %s\n",menssage);
        printf("args:\n");
        CHash_print(args);

    }


    hash.free(person);

}