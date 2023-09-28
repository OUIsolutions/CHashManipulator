
typedef struct CHashObjectModule{

    CHashObject  * (*newObjectEmpty)();
    void  (*set_once)(CHashObject * self, const char *key, CHash *element);
    void  (*delete)(CHashObject *self, const char *key);
    CHash * (*get_by_index)(CHashObject * self, long index);
    CHashStringArray  * (*get_keys)(CHashObject *self);
    char   * (*get_key_of_element)(CHash *self);
    short  (*get_type)(CHashObject *self, const char *key);

    CHash * (*get)(CHashObject * self, const char *key);

    CHashArray * (*getArray)(CHashObject * self, const char *key);

    CHashObject * (*getObject)(CHashObject * self, const char *key);

    long (*getLong)(CHashObject * self, const char *key);

    double (*getDouble)(CHashObject * self, const char *key);

    bool (*getBool)(CHashObject * self, const char *key);

    char  * (*getString)(CHashObject * self, const char *key);




}CHashObjectModule;

CHashObjectModule newCHashObjectModule();