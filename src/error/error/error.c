

CHashError * privatenewCHashError(CHash *args, int error_code,const char *error_menssage){
    CHashError  *self = (CHashError*) malloc(sizeof (CHashError));
    self->args = args;
    self->error_code = error_code;
    self->error_mensage = NULL;

}

char *CHashError_recreate_error_menssage(CHashError *self,const char *error_menssage){
    if(self->error_mensage){
        free(self->error_mensage);
    }


}
void CHashError_free(CHashError *error);