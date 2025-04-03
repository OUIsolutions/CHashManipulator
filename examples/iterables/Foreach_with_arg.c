//
// Created by mateusmoutinho on 06/10/23.
//
#include "CHashManipulator.h"

CHashNamespace hash;
CHashObjectModule  obj;
CHashArrayModule  array;
CHashValidatorModule  validator;

void print_adding(CHash *element, va_list args){
    long value_to_add = va_arg(args,long);
    int  type = hash.get_type(element);
    double value = hash.toNumber(element);
    printf("%lf\n",value+ value_to_add);
    
}
int main(){
    hash = newCHashNamespace();
    obj = hash.object;
    array  = hash.array;

    CHashArray *element = newCHashArray(
            newCHashNumber(10),
            newCHashNumber(34)

    );
    array.foreach_with_args(element,print_adding,10);

    hash.free(element);

}