## Setting Values in an Array

You can set values in an array using `array.set`. Here's how:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

CHashObject *create() {
    return newCHashArray(
        hash.newString("aaa"),
        hash.newNumber(26),
        hash.newNumber(20),
        hash.newBool(true)
    );
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    // Will set the last element
    array.set(element, -1, newCHashString("b"));

    CHash_protected(element) {
        hash.print(element);
    }

    CHash_catch(element) {
        printf("%s", hash.get_error_message(element));
    }

    hash.free(element);
}
```