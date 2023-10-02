
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

    obj.delete(profile,"maried");

    if(!hash.errors(profile)){
        hash.print(profile);
    }
    else{
        printf("%s\n",hash.get_error_menssage(profile));

    }


    hash.free(profile);

}