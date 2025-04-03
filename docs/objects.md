# Objects

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

## Object Iteration

You can iterate over an object using a loop. Here's an example:

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
    CHash_catch(profile) {
        printf("%s\n", hash.get_error_message(profile));
        hash.free(profile);
        return 1;
    }

    long size = hash.get_size(profile);
    for (int i = 0; i < size; i++) {

        char *key = obj.get_key_by_index(profile, i);
        printf("%s: ", key);
        int type = obj.get_type(profile, key);

        if (type == CHASH_STRING) {
            printf("%s", obj.getString(profile, key));
        }

        if (type == CHASH_NUMBER) {
            printf("%lf", obj.getNumber(profile, key));
        }

        if (type == CHASH_BOOL) {
            printf("%s", obj.getBool(profile, key) ? "true" : "false");
        }

        printf("\n");
    }
    hash.free(profile);
}
```

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

## Setting Default Values

You can set default values for keys in an object using `obj.set_default`. Here's an example:

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
        "nothing", hash.newString("aaaaaaaaa")
    );

    obj.set_default(person, "name", hash.newString("default string"));
    char *name = obj.getString(person, "name");
    printf("%s\n", name);

    hash.free(person);
}
```

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