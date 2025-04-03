## Iterating Over an Array

Iterating over an array is a fundamental operation in programming. Our library provides several ways to iterate over an array, but in this example, we'll focus on using a traditional `for` loop. Let's dive into how this works with a detailed example.

### Example: Iterating Over an Array

Here's a step-by-step guide on how to iterate over an array:

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

3. **Create an Array**: Use the `newCHashArray` function to create an array with initial elements.

   ```c
   CHashObject *create() {
       return newCHashArray(
           hash.newString("aaa"),
           hash.newNumber(26),
           hash.newNumber(20),
           hash.newBool(true)
       );
   }
   ```

4. **Get the Array Size**: Use `hash.get_size` to get the size of the array.

   ```c
   int main() {
       CHashArray *element = create();

       long size = hash.get_size(element);
   ```

5. **Iterate Over the Array**: Use a `for` loop to iterate over the array. Inside the loop, use `array.get_type` to determine the type of each element and then use the appropriate getter function to retrieve its value.

   ```c
       for (int i = 0; i < size; i++) {
           int type = array.get_type(element, i);

           if (type == CHASH_STRING) {
               printf("%s\n", array.getString(element, i));
           }

           if (type == CHASH_NUMBER) {
               printf("%lf\n", array.getNumber(element, i));
           }

           if (type == CHASH_BOOL) {
               printf("%s\n", array.getBool(element, i) ? "true" : "false");
           }
       }
   ```

6. **Check for Errors**: Use `CHash_catch` to handle any errors that might occur during the iteration.

   ```c
       CHash_catch(element) {
           printf("%s", hash.get_error_message(element));
       }
   ```

7. **Free the Memory**: Don't forget to free the memory allocated for the array to prevent memory leaks.

   ```c
       hash.free(element);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to iterate over an array:

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

    long size = hash.get_size(element);

    for (int i = 0; i < size; i++) {
        int type = array.get_type(element, i);

        if (type == CHASH_STRING) {
            printf("%s\n", array.getString(element, i));
        }

        if (type == CHASH_NUMBER) {
            printf("%lf\n", array.getNumber(element, i));
        }

        if (type == CHASH_BOOL) {
            printf("%s\n", array.getBool(element, i) ? "true" : "false");
        }
    }

    CHash_catch(element) {
        printf("%s", hash.get_error_message(element));
    }

    hash.free(element);
}
```

By following these steps, you can easily iterate over an array using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.