

typedef struct CHashValidatorModule {

    int (*ensure_Double)(CHash *element);

    int (*ensure_Long)(CHash *element);

    int (*ensure_Bool)(CHash *element);

    int (*ensure_String)(CHash *element);

    int (*ensure_Object)(CHash *element);

    int (*ensure_Array)(CHash *element);

}CHashValidatorModule;

CHashValidatorModule newCHashValidatorModule();
