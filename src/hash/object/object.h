


CHashObject* privatenewCHashObject(void * sentinel, ...);
#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL);

CHashObject  * newCHashObjectEmpty();

void  CHash_set_by_key_once(CHashObject * self, const char *key, CHash *element);

void  privateCHashObject_set(CHashObject *self , ...);
#define  CHash_set_by_key(self,...)privateCHashObject_set(self,__VA_ARGS__,NULL)


void  CHash_delete_by_key(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);


CHashArray  * CHash_get_keys(CHashObject *self);

char * CHash_get_key_of_element(CHash *element);

CHash * CHash_get_by_key(CHashObject * self, const char *key);
