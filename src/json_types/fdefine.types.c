//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end



short CHash_get_type(CHash *self){
    if(Chash_errors(self)){
        return CHASH_NOT_EXIST;
    }
    return self->private_type;
}

const char  *private_Chash_convert_type(long type){

    if(type == CHASH_NULL){
        return "null";
    }
    if(type == CHASH_STRING){
        return "string";
    }
    if(type == CHASH_ARRAY){
        return "array";
    }

    if(type == CHASH_OBJECT){
        return "object";
    }

    if(type == CHASH_NUMBER){
        return "number";
    }

    if(type == CHASH_BOOL){
        return "bool";
    }

    return "not exist";
}
