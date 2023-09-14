

privateCHashArrayItem * privateCHashArrayItem_new(long position){
    privateCHashArrayItem * self = (privateCHashArrayItem*) malloc(sizeof (privateCHashArrayItem));
    *self = (privateCHashArrayItem){0};
    self->position = position;
    return self;
}
