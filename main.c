#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();


    CHash_append_value_to_Array_OR_Object(element, newCHashString("aaaaaaaaaa"));
    CHash_append_value_to_Array_OR_Object(element, newCHashString("aaaaaaaaaa"));
    CHash_append_value_to_Array_OR_Object(element, newCHashString("aaaaaaaaaa"));

    
    CHashArrayItem  *t3 = CHashArray_new_item(element);




    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

