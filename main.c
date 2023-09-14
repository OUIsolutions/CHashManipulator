#include "src/one.h"

CHashObject * teste(){
    privateCHashAny * t = malloc(sizeof(privateCHashAny));
    t->type = 2;
    t->value = strdup("aaaaaaaaaa");
    return t;
}

int main(){
    CHashObject *a = teste();

}

