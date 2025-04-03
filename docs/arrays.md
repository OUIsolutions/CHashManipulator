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