

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
    }

    return self;
}

bool Chash_errors(CHash *self){

    if(!self){
        return true;
    }

    if(self->private_error){
        return true;
    }
    return false;
}

void CHash_raise_error(CHash *self,int error_code,const char *error_menssage, CHash *args){
    if(Chash_errors(self)){return;}
    CHashArray  *path = CHash_get_path(self);
    if(!args){
        args = newCHashObject(NULL);
    }
    CHashObject_set(args,
         "path",path,
         "value",self
    );

    self->private_error = (privateCHashError*) privatenewCHashError(
        args,
        error_code,
        error_menssage
    );
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
    privateCHashError  *error = (privateCHashError*)self->private_error;
    return error->error_mensage->rendered_text;
}

int CHash_get_error_code(CHash *self){
    if(!Chash_errors(self)){
        return 0;
    }
    privateCHashError  *error = (privateCHashError*)self->private_error;
    return error->error_code;
}

CHash * CHash_get_error_args(CHash *self){
    if(!Chash_errors(self)){
        return NULL;
    }
    privateCHashError  *error = (privateCHashError*)self->private_error;
    return error->args;
}
