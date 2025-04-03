# Handling JSON Errors

When dealing with JSON, it's important to handle errors properly. Here are examples of how to manage errors when loading JSON:

**Non-existent File:**

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_file("side_effect/not_exist.json");
    if(hash.errors(element)){
        printf("%s",hash.get_error_menssage(element));
    }
    else{
        hash.print(element);
    }

    hash.free(element);
}
```

**Invalid JSON:**

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_file("side_effect/invalid.json");
    if(hash.errors(element)){
        printf("%s",hash.get_error_menssage(element));
    }
    else{
        hash.print(element);
    }

    hash.free(element);
}
```

These examples show how to check for errors and print appropriate messages when loading JSON files.