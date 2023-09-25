
#include "src/one.h"


CHashObject *create (){

    return newCHashObject(
            "aaa", newCHashString("aaaaaaaaa"),
            "bbb", newCHashLong(20),
            "ddd", newCHashArray(
                        newCHashLong(10),
                        newCHashString("aaaaaaaaaa")
                    )
    );

}




int main(){
    CHashArray *t = create();
    CHash * name = CHash_get_any_by_key(t, "name");
    obj.ensure_sring_by_key(name);

    
    CHash_free(t);
}