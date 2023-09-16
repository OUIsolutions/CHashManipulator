

CHashArrayItem * private_newCHashArrayItem(long position){
    CHashArrayItem * self = (CHashArrayItem*) malloc(sizeof (CHashArrayItem));
    *self = (CHashArrayItem){0};
    self->position = position;
    self->value = private_newCHashAny(CHASH_NULL, NULL);
    return self;
}

int CHashArrayItem_set(CHashArrayItem *self,CHashAny *element){
    self->value = element;
}
