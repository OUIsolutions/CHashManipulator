# Foreach Iteration

To iterate over an array using 'foreach', use the `foreach` function. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;

void print_element(CHash *element) {
    int type = hash.get_type(element);
    if (type == CHASH_NUMBER) {
        printf("%lf\n", hash.toNumber(element));
    }
    if (type == CHASH_STRING) {
        printf("%s\n", hash.toString(element));
    }
}

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;

    CHashArray *element = newCHashArray(
        newCHashNumber(10),
        newCHashString("aaaaaaaaaa")
    );
    array.foreach(element, print_element);

    hash.free(element);
}
```

This code iterates over an array, printing each element based on its type.