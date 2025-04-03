# Implicit Validation - Null Example

This example demonstrates how CHash handles null values during implicit validation.

## Code
```c
#include "CHashManipulatorOne.c"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHash *create (){
    return NULL;
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

In this example, the `create()` function returns `NULL`, which is an invalid value for an array. When attempting to iterate over this null value, CHash's implicit validation will detect this and raise an error. The error message will be printed if any errors are detected after the iteration.

This example illustrates how CHash ensures data integrity by automatically detecting and reporting null values during operations.