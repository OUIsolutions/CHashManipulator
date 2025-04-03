## Appending Values to an Array

You can append values to an array using `CHashArray_append`. Here's how:

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

    CHashArray_append(
        element,
        hash.newString("b"),
        hash.newString("c")
    );

    if (!hash.errors(element)) {
        hash.print(element);
    } else {
        printf("%s", hash.get_error_message(element));
    }

    hash.free(element);
}
```