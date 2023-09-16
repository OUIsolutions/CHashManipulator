//
// Created by mateusmoutinho on 14/09/23.
//

CHashAny * private_newCHashAny(int type, void *value){
    CHashAny  *self  = (CHashAny*) malloc(sizeof(CHashAny));
    self->raw_type = type;
    self->value = value;
    return self;
}

