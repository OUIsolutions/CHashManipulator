#include "src/one.h"


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
void validate(CHash *element){
    validator.ensure_Array(element);
    long size = hash.get_size(element);
    for(long i = 0; i < size; i++){
        CHashObject *current = array.getObject(element,i);
        validator.ensure_String_by_key(current,"name");
        validator.ensure_min_by_key(current,"age",0);
        validator.ensure_max_by_key(current,"age",120);
        validator.ensure_min_by_key(current,"height",0.5);
        validator.ensure_max_by_key(current,"height",2.5);
        validator.ensure_Bool_by_key(current,"married");
    }
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