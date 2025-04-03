## Setting Values of an Object

You can set multiple values of an object using `CHashObject_set_many`. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

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
    validator = hash.validator;

    CHashArray *profile = create();

    validator.ensure_Object(profile);
    if (hash.errors(profile)) {
        printf("%s\n", hash.get_error_message(profile));
        hash.free(profile);
        return 1;
    }

    CHashObject_set_many(profile,
        "age", hash.newNumber(18),
        "married", hash.newBool(false)
    );

    hash.print(profile);

    hash.free(profile);
}
```