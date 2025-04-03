# Raising Error by Index Example

This example demonstrates how to raise an error by index using explicit validation. The code in `examples/ExplictValidation/raising_by_index.c` shows how to raise a custom error for a specific index in an array.

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

    CHashObject *test = newCHashArray(newCHashString("aaaaaa"));
    int custom_code = 500;
    validator.raise_error_by_index(test, 0, custom_code, "my custom error at #path# with #arg1#", newCHashObject("arg1", hash.newString("aaaa")));

    CHash_catch(test) {
        short code = hash.get_error_code(test);
        char *message = hash.get_error_message(test);
        CHash *args = hash.get_error_args(test);

        printf("code: %d\n", code);
        printf("message: %s\n", message);
        printf("args:\n");
        CHash_print(args);
    }

    hash.free(test);
}
```

## Error Raising

The `validator.raise_error_by_index` function is used to raise a custom error for the first element (index 0) of the array. The custom error code is set to 500, and the error message includes a placeholder for an argument (`#arg1#`). The `newCHashObject` function is used to provide the argument value (`"aaaa"`).

## Error Handling

The `CHash_catch` block is used to catch the raised error. It retrieves the error code, message, and arguments, then prints them to the console. This allows for detailed error reporting and handling.