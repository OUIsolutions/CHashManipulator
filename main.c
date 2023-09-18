#include "src/one.h"








int main(){

    CHash * t = CHash_load_from_json_file("a.json");
    CHash_print(t);
}