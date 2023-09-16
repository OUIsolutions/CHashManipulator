#include "src/one.h"




CHashArray  * create_array(){

    CHashArray * element = newCHashArray();

    long size = CHash_get_size(element);
    for(int i = 0; i < size; i ++){

        CHashArrayItem *  current = CHash_get_from_index(element,size);
        int type = CHash_get_type(current);
        if(type == CHASH_STRING){
            char *value = CHash_get_string(current);
        }

    }

    return element;
}


int main(){
    CHashArray * element = create_array();
    long size = CHash_get_size(element);
    CHashPrint(element);


}

