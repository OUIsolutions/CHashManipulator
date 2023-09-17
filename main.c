#include "src/one.h"






CHash  * create(){
    CHashArray  *t = newCHashArray();
    CHashArray_append(t, newCHashString("aaaa"));

    CHashArray_append(t, newCHashLong(20));
    CHashArray_append(t, newCHashString("aaaa"));
    CHashArray_append(t, newCHashString("aaaa"));

    return t;
}

int main(){

    CHashArray *t = create();
    CHash_print(t);

}