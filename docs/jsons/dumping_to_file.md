# Dumping JSON to File

To save a CHash object to a JSON file, use the `dump_to_json_file` function. Here's an example:

```c
#include "CHashManipulatorOne.c"
CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = newCHashObject(
        "name",hash.newString("Mateus"),
        "age",hash.newNumber(26)
    );
    hash.dump_to_json_file(element,"out.json");

    hash.free(element);
}
```

This code creates a CHash object and saves it to `side_effect/out.json`.