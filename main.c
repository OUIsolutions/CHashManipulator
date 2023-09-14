#include "src/one.h"


typedef  void * AA;


CHashArray  * create_array(){

    CHashArray * element = newCHashArray();

    CHashArrayItem  *a1 = CHashArray_new_item(element);
    CHash_set_value(a1, newCHashLong(2444));


    CHash_append(element, newCHashString("aaaaaaaa"));
    CHash_append(element, newCHashLong(20));
    CHash_append(element, newCHashLong(43));


    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

