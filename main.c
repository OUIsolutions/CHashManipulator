#include "src/one.h"


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