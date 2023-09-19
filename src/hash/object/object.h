

#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL)

CHashObject* privatenewCHashObject(void * sentinel, ...);


int privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element);

#define CHashObject_set(...) privateCHashObject_set(__VA_ARGS__,NULL)
int privateCHashObject_set(CHashObject *self ,...);

int CHashObject_delete(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);

CHashArray  * CHashObject_get_keys(CHashObject *self);

CHash * CHashObject_get(CHashObject * self, const char *key);
