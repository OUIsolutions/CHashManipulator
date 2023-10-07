#include "CHashManipulator.h"

CHashNamespace hash;


int main(){
    hash = newCHashNamespace();

    CHash *element = newCHashObject(
        "name",hash.newString("Mateus"),
        "age",hash.newNumber(26)
    );
    char *result = hash.dump_to_json_string(element);
    printf("%s",result);
    free(result);

    hash.free(element);

}