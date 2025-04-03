# Validation

With the validation system, you can test parts of the data structure to ensure everything is correct.

## Validating Data

Here's an example of how to validate data:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

CHash *create() {

    return newCHashArray(

            newCHashObject(
                    "name", hash.newString("Mateus"),
                    "age", hash.newNumber(26),
                    "height", hash.newNumber(1.69),
                    "married", hash.newBool(true)
            ),
            newCHashObject(
                    "name", hash.newString("second name"),
                    "age", hash.newNumber(42),
                    "height", hash.newNumber(2.5),
                    "married", hash.newBool(true)
            ),

            newCHashObject(
                    "name", hash.newString("third name"),
                    "age", hash.newNumber(55),
                    "height", hash.newNumber(2.4),
                    "married", hash.newBool(false)
            )
    );
}

void validate(CHash *all_persons) {
    validator.ensure_Array(all_persons);
    CHash_for_in(person, all_persons, {
        validator.ensure_only_keys_cleaning_args(person, newCHashStringArray(
                "name", "age", "height", "married"
        ));
        validator.ensure_String_by_key(person, "name");
        validator.ensure_min_size_by_key(person, "name", 2);
        validator.ensure_max_size_by_key(person, "name", 30);
        validator.ensure_min_value_by_key(person, "age", 0);
        validator.ensure_max_value_by_key(person, "age", 120);
        validator.ensure_min_value_by_key(person, "height", 0.5);
        validator.ensure_max_value_by_key(person, "height", 2.5);
        validator.ensure_Bool_by_key(person, "married");
    })
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
        printf("\tage:%ld\n", (long) obj.getNumber(current_person, "age"));
        printf("\tage:%lf\n", obj.getNumber(current_person, "height"));
        printf("\tmarried:%s\n", obj.getBool(current_person, "married") ? "true" : "false");
    })
    hash.free(all_persons);
}
```

## Raising an Error

You can raise an error using `validator.raise_error`. Here's an example:

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

    CHashObject *person = newCHashObject(
            "name", hash.newString("aaaaaaaaa")
    );
    CHash *name = obj.get(person, "name");
    int custom_code = 500;
    validator.raise_error(
            name,
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1", hash.newString("aaaa")));

    CHash_catch(person) {
        short code = hash.get_error_code(person);
        char *message = hash.get_error_message(person);
        CHash *args = hash.get_error_args(person);

        printf("code: %d\n", code);
        printf("message: %s\n", message);
        printf("args:\n");
        CHash_print(args);
    }

    hash.free(person);
}
```

## Raising an Error by Key

You can raise an error by key using `validator.raise_error_by_key`. Here's an example:

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

    CHashObject *person = newCHashObject(
            "name", hash.newString("aaaaaaaaa")
    );

    int custom_code = 500;
    validator.raise_error_by_key(
            person,
            "name",
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1", hash.newString("aaaa")));

    CHash_catch(person) {
        short code = hash.get_error_code(person);
        char *message = hash.get_error_message(person);
        CHash *args = hash.get_error_args(person);

        printf("code: %d\n", code);
        printf("message: %s\n", message);
        printf("args:\n");
        CHash_print(args);
    }

    hash.free(person);
}
```

## Raising an Error by Index

You can raise an error by index using `validator.raise_error_by_index`. Here's an example:

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

    CHashObject *test = newCHashArray(
            newCHashString("aaaaaa")
    );
    int custom_code = 500;
    validator.raise_error_by_index(
            test,
            0,
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1", hash.newString("aaaa")));

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

## Creating Custom Errors

You can create custom errors using `validator.generate_custom_error_cleaning_args`. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

CHash *create() {

    return newCHashArray(

            newCHashObject(
                    "name", hash.newString("aaaaaaaaaaaa"),
                    "age", hash.newNumber(26),
                    "height", hash.newNumber(1.69),
                    "married", hash.newBool(true)
            ),
            newCHashObject(
                    "invalid key", hash.newString("aaaaaaa"),
                    "name", hash.newString("second name"),
                    "age", hash.newNumber(42),
                    "height", hash.newNumber(2.5),
                    "married", hash.newBool(true)
            ),

            newCHashObject(
                    "name", hash.newString("third name"),
                    "age", hash.newNumber(55),
                    "height", hash.newNumber(2.4),
                    "married", hash.newBool(false)
            )
    );
}

void validate(CHash *all_persons) {
    validator.ensure_Array(all_persons);
    CHash_for_in(person, all_persons, {
            validator.ensure_only_keys_cleaning_args(person, newCHashStringArray(
                    "name", "age", "height", "married"
            ));

            validator.ensure_String_by_key(person, "name");
            validator.ensure_min_size_by_key(person, "name", 2);
            validator.ensure_max_size_by_key(person, "name", 30);
            validator.ensure_min_value_by_key(person, "age", 0);
            validator.ensure_max_value_by_key(person, "age", 120);
            validator.ensure_min_value_by_key(person, "height", 0.5);
            validator.ensure_max_value_by_key(person, "height", 2.5);
            validator.ensure_Bool_by_key(person, "married");
    })
}

CHash *create_custom_errors() {
    return newCHashArray(
            newCHashObject(
                    CHASH_CODE, newCHashNumber(CHASH_WRONG_TYPE),
                    CHASH_MESSAGE, newCHashString("my custom type error at #path# with #type# and #expected_type#")
            ),
            newCHashObject(
                    CHASH_CODE, newCHashNumber(CHASH_INVALID_KEY),
                    CHASH_MESSAGE, newCHashString("my custom type error at #path# with #key# and #expected_keys#")
            )
    );
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;
    validator = hash.validator;

    CHashArray *all_persons = create();
    validate(all_persons);
    CHash_catch(all_persons) {

        validator.generate_custom_error_cleaning_args(all_persons, create_custom_errors());
        char *message = hash.get_error_message(all_persons);
        printf("%s\n", message);
    }

    CHash_protected(all_persons) {
        CHash_print(all_persons);
    }

    hash.free(all_persons);
}
```