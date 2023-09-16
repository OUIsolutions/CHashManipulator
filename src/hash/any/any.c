//
// Created by mateusmoutinho on 14/09/23.
//

CHashAny * privateCHashAny_new(int type, void *value){
    CHashAny  *self  = (CHashAny*) malloc(sizeof(CHashAny));
    self->raw_type = type;
    self->value = value;
    return self;
}

ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL * privateCHashAny_get_primitive(CHashAny *element){
    
    if(!element){
        return privateCHashAny_new(CHASH_NULL, NULL);
    }


    
    if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        return casted->value;
    }

    return element;
}

long CHash_get_size(ChashArray_OR_CHashObject_OR_CHashString *element){

    if(element->raw_type == CHASH_STRING){
        return (long)strlen(CHash_get_string(element));
    }

    if(element->raw_type == CHASH_ARRAY || element->raw_type == CHASH_OBJECT){
        privateCHashArray *casted = (privateCHashArray*)(element->value);
        return casted->size;
    }

    return -1;

}
int  CHash_get_type(CHashAny *element){
    if(element->raw_type == PRIVATE_CHASH_KEY_VAL || element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
        CHashAny  *raw = privateCHashAny_get_primitive(element);
        return raw->raw_type;
    }
    return element->raw_type;

}

int CHash_set(CHashArrayItem_OR_CHashKeyVal *element, ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool_OR_NULL *value){


    if(element->raw_type == PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        casted->value = privateCHashAny_get_primitive(value);
        return 0;
    }


    return -1;
}





void CHashPrint(CHashAny *element){
    if(element->raw_type == CHASH_LONG){
        long value = CHash_get_long(element);
        printf("%ld\n",value);
    }

    if(element->raw_type == CHASH_STRING){
        char *value = CHash_get_string(element);
        printf("%s\n",value);
    }


    if(element->raw_type == CHASH_NULL){
        printf("null\n");
    }

    

    if(element->raw_type == CHASH_ARRAY){
        private_CHashArray_print(element);
    }

}