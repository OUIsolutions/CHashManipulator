## Appending Values to an Array

Appending values to an array is a fundamental operation in programming. In our library, you can use the `CHashArray_append` function to add new elements to the end of an array. Let's dive into how this works with a detailed example.

### Example: Appending Strings to an Array

Here's a step-by-step guide on how to append values to an array:

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

4. **Append New Elements**: Use `CHashArray_append` to add new elements to the array. In this example, we're appending two strings.

   ```c
   int main() {
       CHashArray *element = create();

       CHashArray_append(
           element,
           hash.newString("b"),
           hash.newString("c")
       );
   ```

5. **Check for Errors**: After appending, check if there were any errors during the operation.

   ```c
       if (!hash.errors(element)) {
           hash.print(element);
       } else {
           printf("%s", hash.get_error_message(element));
       }
   ```

6. **Free the Memory**: Don't forget to free the memory allocated for the array to prevent memory leaks.

   ```c
       hash.free(element);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to append values to an array:

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

By following these steps, you can easily append values to an array using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.