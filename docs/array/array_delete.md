## Deleting Elements from an Array

Deleting elements from an array is a common operation in programming. Our library provides the `array.remove` function to remove elements from an array. Let's explore how to use this function with a detailed example.

### Example: Deleting the Last Element from an Array

Here's a step-by-step guide on how to delete elements from an array:

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

4. **Delete an Element**: Use `array.remove` to remove an element from the array. In this example, we're removing the last element using the index `-1`.

   ```c
   int main() {
       CHashArray *element = create();

       // Will remove the last element
       array.remove(element, -1);
   ```

5. **Check for Errors and Print the Array**: Use `CHash_protected` and `CHash_catch` to handle any errors that might occur during the operation.

   ```c
       CHash_protected(element) {
           hash.print(element);
       }

       CHash_catch(element) {
           printf("%s", hash.get_error_message(element));
       }
   ```

6. **Free the Memory**: Don't forget to free the memory allocated for the array to prevent memory leaks.

   ```c
       hash.free(element);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to delete elements from an array:

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

    // Will remove the last element
    array.remove(element, -1);

    CHash_protected(element) {
        hash.print(element);
    }

    CHash_catch(element) {
        printf("%s", hash.get_error_message(element));
    }

    hash.free(element);
}
```

By following these steps, you can easily delete elements from an array using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.