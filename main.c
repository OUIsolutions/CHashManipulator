
#include "src/one.h"


CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20)
    );

}




int main(){
    TESTE(10,20,3);

    CHashArray *t = create();
    CHash_print(t);


}