# Number Conversion

The `obj.getNumber_converting` function is used to convert values to numbers. It supports the following conversions:

- **Number**: Directly converts number values.
- **String**: Converts string representations of numbers to numbers.

If the value cannot be converted to a number, an error is raised.

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

    CHashArray *elements = newCHashObject("test", hash.newNumber(10));
    double value = obj.getNumber_converting(elements, "test");

    CHash_protected(elements) {
        printf("%lf\n", value);
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example converts the number 10 to a double.

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

    CHashArray *elements = newCHashObject("test", hash.newString("10"));
    double value = obj.getNumber_converting(elements, "test");

    CHash_protected(elements) {
        printf("%lf\n", value);
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example converts the string "10" to a double.

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

    CHashArray *elements = newCHashObject("test", hash.newString("aaa"));
    double value = obj.getNumber_converting(elements, "test");

    CHash_protected(elements) {
        printf("%lf\n", value);
    }

    CHash_catch(elements) {
        char *message = hash.get_error_menssage(elements);
        printf("%s\n", message);
    }

    hash.free(elements);
}
```

This example attempts to convert the string "aaa" to a number, which results in an error.
