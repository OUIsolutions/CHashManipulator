## Dealing with Optional Values

Checking if a key exists in an object is a common operation in programming. Our library provides the `obj.exist` function to check for the existence of a key in an object. Let's explore how to use this function with a detailed example.

### Example: Checking if a Key Exists in an Object

Here's a step-by-step guide on how to check for the existence of a key in an object:

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

3. **Create an Object**: Use the `newCHashObject` function to create an object with an initial key-value pair. In this example, we're creating an object with a key 'name' and a string value.

   ```c
   int main() {
       CHashArray *person = newCHashObject(
           "name", hash.newString("aaaaaaaaa")
       );
   ```

4. **Check if the Key Exists**: Use `obj.exist` to check if the key 'name' exists in the object.

   ```c
       if (obj.exist(person, "name")) {
   ```

5. **Access the Value**: If the key exists, use the appropriate getter function to access its value. In this example, we're accessing the value of the key 'name' as a string.

   ```c
           char *name = obj.getString(person, "name");
           printf("%s\n", name);
       }
   ```

6. **Free the Memory**: Don't forget to free the memory allocated for the object to prevent memory leaks.

   ```c
       hash.free(person);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to check for the existence of a key in an object:

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

    CHashArray *person = newCHashObject(
        "name", hash.newString("aaaaaaaaa")
    );

    if (obj.exist(person, "name")) {
        char *name = obj.getString(person, "name");
        printf("%s\n", name);
    }

    hash.free(person);
}
```

By following these steps, you can easily check for the existence of a key in an object using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.