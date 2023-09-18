#include "src/one.h"






CHash  * create(){
    return newCHashArray(
            newCHashString("aaa"),
            newCHashLong(20),
            newCHashArray(
                    newCHashString("aaaaaaaaa"),
                    newCHashLong(20)
            )
    );


}


int main(){

    CHashArray *t = create();
    //CHash_print(t);
    CHash_print(t);
}