


CHashObject* privatenewCHashObject(void * sentinel, ...);
#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL)

CHashObject  * newCHashObjectEmpty();

void  CHashObject_set_once(CHashObject * self, const char *key, CHash *element);

void  privateCHashObject_set(CHashObject *self , ...);
#define  CHashObject_set(self,...)privateCHashObject_set(self,__VA_ARGS__,NULL)

void  CHashObject_set_default(CHashObject * self, const char *key, CHash *element);

void  CHashObject_remove(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key_or_null(CHashObject * self, const char *key);

bool CHashObject_exist(CHashObject *self, const char *key);



char * CHashObject_get_key_by_index(CHashObject *self,long index);


char   * CHashObject_get_key_of_element(CHash *self);


short  CHashObject_get_type(CHashObject *self, const char *key);

CHash * CHashObject_get(CHashObject * self, const char *key);

CHashArray * CHashObject_getArray(CHashObject * self, const char *key);

CHashObject * CHashObject_getObject(CHashObject * self, const char *key);


double CHashObject_getNumber(CHashObject * self, const char *key);

bool CHashObject_getBool(CHashObject * self, const char *key);

char  * CHashObject_getString(CHashObject * self, const char *key);


