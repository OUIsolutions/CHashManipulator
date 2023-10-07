#include "../../../CHashManipulator.h"

CHashNamespace hash;


int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_file("side_effect/test.json");
    hash.print(element);

    hash.free(element);

}