

privateCHashError * privatenewCHashError(CHash *args, int error_code, const char *error_menssage){
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


void privateCHashError_free(privateCHashError *self){
    CTextStack_free(self->error_mensage);
    CHash_free(self->args);
    free(self);
}
