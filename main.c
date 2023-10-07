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
                    "phones",newCHashStringArray(
                        "+55(11) 12345 1234 ",
                        "+55(11) 12345 5555 "
                    )
            ),
            newCHashObject(
                    "name",hash.newString("second name"),
                    "age", hash.newNumber(42),
                    "height",hash.newNumber(2.5),
                    "married",hash.newBool(true),
                    "phones",newCHashStringArray(
                        "+55(11) 12345 1234 ",
                        "+55(11) 12345 5555 "
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

void validate_and_format_phone(CHash *phone){
    CTextStack *t = hash.toStack(phone);
    ctext.stack.self_replace(t,"+","");
    ctext.stack.self_replace(t,"(","");
    ctext.stack.self_replace(t,")","");
    ctext.stack.self_replace(t," ","");

}
void validate_and_format_person(CHash *person){
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
    CHashStringArray * phones = obj.getArray(perror,"phones");
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
    validate(element);
    if(hash.errors(element)){
        char *menssage = hash.get_error_menssage(element);
        printf("%s\n",menssage);
    }
    else{
        char * formated = hash.dump_to_json_string(element);
        printf("%s",formated);
    }

    hash.free(element);

}