

CHashArray  * newCHashArray(){
    CHashArray * self = (CHashArray*)malloc(sizeof (CHashArray));
    self->size = 0;
    self->elements = malloc(0);
    return self;
}

int CHashArray_append(CHashArray *self, CHashAny *element){

    self->elements = (CHashArrayItem **)realloc(self->elements,(self->size +1) * sizeof(CHashArrayItem **));
    CHashArrayItem *new_element = private_newCHashArrayItem(self->size)

    CHashArrayItem_set(new_element, element);
    self->elements[self->size] = new_element;



    self->size+=1;
    return 0;
}

CHashArrayItem *CHashArray_get(CHashArray  *self, long position){
    long size = self->size;

    long converted_position = position;


    if(position < 0){
        converted_position = size + position;
    }

    if(converted_position < 0){
        converted_position = 0;
    }


    if(converted_position >=size){
        CHashArrayItem * new_element = private_newCHashArrayItem(self->size);
        CHashAny *new_element_any  = private_newCHashAny(
                PRIVATE_CHASH_ARRAY_ITEM,
                new_element
        );
        CHashArray_append(self, new_element_any);
        return new_element;
    }

    return self->elements[converted_position];

}


