#include "src/one.h"


CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;
CHashArray *create (){
    return newCHashArray(
        
        newCHashObject(
                "name",hash.newString("mateus"),
                "age", hash.newLong(26),
                "height",hash.newDouble(1.69),
                "married",hash.newBool(true)
        ),
        newCHashObject(
                "name",hash.newString("second name"),
                "age", hash.newLong(42),
                "height",hash.newDouble(18.4),
                "married",hash.newBool(true)
        ),

        newCHashObject(
                "name",hash.newString("third name"),
                "age", hash.newLong(55),
                "height",hash.newDouble(14.4),
                "married",hash.newBool(false)
        )
    );

}

int main(){

    CHashArray *element = create();
    long size = hash.get_size(element);
    for(int i = 0; i <size; i++){
        CHashObject *current_person = array.getObject(element,i);
        
        char * name = obj.getString(current_person,"name");
        long age = obj.getString(current_person,"age");
        double height = obj.getDouble(current_person,"height");
        bool married = obj.getBool(current_person,"married");

        if(!hash.errors(element)){
            // its safe to print anything here 
            printf("-----------------------------------------------\n");
            printf("\tname:%s\n",name);
            printf("\tage:%ld\n",age);
            printf("\tage:%ld\n",age);
            printf("\tmarried:%s\n",married  ? "true": "false");
        }
        
    }
    
    hash.free(element);

}