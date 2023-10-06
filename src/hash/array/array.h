

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

void  CHashArray_set(CHashArrayOrObject *self, long index,CHash *element);


void  CHashArray_remove(CHashArrayOrObject *self, long index);

CHash * CHashArray_get(CHashArray *self, long index);

void CHashArray_foreach(CHashArray *self,void  (*callback)(CHash *current));

long CHashArray_find(CHashArray *self, CHash *element);


long CHashArray_find_Number(CHashArray *self, double element);

long CHashArray_find_Bool(CHashArray *self, bool  element);

long CHashArray_find_String(CHashArray *self, const char *element);


short CHashArray_get_type(CHashArray *self, long index);



CHashArray * CHashArray_getArray(CHashObject * self, long index);

CHashObject * CHashArray_getObject(CHashObject * self, long index);


double CHashArray_getNumber(CHashArrayOrObject *self, long index);

bool CHashArray_getBool(CHashObject * self, long index);

char  * CHashArray_getString(CHashObject * self, long index);

