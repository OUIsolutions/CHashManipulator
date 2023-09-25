


CHashObject* newCHashObject(void * sentinel, ...);


void  privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element);


void  CHashObject_set(CHashObject *self , ...);

void  CHash_delete_by_key(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);


CHashArray  * CHash_get_keys_of_object(CHashObject *self);

char * CHash_get_key_of_element(CHash *element);

CHash * CHash_get_any_by_key(CHashObject * self, const char *key);
