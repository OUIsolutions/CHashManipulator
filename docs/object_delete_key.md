## Deleting Keys from an Object

You can delete keys from an object using `obj.remove`. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;

CHashObject *create() {
    return newCHashObject(
        "name", hash.newString("aaa"),
        "age", hash.newNumber(26),
        "height", hash.newNumber(20),
        "married", hash.newBool(true)
    );
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;

    CHashArray *profile = create();

    obj.remove(profile, "married");

    CHash_protected(profile) {
        hash.print(profile);
    }

    CHash_catch(profile) {
        printf("%s\n", hash.get_error_message(profile));
    }

    hash.free(profile);
}
```