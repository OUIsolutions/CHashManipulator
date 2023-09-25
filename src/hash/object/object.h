


CHashObject* privatenewCHashObject(void * sentinel, ...);
#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL);

CHashObject  * newCHashObjectEmpty();

void  CHashObject_set_once(CHashObject * self, const char *key, CHash *element);

void  privateCHashObject_set(CHashObject *self , ...);
#define  CHash_set_by_key(self,...)privateCHashObject_set(self,__VA_ARGS__,NULL)


void  CHashObject_delete(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key_or_null(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);


CHashArray  * CHashObject_get_keys(CHashObject *self);


CHash * CHashObject_get(CHashObject * self, const char *key);
