# Arrays

## Creating an Array

To create an array, use the `newCHashArray` function. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;

CHashObject *create() {
    return newCHashArray(
        hash.newString("aaa"),
        hash.newNumber(26),
        hash.newNumber(20)
    );
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;

    CHashArray *element = create();
    char *name = array.getString(element, 0);
    long age = array.getNumber(element, 1);
    double height = array.getNumber(element, 2);

    CHash_protected(element) {
        printf("name: %s\n", name);
        printf("age %ld\n", age);
        printf("height %lf\n", height);
    }

    CHash_catch(element) {
        char *message = hash.get_error_message(element);
        printf("%s", message);
    }
    hash.free(element);
}
```
