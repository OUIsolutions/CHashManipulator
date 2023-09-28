
#include "src/one.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

CHashObject *create (){

    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newLong(26),
            "heigh",hash.newDouble(1.86),
            "maried",hash.newBool(false)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *t = create();

    char *name = hash.toString(obj.get(t,"name"));
    long age = hash.toLong(obj.get(t,"age"));

    if(!hash.errors(t)){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
    }
    CHashArray  *phones = obj.get(t,"phones");
    long  size = hash.get_size(phones);
    if(!hash.errors(t)){
        printf("phones: \n");
    }
    for(int i =0; i < size; i++){
        char *current = hash.toString(array.get(phones,i));
        if(!hash.errors(t)){
            printf("\t%s\n",current);
        }
    }


    if(hash.errors(t)){
        char *menssage = hash.get_error_menssage(t);
        printf("%s",menssage);
    }

}