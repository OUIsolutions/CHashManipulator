
#include "src/one.h"


CHashObject *create (){

    return newCHashObjectMacro(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20)
    );

}

int main(){

    CHashArray *t = create();
    CHash_print(t);


}