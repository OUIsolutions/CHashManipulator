## Deleting Elements from an Array

To delete an element from an array, use `array.remove`. Here's an example:

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

    // Will remove the last element
    array.remove(element, -1);

    CHash_protected(element) {
        hash.print(element);
    }

    CHash_catch(element) {
        printf("%s", hash.get_error_message(element));
    }

    hash.free(element);
}
```