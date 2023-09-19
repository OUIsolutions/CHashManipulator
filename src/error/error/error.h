

typedef struct privateCHashError{
    CHash *args;
    int error_code;
    CTextStack * error_mensage;
}privateCHashError;

privateCHashError * privatenewCHashError(CHash *args, int error_code, const char *error_menssage);


void privateCHashError_free(privateCHashError *self);


void CHash_raise_error(CHash *self, CHash *args, int error_code,const char *error_menssage);

privateCHashError  * CHash_get_error(CHash *self);

