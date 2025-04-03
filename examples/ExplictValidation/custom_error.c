
#include "CHashManipulatorOne.c"

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