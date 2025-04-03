
#include "CHashManipulator.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20),
            hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    long size = hash.get_size(element);


    for(int i = 0; i < size; i++){

        int type = array.get_type(element, i);

        if(type == CHASH_STRING){
            printf("%s\n",array.getString(element, i));
        }

        if(type == CHASH_NUMBER){
            printf("%lf\n",array.getNumber(element,i));
        }

        if(type == CHASH_BOOL){
            printf("%s\n",array.getBool(element,i)  ? "true":"false");
        }


    }

   CHash_catch(element){
        printf("%s",hash.get_error_menssage(element));
    }

    hash.free(element);

}