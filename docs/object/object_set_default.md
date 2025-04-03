## Setting Default Values

Setting default values for keys in an object is a useful feature in programming. Our library provides the `obj.set_default` function to set default values for keys that might not exist in an object. Let's explore how to use this function with a detailed example.

### Example: Setting a Default Value for a Key

Here's a step-by-step guide on how to set default values in an object:

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

3. **Create an Object**: Use the `newCHashObject` function to create an object with an initial key-value pair. In this example, we're creating an object with a key 'nothing' and a string value.

   ```c
   int main() {
       CHashArray *person = newCHashObject(
           "nothing", hash.newString("aaaaaaaaa")
       );
   ```

4. **Set a Default Value**: Use `obj.set_default` to set a default value for a key that might not exist in the object. In this example, we're setting a default value for the key 'name'.

   ```c
       obj.set_default(person, "name", hash.newString("default string"));
   ```

5. **Access the Value**: Use the appropriate getter function to access the value of the key. In this example, we're accessing the value of the key 'name' as a string.

   ```c
       char *name = obj.getString(person, "name");
   ```

6. **Print the Value**: Use `printf` to print the value of the key.

   ```c
       printf("%s\n", name);
   ```

7. **Free the Memory**: Don't forget to free the memory allocated for the object to prevent memory leaks.

   ```c
       hash.free(person);
   }
   ```

### Full Code Example

Here's the complete code example that demonstrates how to set default values in an object:

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
        "nothing", hash.newString("aaaaaaaaa")
    );

    obj.set_default(person, "name", hash.newString("default string"));
    char *name = obj.getString(person, "name");
    printf("%s\n", name);

    hash.free(person);
}
```

By following these steps, you can easily set default values in an object using our library. Remember to always check for errors and manage memory properly to ensure your program runs smoothly.