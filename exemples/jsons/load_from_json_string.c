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