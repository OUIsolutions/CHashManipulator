


CHashObject* privatenewCHashObject(void * sentinel, ...);
#define newCHashObject(...) newCHashObject(NULL,__VA_ARGS__,NULL);


void  CHashObject_set_once(CHashObject * self, const char *key, CHash *element);

void  privateCHashObject_set(CHashObject *self , ...);


void  CHash_delete_by_key(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);


CHashArray  * CHash_get_keys_of_object(CHashObject *self);

char * CHash_get_key_of_element(CHash *element);

CHash * CHash_get_any_by_key(CHashObject * self, const char *key);
