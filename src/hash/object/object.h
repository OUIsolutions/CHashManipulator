

#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL)

CHashObject* privatenewCHashObject(void * sentinel, ...);


int privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element);

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);

CHash * CHashObject_get(CHashObject * self, const char *key);
