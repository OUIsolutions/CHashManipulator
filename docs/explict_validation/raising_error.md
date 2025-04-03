# Raising Error Example

This example demonstrates how to raise an error using explicit validation. The code in `examples/ExplictValidation/raising_error.c` shows how to raise a custom error for a specific value in an object.

## Code Explanation

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

    CHashObject *person = newCHashObject("name", hash.newString("aaaaaaaaa"));
    CHash *name = obj.get(person, "name");
    int custom_code = 500;
    validator.raise_error(name, custom_code, "my custom error at #path# with #arg1#", newCHashObject("arg1", hash.newString("aaaa")));

    CHash_catch(person) {
        short code = hash.get_error_code(person);
        char *message = hash.get_error_menssage(person);
        CHash *args = hash.get_error_args(person);

        printf("code: %d\n", code);
        printf("message: %s\n", message);
        printf("args:\n");
        CHash_print(args);
    }

    hash.free(person);
}
```

## Error Raising

The `validator.raise_error` function is used to raise a custom error for the 'name' value of the object. The custom error code is set to 500, and the error message includes a placeholder for an argument (`#arg1#`). The `newCHashObject` function is used to provide the argument value (`"aaaa"`).

## Error Handling

The `CHash_catch` block is used to catch the raised error. It retrieves the error code, message, and arguments, then prints them to the console. This allows for detailed error reporting and handling.