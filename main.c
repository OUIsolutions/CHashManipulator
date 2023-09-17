#include "src/one.h"

CHashArray  * create(){
    CHashArray  *t = newCHashArray();
    CHashArray_append(t, newCHashLong(20));
    CHashArray_append(t, newCHashLong(20));
    CHashArray_append(t, newCHashLong(20));
    CHashArray  *t2 = newCHashArray();
    CHashArray_append(t2, newCHashString("aaaaaaaaaa"));
    CHashArray_append(t2, newCHashString("aaaaaaaaaa"));
    CHashArray_append(t,t2);
    return t;

}


int main(){



}