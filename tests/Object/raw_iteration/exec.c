
#include "../../../CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newLong(26),
            "height",hash.newDouble(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *profile = create();

    long size = hash.get_size(profile);
    for(int i = 0; i < size; i++){
        CHash *element = hash.object.get_by_index(profile,i);
        char *key =  hash.object.get_key_of_element(element);
        printf("%s:",key);
        int type = hash.get_type(element);
        if(type == CHASH_STRING){
            printf("%s",hash.toString(element));
        }

        if(type == CHASH_DOUBLE){
            printf("%lf",hash.toDouble(element));
        }
        if(type == CHASH_LONG){
            printf("%ld",hash.toLong(element));
        }
        if(type == CHASH_BOOL){
            printf("%s", hash.toBool(element) ? "true":"false");
        }
        printf("\n");

    }
    hash.free(profile);

}