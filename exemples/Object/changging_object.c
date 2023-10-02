
#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;


CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newLong(26),
            "height",hash.newDouble(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *profile = create();

    validator.ensure_Object(profile);
    if(hash.errors(profile)){
        printf("%s\n",hash.get_error_menssage(profile));
        hash.free(profile);
        return 1;
    }

    CHashObject_set(profile,
        "age", newCHashLong(18),
        "maried", newCHashBool(false)
    );

    hash.print(profile);

    hash.free(profile);

}