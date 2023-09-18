#include "src/one.h"








int main(){

    CHash * t = newCHashObject(
            "name", newCHashNULL(),
            "age", newCHashLong(26)
            );
    CHash_print(t);
    CHash_free(t);

}