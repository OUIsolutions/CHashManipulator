
#include "../../../CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;



CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newNumber(26),
            "height",hash.newNumber(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *profile = create();

    obj.remove(profile,"maried");

    CHash_protected(profile){
        hash.print(profile);
    }

    CHash_catch(profile){
        printf("%s\n",hash.get_error_menssage(profile));

    }


    hash.free(profile);

}