
CHash * privatenewChash_raw(){
    CHash  *self = (CHash*) malloc(sizeof (CHash));
    *self = (CHash){0};
    self->private_first = self;
    return self;
}

void CHash_print(CHash *self){
    char * result = CHash_dump_to_json_string(self);
    printf("%s\n",result);
    free(result);
}

CHashArray * CHash_get_path(CHash *self){

    if(self->private_reference_type == PRIVATE_CHASH_NOT_A_REFERENCE){
        return  newCHashArray(NULL);
    }

    CHashArray  *path = CHash_get_path(self->private_father);

    if(self->private_reference_type == PRIVATE_CHASH_ARRAY_ITEM){
        CHashArray_append(path, newCHashLong(self->private_index));;
    }

    if(self->private_reference_type == PRIVATE_CHASH_KEYVAL){
        CHashArray_append(path, newCHashString(self->private_key));
    }
    return path;

}

bool CHash_equals(CHash *element1, CHash *element2){
    char *element1_str = CHash_dump_to_json_string(element1);
    char *element2_str = CHash_dump_to_json_string(element2);

    bool equal = strcmp(element1_str,element2_str) == 0;
    free(element1_str);
    free(element2_str);
    return equal;
}


void CHash_free(CHash *self){

    if(self->private_reference_type == PRIVATE_CHASH_KEYVAL){
        free(self->private_key);
    }
    if(self->private_reference_type == PRIVATE_CHASH_NOT_A_REFERENCE){
        if(self->private_error){
            privateCHashError *error = (privateCHashError*)self->private_error;
            privateCHashError_free(error);
        }
    }

    if(self->private_type == CHASH_STRING){
        CTextStack_free(self->private_value_stack);
    }

    if(self->private_type == CHASH_OBJECT || self->private_type == CHASH_ARRAY){
        long size = self->private_size;
        for(int i = 0; i < size; i++){
            CHash * current = self->private_sub_elements[i];
            CHash_free(current);
        }
        free(self->private_sub_elements);
    }


    free(self);
}

long CHash_get_type(CHash *self){
    if(!self){
        return -1;
    }
    return self->private_type;
}

long CHash_get_size(CHash *self){
    if(self->private_type == CHASH_STRING){
        return (long)self->private_value_stack->size;
    }
    if(self->private_type == CHASH_OBJECT || self->private_type == CHASH_STRING){
        return self->private_size;
    }
    return -1;
}


CHash * CHash_copy(CHash *self){
    
    if(self->private_type == CHASH_STRING){
        return newCHashString(self->private_value_stack->rendered_text);
    }
    
    if(self->private_type == CHASH_LONG){
        return newCHashLong(self->private_value_long);
    }

    if(self->private_type == CHASH_DOUBLE){
        return newCHashDouble(self->private_value_double);
    }
    
    if(self->private_type == CHASH_BOOL){
        return newCHashBool(self->private_value_bool);
    }

    if(self->private_type == CHASH_ARRAY ){
        CHash * new_element  = newCHashArray(NULL);

        for(long i =0; i < self->private_size; i++){
            CHash * copy = CHash_copy(CHashArray_get(self,i));
            CHashArray_append(new_element,copy);
        }
        return new_element;

    }

    if(self->private_type == CHASH_OBJECT){
        CHash * new_element  = newCHashObject(NULL);

        for(long  i =0; i < self->private_size; i++){
            CHash  * current = CHashObject_get_by_index(self,i);
            CHash *copy = CHash_copy(current);

            CHashObject_set(new_element, current->private_key, copy);
        }
        return new_element;
    }


    return newCHashNULL();
}


CHash * newCHashNULL(){
    return privatenewChash_raw();
}
