# Implicit Validation - Correct Example

This example demonstrates correct usage of implicit validation in CHash.

## Code
```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHash *create (){

    return newCHashArray(
        
        newCHashObject(
                "name",hash.newString("mateus"),
                "age", hash.newNumber(26),
                "height",hash.newNumber(1.69),
                "married",hash.newBool(true)
        ),

        newCHashObject(
                "name",hash.newString("second name"),
                "age", hash.newNumber(42),
                "height",hash.newNumber(18.4),
                "married",hash.newBool(true)
        ),

        newCHashObject(
                "name",hash.newString("third name"),
                "age", hash.newNumber(55),
                "height",hash.newNumber(14.4),
                "married",hash.newBool(false)
        )
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *all_persons = create();

    CHash_for_in(person,all_persons,{

        char * name = obj.getString(person,"name");
        long age = obj.getNumber(person,"age");
        double height = obj.getNumber(person,"height");
        bool married = obj.getBool(person,"married");

        CHash_protected(person){
            // its safe to print anything here
            printf("-----------------------------------------------\n");
            printf("\tname:%s\n",name);
            printf("\tage:%ld\n",age);
            printf("\theight:%lf\n",height);
            printf("\tmarried:%s\n",married  ? "true": "false");
        }
    });

    CHash_catch(all_persons){
        char *menssage = hash.get_error_menssage(all_persons);
        printf("%s\n",menssage);
    }
    hash.free(all_persons);
}
```

## Explanation

In this example, we create an array of objects, each representing a person with attributes like name, age, height, and marital status. The `create()` function returns this array, which is then iterated over using `CHash_for_in`. Each object's attributes are accessed and printed safely within a `CHash_protected` block. If any errors occur during this process, they are caught and printed using `CHash_catch`.

This example showcases how implicit validation works in CHash, where the library automatically validates the types of data being accessed or manipulated, ensuring that operations are performed correctly without explicit validation checks.