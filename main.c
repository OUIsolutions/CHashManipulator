
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "name", newCHashDouble(10),
            "age", newCHashLong(26),
            "phones", newCHashStringArray(
                    "000000000",
                    "0000000000"
            )
    );
}

int main(){
    CHashArray *t = create();
    CHash_print(t);

    if(Chash_errors(t)){
        char *menssage = CHash_get_error_menssage(t);
        printf("%s",menssage);
    }

}