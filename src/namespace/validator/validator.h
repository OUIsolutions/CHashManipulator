

typedef struct CHashValidatorModule {
    void (*raise_error)(CHash *self,int error_code,const char *error_menssage, CHash *args);

    int (*ensure_Number)(CHash *element);
    int (*ensure_Number_by_key)(CHash *object, const char *key);
    int (*ensure_Number_by_index)(CHash *array, long index);


    int (*ensure_min)(CHash *element, double  min);
    int (*ensure_min_by_key)(CHash *object, const char *key, double min );
    int (*ensure_min_by_index)(CHash *array, long index, double min);


    int (*ensure_max)(CHash *element, double  max);
    int (*ensure_max_by_key)(CHash *object, const char *key, double  max);
    int (*ensure_max_by_index)(CHash *array, long index, double  max);

    int (*ensure_Bool)(CHash *element);
    int (*ensure_Bool_by_key)(CHash *object , const char *key);
    int (*ensure_Bool_by_index)(CHash *array , long index);

    int (*ensure_String)(CHash *element);
    int (*ensure_String_by_key)(CHash *object , const char *key);
    int (*ensure_String_by_index)(CHash *array , long index);

    int (*ensure_Object)(CHash *element);
    int (*ensure_Object_by_key)(CHash *object , const char *key);
    int (*ensure_Object_by_index)(CHash *array , long index);
    int (*ensure_only_keys)(CHashObject *object, CHashStringArray *keys);
    int (*ensure_only_keys_cleaning_args)(CHashObject *object, CHashStringArray *keys);


    int (*ensure_Array)(CHash *element);
    int (*ensure_Array_by_key)(CHash *object , const char *key);
    int (*ensure_Array_by_index)(CHash *array , long index);

    int (*ensure_min_size)(CHash *iterable,long min);
    int (*ensure_min_size_by_key)(CHash  *object, const char *key,long min);
    int (*ensure_min_size_by_index)(CHash  *array, long index,long  min);


    int (*ensure_max_size)(CHash *iterable,long max);
    int (*ensure_max_size_by_key)(CHash  *object, const char *key,long max);
    int (*ensure_max_size_by_index)(CHash  *array, long index,long  max);


}CHashValidatorModule;

CHashValidatorModule newCHashValidatorModule();
