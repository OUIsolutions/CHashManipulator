
#include "../../../CHashManipulator.h"




CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newLong(26),
            hash.newDouble(20)
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

        char *key = obj.get_key_by_index(profile,i);
        printf("%s: ",key);
        int type = obj.get_type(profile, key);

        if(type == CHASH_STRING){
            printf("%s",obj.getString(profile,key));
        }

        if(type == CHASH_DOUBLE){
            printf("%lf",obj.getDouble(profile,key));
        }
        if(type == CHASH_LONG){
            printf("%ld",obj.getLong(profile,key));
        }
        if(type == CHASH_BOOL){
            printf("%s",obj.getBool(profile,key)  ? "true":"false");
        }

        printf("\n");

    }
    hash.free(profile);

}