#include "src/one.h"

CHashObject * teste(){
    CHashAny * t = malloc(sizeof(CHashAny));
    t->type = 2;
    t->value = strdup("aaaaaaaaaa");
    return t;
}

int main(){
    CHashObject *a = teste();

}

