
#include "../../../CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

CHash *create (){
    return  
    newCHashObject(
                "name",hash.newString("mateus"),
                "age", hash.newLong(26),
                "height",hash.newDouble(1.69),
                "married",hash.newBool(true)
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
        long age = obj.getLong(current_person,"age");
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

    if(hash.errors(element)){
        char *menssage = hash.get_error_menssage(element);
        printf("%s\n",menssage);
    }


    hash.free(element);

}