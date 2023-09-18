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

    CHash *adrres = CHashObject_get(t,"phones");

    CHash *first_pthone = CHashArray_get(adrres,1);

    CHashArray  * first_phone_path = CHash_get_path(first_pthone);
    CHash_print(first_phone_path);

    CHash_free(t);
}