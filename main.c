
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "nameaa", newCHashLong(27),
            "age", newCHashLong(26)
    );
}

int main(){
    CHashArray *t = create();
    CHashObject_get(t,"name");
    if(Chash_errors(t)){
        char *menssage = CHash_get_error_menssage(t);
        printf("%s",menssage);
    }

}