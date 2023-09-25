


CHashArray * newCHashArray(void *sentinel, ...);


void privateCHashArray_append_once(CHashArray *self, CHash *element);

#define CHashArray_append(...) privateCHashArray_append(__VA_ARGS__,NULL)
void privateCHashArray_append(CHashArray *self, CHashArray *element, ...);


void  CHashArray_delete(CHashArray *self, long index);

CHash * CHashArray_get(CHashArray *self, long position);

