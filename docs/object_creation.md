## Creating an Object

To create an object, use the `newCHashObject` function. Here's an example:

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

    char *name = obj.getString(profile, "name");
    long age = obj.getNumber(profile, "age");
    double height = obj.getNumber(profile, "height");
    bool married = obj.getBool(profile, "married");

    CHash_protected(profile) {
        printf("name: %s\n", name);
        printf("age %ld\n", age);
        printf("height %lf\n", height);
        printf("married %s\n", married ? "true" : "false");
    }

    CHash_catch(profile) {
        char *message = hash.get_error_message(profile);
        printf("%s", message);
    }
    hash.free(profile);
}
```