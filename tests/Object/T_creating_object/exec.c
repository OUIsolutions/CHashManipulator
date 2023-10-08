
#include "../../../CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

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

    CHashArray *profile = create();

    char *name = obj.getString(profile,"name");
    long age = obj.getNumber(profile,"age");
    double height = obj.getNumber(profile,"height");
    bool maried = obj.getBool(profile,"maried");

    CHash_protected(profile){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
        printf("maried %s\n", maried ? "true":"false");
    }

    CHash_catch(profile){
        char *menssage = hash.get_error_menssage(profile);
        printf("%s",menssage);
    }
    hash.free(profile);

}