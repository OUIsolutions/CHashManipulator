#include "src/one.h"

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
            "test2", newCHashObject(
                    "aa",hash.newString("aaaaaaaaa")
                    ),
            "test",hash.newNumber(0)
    );
    CHash *d = obj.getObject(elements,"test2");
    obj.getString(d,"aaaaaaaa");

    CHash_catch(elements){
        validator.generate_custom_error(elements, newCHashArray(

                newCHashObject(
                        "code",hash.newNumber(CHASH_ELEMENT_NOT_EXIST),
                        "message",hash.newString("element at #reference# its invalid")
                        )
                ));

        char *menssage = hash.get_error_menssage(elements);
        int clode = hash.get_error_code(elements);
        printf("%ld\n", clode);
        printf("%s\n",menssage);
    }

    obj.getNumber(elements,"aaaaaa");
    hash.free(elements);
}


