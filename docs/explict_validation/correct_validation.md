# Correct Validation Example

This example demonstrates how to use explicit validation to ensure data correctness. The code in `examples/ExplictValidation/Correct.c` shows how to validate an array of objects, each containing specific keys with specific types and constraints.

## Code Explanation

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

CHash *create() {
    return newCHashArray(
        newCHashObject("name", hash.newString("Mateus"), "age", hash.newNumber(26), "height", hash.newNumber(1.69), "married", hash.newBool(true)),
        newCHashObject("name", hash.newString("second name"), "age", hash.newNumber(42), "height", hash.newNumber(2.5), "married", hash.newBool(true)),
        newCHashObject("name", hash.newString("third name"), "age", hash.newNumber(55), "height", hash.newNumber(2.4), "married", hash.newBool(false))
    );
}

void validate(CHash *all_persons) {
    validator.ensure_Array(all_persons);
    CHash_for_in(person, all_persons, {
        validator.ensure_only_keys_cleaning_args(person, newCHashStringArray("name", "age", "height", "married"));
        validator.ensure_String_by_key(person, "name");
        validator.ensure_min_size_by_key(person, "name", 2);
        validator.ensure_max_size_by_key(person, "name", 30);
        validator.ensure_min_value_by_key(person, "age", 0);
        validator.ensure_max_value_by_key(person, "age", 120);
        validator.ensure_min_value_by_key(person, "height", 0.5);
        validator.ensure_max_value_by_key(person, "height", 2.5);
        validator.ensure_Bool_by_key(person, "married");
    });
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;
    validator = hash.validator;

    CHashArray *all_persons = create();
    validate(all_persons);
    CHash_catch(all_persons) {
        char *message = hash.get_error_message(all_persons);
        printf("%s\n", message);
        hash.free(all_persons);
        return 0;
    }

    CHash_for_in(current_person, all_persons, {
        printf("-----------------------------------------------\n");
        printf("\tname:%s\n", obj.getString(current_person, "name"));
        printf("\tage:%ld\n", (long)obj.getNumber(current_person, "age"));
        printf("\theight:%lf\n", obj.getNumber(current_person, "height"));
        printf("\tmarried:%s\n", obj.getBool(current_person, "married") ? "true" : "false");
    });
    hash.free(all_persons);
}
```

## Validation Steps

1. **Ensure Array**: The `validator.ensure_Array` function checks if the input is an array.
2. **Ensure Only Keys**: The `validator.ensure_only_keys_cleaning_args` function ensures that each object in the array contains only the specified keys.
3. **String Validation**: The `validator.ensure_String_by_key` function checks if the 'name' key is a string.
4. **String Length Validation**: The `validator.ensure_min_size_by_key` and `validator.ensure_max_size_by_key` functions ensure the 'name' string length is within the specified range.
5. **Numeric Validation**: The `validator.ensure_min_value_by_key` and `validator.ensure_max_value_by_key` functions check if the 'age' and 'height' values are within the specified ranges.
6. **Boolean Validation**: The `validator.ensure_Bool_by_key` function checks if the 'married' key is a boolean.

## Error Handling

If any validation fails, an error message is printed, and the program exits. This ensures that only valid data is processed.