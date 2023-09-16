

typedef struct CHashArrayItem{
    long position;
    CHashAny *value;

}CHashArrayItem;


CHashArrayItem * private_newCHashArrayItem(long position);

int CHashArrayItem_set(CHashArrayItem *self,CHashAny *element);