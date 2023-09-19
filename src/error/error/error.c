

privateCHashError * privatenewCHashError(CHashObject *args, int error_code, const char *error_menssage){
    privateCHashError  *self = (privateCHashError*) malloc(sizeof (privateCHashError));
    self->args = args;
    self->error_code = error_code;

    self->error_mensage =  newCTextStack_string(error_menssage);

    long args_size = CHash_get_size(self->args);
    for(int i = 0; i < args_size; i++){
        CHash *current = CHashObject_get_by_index(self->args,i);
        char *key = CHashObject_get_element_key(current);
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

    CHash  *first = self->private_first;
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
    CHashArray  *path = CHash_get_path(self);
    
    CHash *formated_args = args;

    if(!args){
        formated_args = newCHashObject(NULL);
    }
    CHashObject_set(formated_args,
         "path",path,
         "value",CHash_copy(self)
    );

    privateCHashError *created = privatenewCHashError(
            formated_args,
            error_code,
            error_menssage
    );
    bool first = self->private_reference_type == PRIVATE_CHASH_NOT_A_REFERENCE;
    if(first){
        self->private_error = (void*)created;
    }

    if(!first){
        self->private_first->private_error = (void*)created;
    }
    
}

void privateCHashError_free(privateCHashError *self){
    CTextStack_free(self->error_mensage);
    CHash_free(self->args);
    free(self);
}

char * CHash_get_error_menssage(CHash *self){

    if(!Chash_errors(self)){
        return NULL;
    }
    privateCHashError  *error = privateCHashError_get_error(self);
    return error->error_mensage->rendered_text;
}

int CHash_get_error_code(CHash *self){
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
