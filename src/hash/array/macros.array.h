

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
