# Implicit Validation - Missing Element Example

This example demonstrates how CHash handles missing elements in an object during implicit validation.

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
                "height",hash.newNumber(18.4)
        )
    );
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

In this example, we create an array of objects where one object is missing the 'married' attribute. When iterating over the array, CHash's implicit validation will detect this missing element and raise an error. The error message will be printed if any errors are detected after the iteration.

This example shows how CHash ensures data integrity by automatically detecting and reporting missing elements during operations.