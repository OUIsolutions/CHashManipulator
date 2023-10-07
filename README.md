# CHashManipulator

CHash is a library for dealing with complex data types, such as key-value structures and arrays, is designed to be simple to use and provides functionality for transformation and validation.
## An Quick guide
<!--codeof:exemples/Implict_validation/correct.c-->
~~~c

#include "CHashManipulator.h"

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

    CHashArray *element = create();
    
    long size = hash.get_size(element);
    for(int i = 0; i <size; i++){
        CHashObject *current_person = array.getObject(element,i);
        
        char * name = obj.getString(current_person,"name");
        long age = obj.getNumber(current_person,"age");
        double height = obj.getNumber(current_person,"height");
        bool married = obj.getBool(current_person,"married");

        if(!hash.errors(element)){
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
~~~

## Arrays

### Creating an Array
<!--codeof:exemples/Array/creating_array.c-->


### Appending Value inside an Array 
<!--codeof:exemples/Array/array_append.c-->

### Deleting Value from Array 
<!--codeof:exemples/Array/array_delete.c-->

### Seting Value inside an Array
<!--codeof:exemples/Array/array_set.c-->


## Objects

### Creating an Object
<!--codeof:exemples/Object/creating_object.c-->

### Iterating over an Object
<!--codeof:exemples/Object/object_iteration.c-->

### Deleting an Key
<!--codeof:exemples/Object/deleting_key.c-->

