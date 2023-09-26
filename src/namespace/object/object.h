
typedef struct CHashObjectModule{

    CHashObject  * (*newObjectEmpty)();
    void  (*set_once)(CHashObject * self, const char *key, CHash *element);
    void  (*delete)(CHashObject *self, const char *key);
    CHash * (*get_by_index)(CHashObject * self, long index);
    CHashStringArray  * (*get_keys)(CHashObject *self);
    char   * (*get_key_of_element)(CHash *self);
    CHash * (*get)(CHashObject * self, const char *key);



}CHashObjectModule;

CHashObjectModule newCHashObjectModule();