
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "name", newCHashLong(27),
            "age", newCHashLong(26)
    );
}

int main(){
    CHashArray *t = create();

    CHash *name = newCHashArrayEmpty();
    CHashArray_append(name,
                      newCHashLong(10),
                      newCHashString("aaaaaa")
                      );

    CHash_print(name);


    if(Chash_errors(t)){
        char *menssage = CHash_get_error_menssage(t);
        printf("%s",menssage);
    }

}