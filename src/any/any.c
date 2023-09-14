//
// Created by mateusmoutinho on 14/09/23.
//

CHashAny * privateCHashAny_new(int type, void *value){
    CHashAny  *self  = (CHashAny*) malloc(sizeof(CHashAny));
    self->type = type;
    self->value = value;
    return self;
}

CHashAny * privateCHashAny_get_value_from_keyvall_or_array_item(CHashAny *element){
    if(element->type ==PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        return casted->value;
    }
    return element;
}
void CHash_set(CHashAny *element,CHashAny *value){

    if(element->type == PRIVATE_CHASH_ARRAY_ITEM){
        privateCHashArrayItem *casted = (privateCHashArrayItem*)(element->value);
        casted->value = value;
    }

}