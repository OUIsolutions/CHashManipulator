## Deleting Keys from an Object

Deleting keys from an object is a common operation in programming. Our library provides the `obj.remove` function to remove keys from an object. Let's explore how to use this function with a detailed example.

### Example: Deleting a Key from an Object

Here's a step-by-step guide on how to delete keys from an object:

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

3. **Create an Object**: Use the `newCHashObject` function to create an object with initial key-value pairs. In this example, we're creating an object with keys for name, age, height, and marital status.

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

4. **Delete a Key**: Use `obj.remove` to delete a key from the object. In this example, we're deleting the key 'married'.

   ```c
   int main() {
       CHashArray *profile = create();

       obj.remove(profile, "married");
   ```

5. **Print the Object**: Use `CHash_protected` to safely print the updated object.

   ```c
       CHash_protected(profile) {
           hash.print(profile);
       }
   ```

6. **Check for Errors**: Use `CHash_catch` to handle any errors that might occur during the operation.

   ```c
       CHash_catch(profile) {
           printf("%s\n", hash.get_error_message(profile));
       }
   ```

7. **Free the Memory**: Don't forget to free the memory allocated for the object to prevent memory leaks.

   ```c
       hash.free(profile);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to delete keys from an object:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;

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

    CHashArray *profile = create();

    obj.remove(profile, "married");

    CHash_protected(profile) {
        hash.print(profile);
    }

    CHash_catch(profile) {
        printf("%s\n", hash.get_error_message(profile));
    }

    hash.free(profile);
}
```

By following these steps, you can easily delete keys from an object using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.