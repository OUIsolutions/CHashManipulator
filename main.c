#include "src/one.h"



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

}
void validate_and_format_person(CHash *person){
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
    array.foreach(phones,validate_and_format_phone);
}

void validate_and_format(CHash *element){
    validator.ensure_Array(element);
    array.foreach(element, validate_and_format_person);
}

int main(){
    

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