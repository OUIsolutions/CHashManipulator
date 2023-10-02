

CHashArray  *newCHashArrayEmpty();

long privateCHashArray_convert_index(CHashArray *self, long index);

CHashArray * privatenewCHashArray(void *sentinel, ...);
#define  newCHashArray(...)privatenewCHashArray(NULL,__VA_ARGS__,NULL)


CHashArray * privatenewCHashStringArray(void *sentinel, ...);
#define  newCHashStringArray(...)privatenewCHashStringArray(NULL,__VA_ARGS__,NULL)
void CHashArray_append_once(CHashArray *self, CHash *element);


void privateCHashArray_append(CHashArray *self, ...);
#define  CHashArray_append(self,...)privateCHashArray_append(self,__VA_ARGS__,NULL)


void CHashArray_switch(CHashArray *self, long index ,long target_index);

void  CHashArray_delete(CHashArray *self, long index);

CHash * CHashArray_get(CHashArray *self, long index);

short CHashArray_get_type(CHashArray *self, long index);


CHashArray * CHashArray_getArray(CHashObject * self, long index);

CHashObject * CHashArray_getObject(CHashObject * self, long index);

long CHashArray_getLong(CHashObject * self, long index);

double CHashArray_getDouble(CHashObject * self, long index);

bool CHashArray_getBool(CHashObject * self, long index);

char  * CHashArray_getString(CHashObject * self, long index);

