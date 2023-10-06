

typedef struct CHashValidatorModule {
    void (*raise_error)(CHash *self,int error_code,const char *error_menssage, CHash *args);

    int (*ensure_Double)(CHash *element);


    int (*ensure_Bool)(CHash *element);

    int (*ensure_String)(CHash *element);

    int (*ensure_Object)(CHash *element);

    int (*ensure_Array)(CHash *element);

}CHashValidatorModule;

CHashValidatorModule newCHashValidatorModule();
