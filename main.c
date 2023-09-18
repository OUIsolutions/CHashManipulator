#include "src/one.h"






CHash  * create(){
    return newCHashObject(
            "name", newCHashString("Mateus"),
            "age", newCHashLong(26),
            "emails", newCHashArray(
                    newCHashString("mateusmoutinho01@gmail.com")
            ),
            "phones", newCHashArray(
                    newCHashString("0000"),
                    newCHashString("00000")
            ),
            "address", newCHashArray(
                    newCHashLong(2121),
                    newCHashLong(21212)
            )
    );


}


int main(){

    CHashArray *t = newCHashArray(NULL);
    CHashArray_append(t,
          newCHashString("aaaaaaaaa0"),
          newCHashLong(20)
    );



    //CHash_print(t);
    CHash_print(t);
}