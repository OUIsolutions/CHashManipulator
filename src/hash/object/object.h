


CHashObject* newCHashObject();


int CHashObject_set(CHashObject * object,const char *key, CHash *element);

CHash * privateCHashObject_get_by_key(CHashObject * object, const char *key);

CHash * CHashObject_get_by_index(CHashObject * object, const char *key);

CHash * CHashObject_get(CHashObject * object, const char *key);