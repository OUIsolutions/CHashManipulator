
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "name", newCHashLong(27),
            "age", newCHashLong(26)
    );
}

int main(){
    CHashArray *t = create();
    char *name = CHash_toString(CHashObject_get(t,"name"));
    if(Chash_errors(t)){
        char *menssage = CHash_get_error_menssage(t);
        printf("%s",menssage);
    }

}