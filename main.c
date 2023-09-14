#include "src/one.h"


typedef  void * AA;


CHashArray  * create_array(){

    CHashArray * element = newCHashArray();

    CHashArrayItem  *a1 = CHashArray_new_item(element);
    CHash_set_value(a1, newCHashLong(2444));


    CHashArray_append(element, newCHashString("aaaaaaaa"));
    CHashArray_append(element, newCHashLong(20));
    CHashArray_append(element, newCHashLong(43));


    return element;
}


int main(){
    CHashArray * element = create_array();
    CHashPrint(element);


}

