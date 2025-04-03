#include "release/CHashManipulatorOne.c"
CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = newCHashObject(
        "name",hash.newString("Mateus"),
        "age",hash.newNumber(26)
    );
    hash.dump_to_json_file(element,"out.json");

    hash.free(element);
}