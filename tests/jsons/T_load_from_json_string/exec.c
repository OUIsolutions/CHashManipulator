#include "../../../CHashManipulator.h"

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