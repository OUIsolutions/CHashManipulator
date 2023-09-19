

typedef struct privateCHashError{
    CHash *args;
    int error_code;
    CTextStack * error_mensage;
}privateCHashError;

privateCHashError * privatenewCHashError(CHashObject *args, int error_code, const char *error_menssage);


void privateCHashError_free(privateCHashError *self);

bool Chash_errors(CHash *self);


void CHash_raise_error(CHash *self, CHashObject *args, int error_code,const char *error_menssage);

char * CHash_get_error_menssage(CHash *self);

int CHash_get_error_code(CHash *self);

CHash * CHash_get_error_args(CHash *self);

