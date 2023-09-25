


CHashObject* privatenewCHashObject(void * sentinel, ...);
#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL)

CHashObject  * newCHashObjectEmpty();

void  CHashObject_set_once(CHashObject * self, const char *key, CHash *element);

void  privateCHashObject_set(CHashObject *self , ...);
#define  CHashObject_set(self,...)privateCHashObject_set(self,__VA_ARGS__,NULL)


void  CHashObject_delete(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key_or_null(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);


CHashArray  * CHashObject_get_keys(CHashObject *self);

char   * CHashObject_get_key_of_element(CHash *self);

CHash * CHashObject_get(CHashObject * self, const char *key);
