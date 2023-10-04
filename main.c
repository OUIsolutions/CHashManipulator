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

    char *teste[2]={0};
    char *menssage = "💩💩💩";

    for(int i = 0 ; i < strlen(menssage); i++){
        long current = menssage[i];
        printf("valor: %ld\n",current);
    }

}