
#include "../../../CHashManipulator.h"


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

    CHashStringArray  * keys = obj.get_keys(profile);
    long keys_size = hash.get_size(keys);
    for(int i = 0; i < keys_size; i ++){

    }


    hash.free(profile);

}