#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();


    CHashArrayItem  *t1  = CHashArray_new_item(element);
    CHash_set_value_to_ArrayItem_OR_KeyVal(t1, newCHashString("aaaaaaaaaa"));
    CHashArrayItem  *t2 = CHashArray_new_item(element);
    CHash_set_value_to_ArrayItem_OR_KeyVal(t2, newCHashString("aaaaaaaaaa"));


    CHashArrayItem  *t3 = CHashArray_new_item(element);




    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

