//
// Created by mateusmoutinho on 14/09/23.
//

CHashAny * privateCHashAny_new(int type, void *value){
    CHashAny  *self  = (CHashAny*) malloc(sizeof(CHashAny));
    self->type = type;
    self->value = value;
    return self;
}

