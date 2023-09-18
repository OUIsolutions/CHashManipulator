#include "src/one.h"






CHash  * create(){
    CHashArray  *t = newCHashObject();
    CHashObject_set(t,"a", newCHashString("aaaa"));
    CHashObject_set(t,"b", newCHashString("aaaa"));

    return t;
}

void test(...){

}
int main(){

    CHashArray *t = create();
    //CHash_print(t);
    CHash_print(t);
}