
# Releases

| Item | Description |
|------|-------------|
|[CHashManipulatorOne.c](https://github.com/OUIsolutions/CHashManipulator/releases/download/0.2.0/CHashManipulatorOne.c)| CHashManipulato One file |
|[CHashManipulator.c](https://github.com/OUIsolutions/CHashManipulator/releases/download/0.2.0/CHashManipulator.c)| Definition|
|[CHashManipulator.h](https://github.com/OUIsolutions/CHashManipulator/releases/download/0.2.0/CHashManipulator.h)| Header|
|[CHashManipulator.zip](https://github.com/OUIsolutions/CHashManipulator/releases/download/0.2.0/CHashManipulator.zip)| Full Folder that can be included with **src/one.c**|

# Basic Example

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
int main() {
    hash = newCHashNamespace();
    CHashObjectModule obj = hash.object;
    CHashArrayModule array = hash.array;

    CHash *person = newCHashObject("name", hash.newString("John"), "age", hash.newNumber(30));

    CHash_protected(person) {
        printf("Name: %s\n", obj.getString(person, "name"));
        printf("Age: %ld\n", (long)obj.getNumber(person, "age"));
    }

    CHash_catch(person) {
        printf("Error: %s\n", hash.get_error_menssage(person));
    }

    hash.free(person);
    return 0;
}

```

# Documentation
| Item | Description |
|------|-------------|
| [build_and_install.md](/docs/build_and_install.md) | Instructions for installing and compiling the library on Linux, Windows, and building from scratch on Darwin. |
| [array_creation.md](/docs/array/array_creation.md) | Function to create an array. |
| [array_append.md](/docs/array/array_append.md) | Method to append elements to an array. |
| [array_delete.md](/docs/array/array_delete.md) | Method to delete elements from an array. |
| [array_iteration.md](/docs/array/array_iteration.md) | Method to iterate over array elements. |
| [array_set.md](/docs/array/array_set.md) | Method to set values in an array. |
| [object_creation.md](/docs/object/object_creation.md) | Function to create an object. |
| [object_iteration.md](/docs/object/object_iteration.md) | Method to iterate over object keys and values. |
| [object_set_values.md](/docs/object/object_set_values.md) | Method to set values in an object. |
| [object_check_existence.md](/docs/object/object_check_existence.md) | Method to check for key existence. |
| [object_set_default.md](/docs/object/object_set_default.md) | Method to set default values for keys. |
| [object_delete_key.md](/docs/object/object_delete_key.md) | Method to delete keys from an object. |
| [validation.md](/docs/validation.md) | Functions for data validation, error raising, and custom error creation. |
| [Boolean_Conversion.md](/docs/Converters/Boolean_Conversion.md) | Converts values to boolean. |
| [Number_Conversion.md](/docs/Converters/Number_Conversion.md) | Converts values to numbers. |
| [introduction.md](/docs/explict_validation/introduction.md) | Overview of explicit validation techniques. |
| [incorrect_age.md](/docs/explict_validation/incorrect_age.md) | Example of incorrect age validation. |
| [incorrect_size.md](/docs/explict_validation/incorrect_size.md) | Example of incorrect size validation. |
| [custom_error.md](/docs/explict_validation/custom_error.md) | Example of custom error creation. |
| [raising_by_index.md](/docs/explict_validation/raising_by_index.md) | Example of raising errors by index. |
| [raising_by_key.md](/docs/explict_validation/raising_by_key.md) | Example of raising errors by key. |
| [raising_error.md](/docs/explict_validation/raising_error.md) | Example of raising errors. |
| [correct_validation.md](/docs/explict_validation/correct_validation.md) | Example of correct validation. |
| [foreach_with_args.md](/docs/iterables/foreach_with_args.md) | Example of foreach with arguments. |
| [for_in.md](/docs/iterables/for_in.md) | Example of for_in iteration. |
| [foreach.md](/docs/iterables/foreach.md) | Example of foreach iteration. |
| [dumping_to_file.md](/docs/jsons/dumping_to_file.md) | Example of dumping JSON to a file. |
| [dumping_to_string.md](/docs/jsons/dumping_to_string.md) | Example of dumping JSON to a string. |
| [loading_from_file.md](/docs/jsons/loading_from_file.md) | Example of loading JSON from a file. |
| [loading_from_string.md](/docs/jsons/loading_from_string.md) | Example of loading JSON from a string. |
| [handling_errors.md](/docs/jsons/handling_errors.md) | Example of handling JSON errors. |
|[dependencies.md](/docs/dependencies.md)| List of dependencies for the library. |