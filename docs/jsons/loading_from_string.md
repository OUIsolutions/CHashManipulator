# Loading JSON from String

To load a JSON string into a CHash object, use the `load_from_json_string` function. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_strimg("{\"name\":\"Mateus\",\"age\":26}");
    
    CHash_protected(element){
        hash.print(element);
    }

    CHash_catch(element){
        printf("%s",hash.get_error_menssage(element));
    }

    hash.free(element);
}
```

This code loads a JSON string into a CHash object, prints it if successful, or prints an error message if there's an issue.