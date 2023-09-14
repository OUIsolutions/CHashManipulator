#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();


    CHashArrayItem  * t = CHash_get_item_from_position(element,-1);
    CHash_set_item_value(t,NULL);







    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

