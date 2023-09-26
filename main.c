
#include "src/one.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

CHashObject *create (){

    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newLong(26),
            "phones", newCHashStringArray(
                    "000000000",
                    "0000000000"
            )
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *t = create();


    if(Chash_errors(t)){
        char *menssage = CHash_get_error_menssage(t);
        printf("%s",menssage);
    }

}