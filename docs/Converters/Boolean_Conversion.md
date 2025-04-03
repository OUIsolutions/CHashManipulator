# Boolean Conversion

The `obj.getBool_converting` function is used to convert various types of values to boolean. It supports the following conversions:

- **Boolean**: Directly converts boolean values.
- **Number**: Converts 0 to `false`, and any other number to `true`.
- **String**: Converts specific strings to boolean:
  - 'true',  to `true`
  - 'false',  to `false`

If the value cannot be converted to a boolean, an error is raised.

## Examples

### Correct Conversion

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

    CHashArray *elements = newCHashObject("test", hash.newBool(true));
    bool value = obj.getBool_converting(elements, "test");

    CHash_protected(elements) {
        printf("%s\n", value ? "true" : "false");
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example converts a boolean value to `true`.

### Conversion from Number

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

    CHashArray *elements = newCHashObject("test", hash.newNumber(0));
    bool value = obj.getBool_converting(elements, "test");

    CHash_protected(elements) {
        printf("%s\n", value ? "true" : "false");
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example converts the number 0 to `false`.

### Conversion from String

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

    CHashArray *elements = newCHashObject("test", hash.newString("true"));
    bool value = obj.getBool_converting(elements, "test");

    CHash_protected(elements) {
        printf("%s\n", value ? "true" : "false");
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example converts the string "true" to `true`.

### Incorrect Conversion

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

    CHashArray *elements = newCHashObject("test", hash.newString("aaaa"));
    bool value = obj.getBool_converting(elements, "test");

    CHash_protected(elements) {
        printf("%s\n", value ? "true" : "false");
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example attempts to convert the string "aaaa" to a boolean, which results in an error.
