
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

    CHashArray *t = create();

    char *name =obj.getString(t,"name");
    long age = obj.getLong(t,"age");
    double height = obj.getDouble(t,"height");

    bool maried = obj.getBool(t,"maried");

    if(hash.errors(t) == false){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
        printf("maried %s\n", maried ? "true":"false");
    }

    else{
        char *menssage = hash.get_error_menssage(t);
        printf("%s",menssage);
    }

}