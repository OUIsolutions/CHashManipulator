#include "src/one.h"

#define CHash_for_in(var,array, scope){                                                                             \
        long private_size = CHash_get_size(array);                                \   
        for(int private_iter = 0; private_iter < private_size; private_iter++){   \
                var = CHashArray_get(array,private_iter);                         \
                scope                                                              \
        }                                                                          \
    }

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;
CTextNamespace ctext;
CHash *create (){

    return newCHashArray(

            newCHashObject(
                    "name",hash.newString("Mateus"),
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
                    "name",hash.newString("third name"),
                    "age", hash.newNumber(55),
                    "height",hash.newNumber(2.4),
                    "married",hash.newBool(false),
                    "phones",newCHashStringArray(
                        "+55(11) 12345 1234 ",
                        "+55(11) 12345 5555 "
                    )
            )
    );

}

void remove_invalid(CHash *invalid,va_list args){
    CTextStack *phone = (CTextStack*)va_arg(args,void*);
    ctext.stack.self_replace(phone,hash.toString(invalid),"");
}

void validate_and_format_phone(CHash *phone){
    CTextStack *phone_stack = hash.toStack(phone);
    CHashStringArray  *invalids = newCHashStringArray("+","(",")"," ");
    array.foreach_with_args(invalids,remove_invalid,phone_stack);
    hash.free(invalids);
    validator.ensure_size(phone,13);

    
}

void validate_and_format(CHash *persons_array){
    validator.ensure_Array(persons_array);
    CHash_for_in(CHash *person, persons_array,{
           validator.ensure_only_keys_cleaning_args(person, newCHashStringArray(
                  "name","age","height","married","phones"
           ));
           validator.ensure_String_by_key(person,"name");
            validator.ensure_min_size_by_key(person,"name",2);
            validator.ensure_max_size_by_key(person,"name",30);
            validator.ensure_min_value_by_key(person, "age", 0);
            validator.ensure_max_value_by_key(person, "age", 120);
            validator.ensure_min_value_by_key(person, "height", 0.5);
            validator.ensure_max_value_by_key(person, "height", 2.5);
            validator.ensure_Bool_by_key(person,"married");
            CHashStringArray * phones = obj.getArray(person,"phones");
            validator.ensure_all_String(phones);  
    });
}

int main(){
    /*
    int r = 0;
    t1:
        printf("%ld\n",r);
        if(r < 20){
            r+=1;
            goto t1;
        }
    */
    

    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;
    validator = hash.validator;
    ctext = newCTextNamespace();

    CHashArray *element = create();
    validate_and_format(element);

    CHash_protected(element){
        char * formated = hash.dump_to_json_string(element);
        printf("%s",formated);
        free(formated);
    }

    CHash_catch(element){
        char *menssage = hash.get_error_menssage(element);
        printf("%s\n",menssage);
    }

    hash.free(element);

}