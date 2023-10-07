#include "src/one.h"

CHashNamespace hash;


int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_file("side_effect/test.json");


    hash.free(element);

}