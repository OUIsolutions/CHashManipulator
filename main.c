#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();


    CHash_append(element, newCHashString("aaaaaaaa"));
    CHash_append(element, newCHashLong(20));
    CHash_append(element, newCHashLong(43));


    CHash_get_item_from_position(element,-2);






    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

