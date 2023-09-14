#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();

    CHashArray_append(element, newCHashString("aaaaaaaaaa"));
    CHashArray_append(element, newCHashString("aaaaaaaaaa"));
    CHashArray_append(element, newCHashString("aaaaaaaaaa"));


    CHashArrayItem  *t3 = CHashArray_new_item(element);




    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

