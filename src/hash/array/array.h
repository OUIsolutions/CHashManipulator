


CHashArray * newCHashArray(void *sentinel, ...);


void privateCHashArray_append_once(CHashArray *self, CHash *element);

void CHashArray_append(CHashArray *self, CHashArray *element, ...);


void  CHashArray_delete(CHashArray *self, long index);

CHash * CHashArray_get(CHashArray *self, long position);

