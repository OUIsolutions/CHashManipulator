# CHashManipulator

CHash is a library for dealing with complex data types, such as key-value structures and arrays, is designed to be simple to use and provides functionality for transformation and validation.

# Warning
This library is still in Beta
Be aware that memory failures and bugs may occur

## Installation
Like all OUI libs, CHashManipulator is single file, and just add the file ""CHashManipulator.h" 
to your directory and compile it with gcc or clang.

If you want, you can also include the entire "src" folder in your directory and include  it from "src/one.h"

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

    CHash_protected(element){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
    }

    CHash_catch(element){
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


    CHash_protected(element){
        hash.print(element);

    }

    CHash_catch(element){
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


    CHash_protected(element){
        hash.print(element);

    }

    CHash_catch(element){
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

    CHash_protected(profile){
        printf("name: %s\n",name);
        printf("age %ld\n",age);
        printf("heigh %lf\n",height);
        printf("maried %s\n", maried ? "true":"false");
    }

    CHash_catch(profile){
        char *menssage = hash.get_error_menssage(profile);
        printf("%s",menssage);
    }
    hash.free(profile);

}
~~~
### Object Iteration
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
    CHash_catch(profile){
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

### Seting Values of an Object
<!--codeof:exemples/Object/seting_values.c-->
~~~c

#include "CHashManipulator.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;


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

    CHashObject_set_many(profile,
        "age", hash.newNumber(18),
        "maried", hash.newBool(false)
    );

    hash.print(profile);

    hash.free(profile);

}
~~~
### Dealing with optional values 
<!--codeof:exemples/Object/verify_if_exist.c-->
~~~c
#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *person = newCHashObject(
        "name",hash.newString("aaaaaaaaa")
    );

    if(obj.exist(person,"name")){
        char *name = obj.getString(person,"name");
        printf("%s\n",name);
    }


    hash.free(person);

}
~~~
### Setting Default values 
<!--codeof:exemples/Object/default.c-->
~~~c
#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *person = newCHashObject(
        "nothing",hash.newString("aaaaaaaaa")
    );

    obj.set_default(person,"name",hash.newString("default string"));
    char *name = obj.getString(person,"name");
    printf("%s\n",name);
    


    hash.free(person);

}
~~~
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

    CHash_protected(profile){
        hash.print(profile);
    }

    CHash_catch(profile){
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

void validate(CHash *all_persons){
    validator.ensure_Array(all_persons);
    CHash_for_in(person,all_persons,{
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
    })
}

int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *all_persons = create();
    validate(all_persons);
    CHash_catch(all_persons){
        char *menssage = hash.get_error_menssage(all_persons);
        printf("%s\n",menssage);
        hash.free(all_persons);
        return 0;
    }

    CHash_for_in(current_person,all_persons,{
        printf("-----------------------------------------------\n");
        printf("\tname:%s\n", obj.getString(current_person,"name"));
        printf("\tage:%ld\n",(long)obj.getNumber(current_person,"age"));
        printf("\tage:%lf\n",obj.getNumber(current_person, "height"));
        printf("\tmarried:%s\n",obj.getBool(current_person,"married")  ? "true": "false");
    })
    hash.free(all_persons);

}
~~~
### Rasing an Error 
<!--codeof:exemples/ExplictValidation/raising_error.c-->
~~~c

#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashObject *person = newCHashObject(
            "name",hash.newString("aaaaaaaaa")
    );
    CHash *name = obj.get(person,"name");
    int custom_code = 500;
    validator.raise_error(
            name,
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1",hash.newString("aaaa")));

    CHash_catch(person){
        short  code = hash.get_error_code(person);
        char *menssage=  hash.get_error_menssage(person);
        CHash *args = hash.get_error_args(person);

        printf("code: %d\n",code);
        printf("menssage: %s\n",menssage);
        printf("args:\n");
        CHash_print(args);

    }


    hash.free(person);

}
~~~

### Raising an Error by key
<!--codeof:exemples/ExplictValidation/raising_by_key.c-->
~~~c

#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashObject *person = newCHashObject(
            "name",hash.newString("aaaaaaaaa")
    );

    int custom_code = 500;
    validator.raise_error_by_key(
            person,
            "name",
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1",hash.newString("aaaa")));

    CHash_catch(person){
        short  code = hash.get_error_code(person);
        char *menssage=  hash.get_error_menssage(person);
        CHash *args = hash.get_error_args(person);

        printf("code: %d\n",code);
        printf("menssage: %s\n",menssage);
        printf("args:\n");
        CHash_print(args);

    }


    hash.free(person);

}
~~~

### Raising an Error by Index
<!--codeof:exemples/ExplictValidation/raising_by_index.c-->
~~~c

#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;



int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashObject *test = newCHashArray(
            newCHashString("aaaaaa")
            );
    int custom_code = 500;
    validator.raise_error_by_index(
            test,
            0,
            custom_code,
            "my custom error at #path# with #arg1#",
            newCHashObject("arg1",hash.newString("aaaa")));

    CHash_catch(test){
        short  code = hash.get_error_code(test);
        char *menssage=  hash.get_error_menssage(test);
        CHash *args = hash.get_error_args(test);

        printf("code: %d\n",code);
        printf("menssage: %s\n",menssage);
        printf("args:\n");
        CHash_print(args);

    }


    hash.free(test);

}
~~~
### Creating an custom Error
you also can create your all custom errors 
<!--codeof:exemples/ExplictValidation/custom_error.c-->
~~~c

#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHash *create (){

    return newCHashArray(

            newCHashObject(
                    "name",hash.newString("aaaaaaaaaaaa"),
                    "age", hash.newNumber(26),
                    "height",hash.newNumber(1.69),
                    "married",hash.newBool(true)
            ),
            newCHashObject(
                    "invalid key",hash.newString("aaaaaaa"),
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

void validate(CHash *all_persons){
    validator.ensure_Array(all_persons);
    CHash_for_in(person,all_persons,{
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
    })
}
CHash *create_custom_errors(){
    return newCHashArray(
            newCHashObject(
                    CHASH_CODE, newCHashNumber(CHASH_WRONG_TYPE),
                    CHASH_MESSAGE, newCHashString("my custom type error at #path# with #type# and #expected_type#")
            ),
            newCHashObject(
                    CHASH_CODE, newCHashNumber(CHASH_INVALID_KEY),
                    CHASH_MESSAGE, newCHashString("my custom type error at #path# with #key# and #expected_keys#")
            )
    );
}
int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;

    CHashArray *all_persons = create();
    validate(all_persons);
    CHash_catch(all_persons){

        validator.generate_custom_error_cleaning_args(all_persons,create_custom_errors());
        char *menssage = hash.get_error_menssage(all_persons);
        printf("%s\n",menssage);

    }

    CHash_protected(all_persons){
        CHash_print(all_persons);
    }

    hash.free(all_persons);

}
~~~



### Transforming elements 
<!--codeof:exemples/Transformation/transforming_lsit.c-->
~~~c
#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;
CTextStackModule  stack;

CHash *create (){

    return newCHashArray(

            newCHashObject(
                    "name",hash.newString("Mateus       Moutinho Queiroz"),
                    "age", hash.newNumber(26),
                    "height",hash.newNumber(1.69),
                    "married",hash.newBool(true),
                    "phones", newCHashStringArray(
                            "+55(11 12345 1234 ",
                            "+55 11 12345 5555 "
                    )
            ),
            newCHashObject(
                    "name",hash.newString("second name"),
                    "age", hash.newNumber(42),
                    "height",hash.newNumber(2.5),
                    "married",hash.newBool(true),
                    "phones",newCHashStringArray(
                            "+55 11 12345 1234 ",
                            "+55 11 12345 5555 "
                    )
            ),

            newCHashObject(
                    "name",hash.newString("third                name"),
                    "age", hash.newNumber(55),
                    "height",hash.newNumber(2.4),
                    "married",hash.newBool(false),
                    "phones",newCHashStringArray(
                            "+55 11            12345 1234 ",
                            "+55 11  12345 5555 "
                    )
            )
    );

}


void validate_and_format_phone(CHash *phone){
    CTextStack *phone_stack = hash.toStack(phone);
    validator.ensure_only_chars(phone,"+()- 0123456789");

    CHashStringArray  *invalids = newCHashStringArray(
            "+","(",")","-"," "
    );
    CHash_for_in(i,invalids,{
        stack.self_replace(phone_stack,hash.toString(i),"");
    });
    hash.free(invalids);
    CTextStack *formated = newCTextStack_string_empty();
    stack.format(
            formated,
            "%tc+ (%tc) %tc %tc",
            stack.substr(phone_stack,0,2),
            stack.substr(phone_stack,2,4),
            stack.substr(phone_stack,4,9),
            stack.substr(phone_stack,9,-1)
    );
    hash.set_Stack(phone,formated);
}

void validate_and_format(CHash *persons_array){
    validator.ensure_Array(persons_array);
    CHash_for_in(person, persons_array,{
        validator.ensure_only_keys_cleaning_args(person, newCHashStringArray(
                "name","age","height","married","phones"
        ));

        validator.ensure_String_by_key(person,"name");
        validator.ensure_min_size_by_key(person,"name",2);

        CHash_protected(person){
            CTextStack  *name = obj.getStack(person,"name");
            while(stack.index_of(name,"  ") != -1){
                stack.self_replace(name,"  "," ");
            }
            stack.self_captalize(name);
        }
        validator.ensure_max_size_by_key(person,"name",30);
        validator.ensure_Long_by_key(person,"age");
        validator.ensure_min_value_by_key(person, "age", 0);
        validator.ensure_max_value_by_key(person, "age", 120);
        validator.ensure_min_value_by_key(person, "height", 0.5);
        validator.ensure_max_value_by_key(person, "height", 2.5);
        validator.ensure_Bool_by_key(person,"married");
        CHashStringArray * phones = obj.getArray(person,"phones");
        validator.ensure_all_String(phones);
        array.foreach(phones,validate_and_format_phone);
    });
}

int main(){

    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    stack = newCTextStackModule();

    CHashArray *element = create();
    validate_and_format(element);

    CHash_protected(element){
        char * formated = hash.dump_to_json_string(element);
        printf("%s\n",formated);
        free(formated);
    }

    CHash_catch(element){
        char *menssage = hash.get_error_menssage(element);
        printf("%s\n",menssage);
    }

    hash.free(element);

}
~~~



## Jsons 
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

### Loading from Json String

<!--codeof:exemples/jsons/load_from_json_string.c-->
~~~c
#include "CHashManipulator.h"

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
~~~
### Dumping to Json File
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
### Dumping to Json String
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

