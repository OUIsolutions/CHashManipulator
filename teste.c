#include "release/CHashManipulatorOne.c"

CHashNamespace hash;
int main() {
    hash = newCHashNamespace();
    CHashObjectModule obj = hash.object;
    CHashArrayModule array = hash.array;

    CHash *person = newCHashObject("name", hash.newString("John"), "age", hash.newNumber(30));

    CHash_protected(person) {
        printf("Name: %s\n", obj.getString(person, "name"));
        printf("Age: %ld\n", (long)obj.getNumber(person, "age"));
    }

    CHash_catch(person) {
        printf("Error: %s\n", hash.get_error_menssage(person));
    }

    hash.free(person);
    return 0;
}