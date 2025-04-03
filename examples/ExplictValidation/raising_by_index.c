
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

    CHashObject *test = newCHashArray(
            newCHashString("aaaaaa")
            );
    int custom_code = 500;
    validator.raise_error_by_index(
            test,
            0,
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1",hash.newString("aaaa")));

    CHash_catch(test){
        short  code = hash.get_error_code(test);
        char *menssage=  hash.get_error_menssage(test);
        CHash *args = hash.get_error_args(test);

        printf("code: %d\n",code);
        printf("menssage: %s\n",menssage);
        printf("args:\n");
        CHash_print(args);

    }


    hash.free(test);

}