# For In Iteration

To iterate over an array or object using 'for_in', use the `CHash_for_in` macro. Here's an example:

```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule obj;
CHashArrayModule array;
CHashValidatorModule validator;
CTextNamespace ctext;

int main() {
    hash = newCHashNamespace();
    obj = hash.object;
    array = hash.array;

    CHash *elements = newCHashArray(
        hash.newNumber(23),
        hash.newString("aaaaaaa")
    );

    CHash_for_in(e, elements, {
        short type = hash.get_type(e);
        if (type == CHASH_NUMBER) {
            double value = hash.toNumber(e);
            printf("%lf\n", value);
        }
        if (type == CHASH_STRING) {
            char *value = hash.toString(e);
            printf("%s\n", value);
        }
    })

    hash.free(elements);
}
```

This code iterates over an array, printing each element based on its type.