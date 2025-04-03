
#include "CHashManipulatorOne.c"




CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newNumber(26),
            "height",hash.newNumber(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *profile = create();
    validator.ensure_Object(profile);
    CHash_catch(profile){
        printf("%s\n",hash.get_error_menssage(profile));
        hash.free(profile);
        return 1;
    }

    long size = hash.get_size(profile);
    for(int i = 0; i < size; i++){

        char *key = obj.get_key_by_index(profile,i);
        printf("%s: ",key);
        int type = obj.get_type(profile, key);

        if(type == CHASH_STRING){
            printf("%s",obj.getString(profile,key));
        }

        if(type == CHASH_NUMBER){
            printf("%lf",obj.getNumber(profile,key));
        }

        if(type == CHASH_BOOL){
            printf("%s",obj.getBool(profile,key)  ? "true":"false");
        }

        printf("\n");

    }
    hash.free(profile);

}