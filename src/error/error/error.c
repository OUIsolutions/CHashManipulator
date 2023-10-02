

privateCHashError * privatenewCHashError(CHashObject *args, int error_code, const char *error_menssage){
    privateCHashError  *self = (privateCHashError*) malloc(sizeof (privateCHashError));
    self->args = args;
    self->error_code = error_code;

    self->error_mensage =  newCTextStack_string(error_menssage);

    long args_size = CHash_get_size(self->args);
    for(int i = 0; i < args_size; i++){
        CHash *current = CHashArray_get(self->args,i);
        char *key = CHashObject_get_key_of_element(current);
        char *value = CHash_dump_to_json_string(current);
        CTextStack * formated_key = newCTextStack_string_empty();
        CTextStack_format(formated_key,"#%s#",key);
        CTextStack_self_replace(self->error_mensage,formated_key->rendered_text,value);
        CTextStack_free(formated_key);
        free(value);
    }

    return self;
}




privateCHashError * privateCHashError_get_error(CHash *self){

    CHash  *first =  privateCHash_get_first_object(self);
    if(first->private_error){
        return (privateCHashError*)first->private_error;
    }
    return NULL;
}


bool Chash_errors(CHash *self){
    
    if(!self){
        return true;
    }

    privateCHashError *error  = privateCHashError_get_error(self);
    if(error){
        return true;
    }
    return false;
}


void CHash_raise_error(CHash *self,int error_code,const char *error_menssage, CHash *args){

    if(Chash_errors(self)){return;}

    CHash *formated_args = args;

    if(!args){
        formated_args = newCHashObjectEmpty();
    }
    CHashObject_set_default(formated_args,  "path", CHash_get_path(self));
    CHashObject_set_default(formated_args,"value", CHash_copy(self));
    CHashObject_set_default(formated_args,"type",newCHashString(private_Chash_convert_type(self->private_type)));


    privateCHashError *created = privatenewCHashError(
            formated_args,
            error_code,
            error_menssage
    );
    CHash *first = privateCHash_get_first_object(self);
    first->private_error = (void*)created;

    
}

void privateCHashError_free(privateCHashError *self){
    CTextStack_free(self->error_mensage);
    CHash_free(self->args);
    free(self);
}

char * CHash_get_error_menssage(CHash *self){
    if(!self){

        return (char*)"element its NULL , (impossíble to get error menssage)\n";
    }

    if(!Chash_errors(self)){
        return NULL;
    }

    privateCHashError  *error = privateCHashError_get_error(self);

    return error->error_mensage->rendered_text;
}

int CHash_get_error_code(CHash *self){

    if(!self){
        return CHASH_ELEMENT_IS_NULL;
    }

    if(!Chash_errors(self)){
        return 0;
    }
    privateCHashError  *error = privateCHashError_get_error(self);
    return error->error_code;
}

CHash * CHash_get_error_args(CHash *self){
    if(!Chash_errors(self)){
        return NULL;
    }
    privateCHashError  *error = privateCHashError_get_error(self);
    return error->args;
}
