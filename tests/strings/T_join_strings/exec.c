
#include "../../../LibName.h"

int main(){
    char *joined = join_strings("test","test2");
    printf("%s",joined);
    free(joined);
}