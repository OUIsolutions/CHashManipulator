

typedef struct CHashNamespace{


    CHash * (*load_from_cJSON)(cJSON *element);
    CHash * (*load_from_json_strimg)(const char *element);
    CHash * (*load_from_json_file)(const char *filename);


    cJSON * (*dump_to_cJSON)(CHash *element);
    char * (*dump_to_json_string)(CHash * element);
    int  (*dump_to_json_file)(CHash *element,const char *filename);


    CHash * (*newBool)(bool value);
    bool (*toBool)(CHash *element);


    CHash * (*newNumber)(double value);
    double  (*toNumber)(CHash *element);


    CHash * (*newStackString)(CTextStack *element);
    CTextStack  *(*toStack)(CHash *element);


    CHash * (*newString)(const char *value);
    char * (*toString)(CHashArray *element);
    CHash * (*newNULL)();

    void (*print)(CHash *self);
    CHashArray * (*get_path)(CHash *self);
    CHash * (*copy)(CHash *self);

    bool (*errors)(CHash *self);
    char * (*get_error_menssage)(CHash *self);
    int (*get_error_code)(CHash *self);
    CHash * (*get_error_args)(CHash *self);



    bool (*equals)(CHash *element1, CHash *element2);

    long (*get_size)(CHash *self);

    short (*get_type)(CHash *self);


    void (*free)(CHash *self);

    CHashObjectModule  object;
    CHashArrayModule array;
    CHashValidatorModule validator;
}CHashNamespace;

CHashNamespace newCHashNamespace();