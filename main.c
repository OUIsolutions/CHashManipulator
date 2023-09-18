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

    CHashObject *t = create();

    CHashObject_set(t,
       "name", newCHashLong(20),
        "b", newCHashLong(30)
    );
    CHashObject_set(t,"xxx", newCHashString("sssssss"));


    CHash_print(t);
    CHash_free(t);
}