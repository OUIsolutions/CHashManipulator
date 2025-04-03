#include "release/CHashManipulatorOne.c"

CHashNamespace hash;
int main(){
CHashArray *elements = newCHashObject("test", hash.newNull());
double value = hash.obj.getNumber_converting(elements, "test"); // This will raise an 

}