

privateCHashArrayItem * privateCHashArrayItem_new(long position){
    privateCHashArrayItem * self = (privateCHashArrayItem*) malloc(sizeof (privateCHashArrayItem));
    *self = (privateCHashArrayItem){0};
    self->position = position;
    self->value = privateCHashAny_new(CHASH_NULL,NULL);
    return self;
}

