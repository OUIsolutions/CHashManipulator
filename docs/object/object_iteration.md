## Object Iteration

Iterating over an object is a common operation in programming. Our library provides a way to iterate over an object using a loop. Let's explore how to do this with a detailed example.

### Example: Iterating Over an Object

Here's a step-by-step guide on how to iterate over an object:

1. **Include the Necessary Header**: Start by including the `CHashManipulatorOne.c` header file which contains the necessary definitions for our library.

   ```c
   #include "CHashManipulatorOne.c"
   ```

2. **Initialize the Namespace and Modules**: We need to initialize the `CHashNamespace` and its modules like `object`, `array`, and `validator`.

   ```c
   CHashNamespace hash = newCHashNamespace();
   CHashObjectModule obj = hash.object;
   CHashArrayModule array = hash.array;
   CHashValidatorModule validator = hash.validator;
   ```

3. **Create an Object**: Use the `newCHashObject` function to create an object with key-value pairs. In this example, we're creating an object with keys for name, age, height, and marital status.

   ```c
   CHashObject *create() {
       return newCHashObject(
           "name", hash.newString("aaa"),
           "age", hash.newNumber(26),
           "height", hash.newNumber(20),
           "married", hash.newBool(true)
       );
   }
   ```

4. **Ensure the Object is Valid**: Use `validator.ensure_Object` to ensure the object is valid before iterating over it.

   ```c
   int main() {
       CHashArray *profile = create();
       validator.ensure_Object(profile);
   ```

5. **Check for Errors**: Use `CHash_catch` to handle any errors that might occur during the validation.

   ```c
       CHash_catch(profile) {
           printf("%s\n", hash.get_error_message(profile));
           hash.free(profile);
           return 1;
       }
   ```

6. **Get the Object Size**: Use `hash.get_size` to get the size of the object.

   ```c
       long size = hash.get_size(profile);
   ```

7. **Iterate Over the Object**: Use a `for` loop to iterate over the object. Inside the loop, use `obj.get_key_by_index` to get the key at each index, and then use `obj.get_type` to determine the type of each value. Use the appropriate getter function to retrieve the value.

   ```c
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
   ```

8. **Free the Memory**: Don't forget to free the memory allocated for the object to prevent memory leaks.

   ```c
       hash.free(profile);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to iterate over an object:

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

By following these steps, you can easily iterate over an object using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.