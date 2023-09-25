

CHashArray  *newCHashArrayEmpty();


CHashArray * privatenewCHashArray(void *sentinel, ...);
#define  newCHashArray(...)privatenewCHashArray(NULL,__VA_ARGS__,NULL)


CHashArray * privatenewCHashStringArray(void *sentinel, ...);
#define  newCHashStringArray(...)privatenewCHashStringArray(NULL,__VA_ARGS__,NULL)
void CHashArray_append_once(CHashArray *self, CHash *element);


void privateCHashArray_append(CHashArray *self, ...);
#define  CHashArray_append(self,...)privateCHashArray_append(self,__VA_ARGS__,NULL)



void  CHashArray_delete(CHashArray *self, long index);

CHash * CHashArray_get(CHashArray *self, long position);

