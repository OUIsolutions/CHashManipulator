//
// Created by mateusmoutinho on 14/09/23.
//

CHashAny * privateCHashAny_new(int type, void *value){
    CHashAny  *self  = (CHashAny*) malloc(sizeof(CHashAny));
    self->type = type;
    self->value = value;
    return self;
}

ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool * privateCHashAny_get_primitive(CHashAny *element){
    if(element->type ==PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        return casted->value;
    }

    return element;
}

long CHash_get_size(ChashArray_OR_CHashObject_OR_CHashString *element){

    if(element->type == CHASH_STRING){
        return (long)strlen(CHash_get_string_from_item(element));
    }

    if(element->type == CHASH_ARRAY || element->type == CHASH_OBJECT){
        privateCHashArray *casted = (privateCHashArray*)(element->value);
        return casted->size;
    }

    return -1;

}

int CHash_set_item_value(CHashArrayItem_OR_CHashKeyVal *element, ChashArray_OR_CHashOject_OR_CHashLong_OR_CHashString_OR_CHashBool *value){

    if(element->type == PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        casted->value = privateCHashAny_get_primitive(value);
        return 0;
    }


    return -1;
}





void CHashPrint(CHashAny *element){
    if(element->type == CHASH_LONG){
        long value = CHash_get_long_from_item(element);
        printf("%ld\n",value);
    }

    if(element->type == CHASH_STRING){
        char *value = CHash_get_string_from_item(element);
        printf("%s\n",value);
    }

    if(element->type == CHASH_ARRAY){
        private_CHashArray_print(element);
    }

}