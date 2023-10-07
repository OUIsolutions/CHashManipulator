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
~~~c

#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *element = create();
    char *name  = array.getString(element,0);
    long age = array.getNumber(element,1);
    double height = array.getNumber(element,2);

    if(!hash.errors(element)){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
    }

    else{
        char *menssage = hash.get_error_menssage(element);
        printf("%s",menssage);
    }
    hash.free(element);

}
~~~

### Appending Values to an Array
<!--codeof:exemples/Array/array_append.c-->
~~~c

#include "CHashManipulator.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20),
            hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    CHashArray_append(
        element,
       hash.newString("b"),
       hash.newString("c")
    );

    if(!hash.errors(element)){
        hash.print(element);

    }
    else{
        printf("%s",hash.get_error_menssage(element));

    }

    hash.free(element);

}
~~~
### Deleting Element inside an Array
<!--codeof:exemples/Array/array_delete.c-->
~~~c

#include "CHashManipulator.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20),
            hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    //will remove the last element
    array.remove(element,-1);


    if(!hash.errors(element)){
        hash.print(element);

    }
    else{
        printf("%s",hash.get_error_menssage(element));

    }

    hash.free(element);

}
~~~
### Setting Values inside an Array
<!--codeof:exemples/Array/array_set.c-->
~~~c

#include "CHashManipulator.h"



CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashArray(
            hash.newString("aaa"),
            hash.newNumber(26),
            hash.newNumber(20),
            hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *element = create();

    //will set  the last element
    array.set(element,-1, newCHashString("b"));


    if(!hash.errors(element)){
        hash.print(element);

    }
    else{
        printf("%s",hash.get_error_menssage(element));

    }

    hash.free(element);

}
~~~

### Creating an Object
<!--codeof:exemples/Object/creating_object.c-->
~~~c

#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;

CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newNumber(26),
            "height",hash.newNumber(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *profile = create();

    char *name = obj.getString(profile,"name");
    long age = obj.getNumber(profile,"age");
    double height = obj.getNumber(profile,"height");
    bool maried = obj.getBool(profile,"maried");

    if(!hash.errors(profile)){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
        printf("maried %s\n", maried ? "true":"false");
    }

    else{
        char *menssage = hash.get_error_menssage(profile);
        printf("%s",menssage);
    }
    hash.free(profile);

}
~~~
### Generating an Object Iteration
<!--codeof:exemples/Object/object_iteration.c-->
~~~c

#include "CHashManipulator.h"




CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule validator;


CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newNumber(26),
            "height",hash.newNumber(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    CHashArray *profile = create();
    validator.ensure_Object(profile);
    if(hash.errors(profile)){
        printf("%s\n",hash.get_error_menssage(profile));
        hash.free(profile);
        return 1;
    }

    long size = hash.get_size(profile);
    for(int i = 0; i < size; i++){

        char *key = obj.get_key_by_index(profile,i);
        printf("%s: ",key);
        int type = obj.get_type(profile, key);

        if(type == CHASH_STRING){
            printf("%s",obj.getString(profile,key));
        }

        if(type == CHASH_NUMBER){
            printf("%lf",obj.getNumber(profile,key));
        }

        if(type == CHASH_BOOL){
            printf("%s",obj.getBool(profile,key)  ? "true":"false");
        }

        printf("\n");

    }
    hash.free(profile);

}
~~~
### Deleting an value of an object by Key
<!--codeof:exemples/Object/deleting_key.c-->
~~~c

#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;



CHashObject *create (){
    return newCHashObject(
            "name", hash.newString("aaa"),
            "age", hash.newNumber(26),
            "height",hash.newNumber(20),
            "maried",hash.newBool(true)
    );
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *profile = create();

    obj.remove(profile,"maried");

    if(!hash.errors(profile)){
        hash.print(profile);
    }
    else{
        printf("%s\n",hash.get_error_menssage(profile));

    }


    hash.free(profile);

}
~~~

## Validation 
With The Validation system you can test parts of the data struct to ensure everything
its correct

<!--codeof:exemples/ExplictValidation/Correct.c-->
~~~c
#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHash *create (){

    return newCHashArray(

            newCHashObject(
                    "name",hash.newString("Mateus"),
                    "age", hash.newNumber(26),
                    "height",hash.newNumber(1.69),
                    "married",hash.newBool(true)
            ),
            newCHashObject(
                    "name",hash.newString("second name"),
                    "age", hash.newNumber(42),
                    "height",hash.newNumber(2.5),
                    "married",hash.newBool(true)
            ),

            newCHashObject(
                    "name",hash.newString("third name"),
                    "age", hash.newNumber(55),
                    "height",hash.newNumber(2.4),
                    "married",hash.newBool(false)
            )
    );

}
void validate_person(CHash *person){
    validator.ensure_only_keys_cleaning_args(person, newCHashStringArray(
            "name","age","height","married"
    ));
    validator.ensure_String_by_key(person,"name");
    validator.ensure_min_size_by_key(person,"name",2);
    validator.ensure_max_size_by_key(person,"name",30);
    validator.ensure_min_value_by_key(person, "age", 0);
    validator.ensure_max_value_by_key(person, "age", 120);
    validator.ensure_min_value_by_key(person, "height", 0.5);
    validator.ensure_max_value_by_key(person, "height", 2.5);
    validator.ensure_Bool_by_key(person,"married");
}

void validate(CHash *element){
    validator.ensure_Array(element);
    array.foreach(element, validate_person);
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *element = create();
    validate(element);
    if(hash.errors(element)){
        char *menssage = hash.get_error_menssage(element);
        printf("%s\n",menssage);
        hash.free(element);
        return 0;
    }

    long size = hash.get_size(element);
    for(int i = 0; i <size; i++){
        CHashObject *current_person = array.getObject(element,i);
        printf("-----------------------------------------------\n");
        printf("\tname:%s\n", obj.getString(current_person,"name"));
        printf("\tage:%ld\n",(long)obj.getNumber(current_person,"age"));
        printf("\tage:%lf\n",obj.getNumber(current_person, "height"));
        printf("\tmarried:%s\n",obj.getBool(current_person,"married")  ? "true": "false");
    }

    hash.free(element);

}
~~~
You also can use json loading and dumping functions to parse values from/to jsons 

### Loading from Json File
<!--codeof:exemples/jsons/load_from_json_file.c-->
~~~c
#include "CHashManipulator.h"

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
~~~
<!--codeof:exemples/jsons/load_from_json_string.c-->
~~~c
#include "CHashManipulator.h"

CHashNamespace hash;

int main(){
    hash = newCHashNamespace();

    CHash *element = hash.load_from_json_strimg("{\"name\":\"Mateus\",\"age\":26}");
    if(hash.errors(element)){
        printf("%s",hash.get_error_menssage(element));
    }
    else{
        hash.print(element);

    }

    hash.free(element);

}
~~~
<!--codeof:exemples/jsons/dumping_to_json_file.c-->
~~~c
#include "CHashManipulator.h"

CHashNamespace hash;


int main(){
    hash = newCHashNamespace();

    CHash *element = newCHashObject(
        "name",hash.newString("Mateus"),
        "age",hash.newNumber(26)
    );
    hash.dump_to_json_file(element,"side_effect/out.json");
    

    hash.free(element);

}
~~~
<!--codeof:exemples/jsons/dumping_to_json_string.c-->
~~~c
#include "CHashManipulator.h"

CHashNamespace hash;


int main(){
    hash = newCHashNamespace();

    CHash *element = newCHashObject(
        "name",hash.newString("Mateus"),
        "age",hash.newNumber(26)
    );
    char *result = hash.dump_to_json_string(element);
    printf("%s",result);
    free(result);

    hash.free(element);

}
~~~