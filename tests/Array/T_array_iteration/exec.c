
#include "../../../CHashManipulator.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newLong(26),
            hash.newDouble(20),
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

        if(type == CHASH_DOUBLE){
            printf("%lf\n",array.getDouble(element,i));
        }
        if(type == CHASH_LONG){
            printf("%ld\n",array.getLong(element,i));
        }
        if(type == CHASH_BOOL){
            printf("%s\n",array.getBool(element,i)  ? "true":"false");
        }


    }

    if(hash.errors(element)){
        printf("%s",hash.get_error_menssage(element));
    }

    hash.free(element);

}