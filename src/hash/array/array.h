

#define newCHashArray(...) privatenewCHashArray(NULL,__VA_ARGS__,NULL)

CHashArray * privatenewCHashArray(void *sentinel, ...);


void CHashArray_append(CHashArray *self,CHash *element);

CHash * CHashArray_get(CHashArray *self, long position);

