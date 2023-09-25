
#include "src/one.h"



CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20),
            "ddd", newCHashArray(
                        newCHashLong(10),
                        newCHashString("aaaaaaaaaa")
                    )
    );

}

int main(){
    CHashArray *t = create();

   char *name = hash.toString(object.get(t,"name"));

   long age = hash.toLong(object.get(t,"age"));

}