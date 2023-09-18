#include "src/one.h"








int main(){

    CHash * t = newCHashObject(
            "name", newCHashNULL(),
            "age", newCHashLong(26)
            );
    CHash_print(t);
    CHash_free(t);

    double t1 = 2.3;
    double rest = t1 - (double)(long)t1;
    printf("%lf",rest);
}