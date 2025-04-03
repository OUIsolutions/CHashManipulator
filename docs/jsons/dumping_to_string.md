# Dumping JSON to String

To convert a CHash object to a JSON string, use the `dump_to_json_string` function. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = newCHashObject(
        "name",hash.newString("Mateus"),
        "age",hash.newNumber(26)
    );
    char *result = hash.dump_to_json_string(element);
    printf("%s",result);
    free(result);

    hash.free(element);
}
```

This code creates a CHash object, converts it to a JSON string, prints it, and then frees the memory.