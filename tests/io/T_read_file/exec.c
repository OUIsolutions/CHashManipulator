
#include "../../../LibName.h"

int main(){
    char *content = read_file("side_effect/a.txt");
    printf("%s",content);
    free(content);
    
}