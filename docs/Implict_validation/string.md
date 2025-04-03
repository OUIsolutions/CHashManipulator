# Implicit Validation - String Example

This example demonstrates how CHash handles strings during implicit validation.

## Code
```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHash *create (){
    return  hash.newString("aaaaaaaaa");
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *element = create();
    
    long size = hash.get_size(element);
    for(int i = 0; i <size; i++){
        CHashObject *current_person = array.getObject(element,i);
        
        char * name = obj.getString(current_person,"name");
        long age = obj.getNumber(current_person,"age");
        double height = obj.getNumber(current_person,"height");
        bool married = obj.getBool(current_person,"married");

        CHash_protected(element){
            // its safe to print anything here 
            printf("-----------------------------------------------\n");
            printf("\tname:%s\n",name);
            printf("\tage:%ld\n",age);
            printf("\theight:%lf\n",height);
            printf("\tmarried:%s\n",married  ? "true": "false");
        }
        
    }

    if(hash.errors(element)){
        char *menssage = hash.get_error_menssage(element);
        printf("%s\n",menssage);
    }


    hash.free(element);
}
```

## Explanation

In this example, the `create()` function returns a string instead of an array or object. When attempting to iterate over this string as if it were an array, CHash's implicit validation will detect this mismatch and raise an error. The error message will be printed if any errors are detected after the iteration.

This example illustrates how CHash ensures data integrity by automatically detecting and reporting incorrect types during operations.