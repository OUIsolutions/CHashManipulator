
#include "src/one.h"


CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20)
    );

}




int main(){
    CHashArray *t = create();
    CHash_set_by_key(t,
                     "aaaaa", newCHashLong(55)
    );

    CHash_print(t);


}