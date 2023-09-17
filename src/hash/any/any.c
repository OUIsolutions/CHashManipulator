//
// Created by mateusmoutinho on 14/09/23.
//

CHashAny * privateCHashAny_new(int type, void *value){
    CHashAny  *self  = (CHashAny*) malloc(sizeof(CHashAny));
    self->raw_type = type;
    self->value = value;
    return self;
}


CHashAny * privateCHashAny_get_primitive(CHashAny *element){

    if(!element){
        return NULL;
    }

    if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        return casted->value;
    }

    if(element->raw_type == PRIVATE_CHASH_KEY_VAL){
        privateCHashKeyVal *casted = (privateCHashKeyVal*)(element->value);
        return casted->value;
    }


    return element;
}

long CHash_get_size(CHashIterable *element){
    CHashAny *raw = privateCHashAny_get_primitive(element);
    if(!raw){
        return -1;
    }
    if(raw->raw_type == CHASH_STRING){
        return (long)strlen(CHash_toString(raw));
    }

    if(raw->raw_type == CHASH_ARRAY || raw->raw_type == CHASH_OBJECT){
        privateCHashArray *casted = (privateCHashArray*)(raw->value);
        return casted->size;
    }

    return -1;

}
int  CHash_get_type(CHashAny *element){
    CHashAny  *raw = privateCHashAny_get_primitive(element);
    if(!raw){
        return -1;
    }
    return raw->raw_type;
}

int CHash_set(CHashAny *element, CHashAny *value){


    if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        casted->value = value;
        return 0;
    }

    if(element->raw_type == PRIVATE_CHASH_KEY_VAL){
        privateCHashKeyVal *casted = (privateCHashKeyVal*)(element->value);
        casted->value = value;
        return 0;
    }

    element->raw_type = value->raw_type;
    value->value = value->value;

    return 0;

}




