
#include "../../../CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *element = create();
    char *name  = array.getString(element,0);
    long age = array.getNumber(element,1);
    double height = array.getNumber(element,2);

    if(!hash.errors(element)){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
    }

    else{
        char *menssage = hash.get_error_menssage(element);
        printf("%s",menssage);
    }
    hash.free(element);

}