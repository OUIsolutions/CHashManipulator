## Creating an Array

Creating an array is one of the most basic operations in programming. In our library, you can use the `newCHashArray` function to create an array with initial elements. Let's dive into how this works with a detailed example.

### Example: Creating an Array with Initial Elements

Here's a step-by-step guide on how to create an array:

1. **Include the Necessary Header**: Start by including the `CHashManipulatorOne.c` header file which contains the necessary definitions for our library.

   ```c
   #include "CHashManipulatorOne.c"
   ```

2. **Initialize the Namespace and Modules**: We need to initialize the `CHashNamespace` and its modules like `object` and `array`.

   ```c
   CHashNamespace hash = newCHashNamespace();
   CHashObjectModule obj = hash.object;
   CHashArrayModule array = hash.array;
   ```

3. **Create an Array**: Use the `newCHashArray` function to create an array with initial elements. In this example, we're creating an array with a string, a number, and another number.

   ```c
   CHashObject *create() {
       return newCHashArray(
           hash.newString("aaa"),
           hash.newNumber(26),
           hash.newNumber(20)
       );
   }
   ```

4. **Access Array Elements**: Use the appropriate getter functions to access the elements of the array. In this example, we're accessing the first element as a string, the second as a number, and the third as a number.

   ```c
   int main() {
       CHashArray *element = create();

       char *name = array.getString(element, 0);
       long age = array.getNumber(element, 1);
       double height = array.getNumber(element, 2);
   ```

5. **Print the Array Elements**: Use `CHash_protected` to safely print the elements of the array.

   ```c
       CHash_protected(element) {
           printf("name: %s\n", name);
           printf("age %ld\n", age);
           printf("height %lf\n", height);
       }
   ```

6. **Check for Errors**: Use `CHash_catch` to handle any errors that might occur during the operation.

   ```c
       CHash_catch(element) {
           char *message = hash.get_error_message(element);
           printf("%s", message);
       }
   ```

7. **Free the Memory**: Don't forget to free the memory allocated for the array to prevent memory leaks.

   ```c
       hash.free(element);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to create an array:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;

CHashObject *create() {
    return newCHashArray(
        hash.newString("aaa"),
        hash.newNumber(26),
        hash.newNumber(20)
    );
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;

    CHashArray *element = create();
    char *name = array.getString(element, 0);
    long age = array.getNumber(element, 1);
    double height = array.getNumber(element, 2);

    CHash_protected(element) {
        printf("name: %s\n", name);
        printf("age %ld\n", age);
        printf("height %lf\n", height);
    }

    CHash_catch(element) {
        char *message = hash.get_error_message(element);
        printf("%s", message);
    }
    hash.free(element);
}
```

By following these steps, you can easily create an array using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.