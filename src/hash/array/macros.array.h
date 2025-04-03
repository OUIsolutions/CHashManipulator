//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.dep_declare.h"
//silver_chain_scope_end


#define CHash_for_in(var,array, scope){                                            \
        long private_size = CHash_get_size(array);                                 \
        for(int private_iter = 0; private_iter < private_size; private_iter++){    \
                CHash *var = CHashArray_get(array,private_iter);                   \
                                                                                   \
                if(Chash_errors(var)){                                             \
                    break;                                                         \
                }                                                                  \
                scope                                                              \
        }                                                                          \
    }
