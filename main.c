#include "src/one.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;
CHashObject *create (){
    return newCHashObject(
            "name",hash.newString("mateus"),
            "age", hash.newLong(26),
            "height",hash.newDouble(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *profile = create();

    char *name =obj.getString(profile,"name");
    long age = obj.getLong(profile,"age");
    double height = obj.getDouble(profile,"height");
    bool maried = obj.getBool(profile,"maried");


    CHashObject *second = newCHashObject(
            "name",  obj.get(profile,"name"),
            "age",obj.get(profile,"age")
            );

    hash.print(second);
   hash.free(second);

    if(!hash.errors(profile)){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
        printf("maried %s\n", maried ? "true":"false");
    }

    else{
        char *menssage = hash.get_error_menssage(profile);
        printf("%s",menssage);
    }
    hash.free(profile);

}