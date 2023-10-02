#include "src/one.h"


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
    CHash * current = obj.get_by_index(profile,-1);

    if(hash.errors(profile)){
        printf("%s\n",hash.get_error_menssage(profile));
    }
    else{
        hash.print(current);

    }

    hash.free(profile);

}