
#include "src/one.h"
#include "src/one.h"



CHashObject *create (){
    
    return newCHashObject(
        "a", newCHashObject(
                "age", newCHashString("aaaaaaa"),
                "name",newCHashString("mateus")
            )
    );

}

int main(){

    CHashObject *t = create();


    CHash *a = CHash_get_any_by_key(t, "a");
    double age = CHash_toDouble(CHash_get_any_by_key(a,"age"));
    char *name = CHash_toString(CHash_get_any_by_key(a,"name"));


    if(!Chash_errors(a)){
        //here its safe to work with any primitive var
        printf("age: %lf\n",age);
        printf("name: %s\n",name);
    }

    else{
        printf("%s", CHash_get_error_menssage(a));

    }


    CHash_free(t);

}