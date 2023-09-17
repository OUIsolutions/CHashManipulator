


CHashObject* newCHashObject();


int CHashObject_set(CHashObject * object,const char *key, CHash *element);

CHashAny * privateCHashObject_get_by_key(CHashObject * object, const char *key);

CHashAny * CHashObject_get_by_index(CHashObject * object, const char *key);

CHashAny * CHashObject_get(CHashObject * object, const char *key);