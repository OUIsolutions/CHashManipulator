

typedef struct CHashError{
    CHash *args;
    int error_code;
    char *error_mensage;
}CHashError;

CHashError * privatenewCHashError(CHash *args, int error_code,const char *error_menssage);

char *CHashError_recreate_error_menssage(CHashError *self,const char *error_menssage);

void CHashError_free(CHashError *error);


void CHash_raise_error(CHash *self, CHash *args, int error_code,const char *error_menssage);

CHashError  * CHash_get_error(CHash *self);

