## Dealing with Optional Values

You can check if a key exists in an object using `obj.exist`. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;
    validator = hash.validator;

    CHashArray *person = newCHashObject(
        "name", hash.newString("aaaaaaaaa")
    );

    if (obj.exist(person, "name")) {
        char *name = obj.getString(person, "name");
        printf("%s\n", name);
    }

    hash.free(person);
}
```