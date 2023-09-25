
#include "src/one.h"


CHashObject *create (){

    return newCHashObjectEmpty(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20)
    );

}




int main(){
    CHashArray *t = create();
    CHash_print(t);


}