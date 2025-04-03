# Loading JSON from File

To load a JSON file into a CHash object, use the `load_from_json_file` function. Here are examples:

**Example 1:**

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_file("side_effect/test.json");
    if(hash.errors(element)){
        printf("%s",hash.get_error_menssage(element));
    }
    else{
        hash.print(element);
    }

    hash.free(element);
}
```

**Example 2:**

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_file("side_effect/test2.json");
    if(hash.errors(element)){
        printf("%s",hash.get_error_menssage(element));
    }
    else{
        hash.print(element);
    }

    hash.free(element);
}
```

These examples load JSON from files and print the result or an error message if the file is not found or invalid.