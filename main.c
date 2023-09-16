#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();

    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

