
#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;



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

    CHashArray *profile = create();

    CHashObject_set(profile,
        "age", newCHashLong(18),
        "maried", newCHashBool(false)
    );

    if(hash.errors(profile)){
        printf("%s\n",hash.get_error_menssage(profile));
    }
    else{
        hash.print(profile);

    }

    hash.free(profile);

}