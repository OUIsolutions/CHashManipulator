/*
MIT License

Copyright (c) 2023 CHashManipulator

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef CHashManipulator
#define CHashManipulator

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>


//#include "dependencies/declaration.h"



char *privateCHash_read_file(const char *filename);

int privateCHash_write_file(const char *filename, const char *value);



typedef struct CHash{

    unsigned short private_type;
    unsigned short private_reference_type;

    void *private_error;

    struct CHash *private_father;
    unsigned long private_size;

    //these is the reference system
    union {
        unsigned long private_index;
        char * private_key;
    };
    //these is the values sysstem
    union {
        CTextStack  *private_value_stack;
        double private_value_double;
        long private_value_long;
        bool private_value_bool;
        struct CHash **private_sub_elements;
    };

}CHash;

enum {
    PRIVATE_CHASH_NOT_A_REFERENCE,
    PRIVATE_CHASH_ARRAY_ITEM,
    PRIVATE_CHASH_KEYVAL
};

typedef CHash CHashArray;
typedef CHash CHashObject;


CHash * privatenewChash_raw();



void CHash_print(CHash *self);

CHashArray * CHash_get_path(CHash *self);

CHash * CHash_copy(CHash *self);

void CHash_free(CHash *self);

bool CHash_equals(CHash *element1, CHash *element2);

long CHash_get_size(CHash *self);


CHash * privateCHash_get_first_object(CHash *self);

CHash * newCHashNULL();



double  CHash_toDouble(CHash *element);

CHash * newCHashDouble(double value);




long CHash_toLong(CHash *element);

CHash * newCHashLong(long value);




bool CHash_toBool(CHash *element);

CHash * newCHashBool(bool value);




char * CHash_toString(CHashArray *element);

CTextStack  *CHash_toStackSttring(CHash *element);

CHash * newCHashStackString(CTextStack *element);

CHash * newCHashString(const char *value);



#define newCHashArray(...) privatenewCHashArray(NULL,__VA_ARGS__,NULL)

CHashArray * privatenewCHashArray(void *sentinel, ...);


void privateCHashArray_append_once(CHashArray *self, CHash *element);

#define CHashArray_append(...) privateCHashArray_append(__VA_ARGS__,NULL)
void privateCHashArray_append(CHashArray *self, CHashArray *element, ...);


void  CHashArray_delete(CHashArray *self, long index);

CHash * CHashArray_get(CHashArray *self, long position);





#define newCHashObject(...) privatenewCHashObject(NULL,__VA_ARGS__,NULL)

CHashObject* privatenewCHashObject(void * sentinel, ...);


void  privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element);

#define CHashObject_set(...) privateCHashObject_set(__VA_ARGS__,NULL)
void  privateCHashObject_set(CHashObject *self ,...);

void  CHash_delete_by_key(CHashObject *self, const char *key);

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key);

CHash * CHashObject_get_by_index(CHashObject * self, long index);


CHashArray  * CHash_get_keys_of_object(CHashObject *self);

char * CHash_get_key_of_element(CHash *element);

CHash * CHash_get_any_by_key(CHashObject * self, const char *key);





enum{
    CHASH_NULL,
    CHASH_ARRAY,
    CHASH_OBJECT,
    CHASH_LONG,
    CHASH_DOUBLE,
    CHASH_BOOL,
    CHASH_STRING
};

long CHash_get_type(CHash *self);

const char  *private_Chash_convert_type(long type);




cJSON * privateCHash_dumps_json_object(CHashObject *object);

cJSON * privateCHash_dumps_json_array(CHashArray *object);

cJSON * CHash_dump_to_cJSON(CHash *element);


char * CHash_dump_to_json_string(CHash * element);

int  CHash_dump_to_json_file(CHash *element,const char *filename);

//loaders

CHash  * privateCHash_load_json_object(cJSON *element);

CHash  * privateCHash_load_json_array(cJSON *element);


CHash * CHash_load_from_cJSON(cJSON *element);

CHash * CHash_load_from_json_strimg(const char *element);

CHash * CHash_load_from_json_file(const char *filename);










#define CHASH_ELEMENT_NOT_EXIST 200
#define CHASH_WRONG_TYPE 201



typedef struct privateCHashError{
    CHash *args;
    int error_code;
    CTextStack * error_mensage;
}privateCHashError;

privateCHashError * privatenewCHashError(CHashObject *args, int error_code, const char *error_menssage);


void privateCHashError_free(privateCHashError *self);

bool Chash_errors(CHash *self);


void CHash_raise_error(CHash *self,int error_code,const char *error_menssage, CHash *args);


char * CHash_get_error_menssage(CHash *self);


int CHash_get_error_code(CHash *self);

CHash * CHash_get_error_args(CHash *self);


privateCHashError * privateCHashError_get_error(CHash *self);


int private_chash_check_type(CHash *element, unsigned short  expected_type,char *expected_type_str);

int CHash_ensure_double(CHash *element);

int CHash_ensure_long(CHash *element);

int CHash_ensure_string(CHash *element);



//#include "dependencies/definition.h"





char *privateCHash_read_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);


    char *buffer = (char *)malloc(file_size + 1);


    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);
    return buffer;
}

int  privateCHash_write_file(const char *filename, const char *value) {

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        return 1;
    }
    fputs(value, file);

    fclose(file);
    return 0;
}



CHash * privatenewChash_raw(){
    CHash  *self = (CHash*) malloc(sizeof (CHash));
    *self = (CHash){0};
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

CHash * privateCHash_get_first_object(CHash *self){
    if(self->private_reference_type == PRIVATE_CHASH_NOT_A_REFERENCE) {
        return self;
    }
    return privateCHash_get_first_object(self->private_father);

}
CHash * newCHashNULL(){
    return privatenewChash_raw();
}




long CHash_toLong(CHash *element){
    if(Chash_errors(element)){
        return -1;
    }

    if(element->private_type != CHASH_LONG){
        return -1;
    }
    return element->private_value_long;
}

CHash * newCHashLong(long value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_LONG;
    self->private_value_long = value;
    return self;
}





double CHash_toDouble(CHash *element){

    if(CHash_ensure_double(element)){
        return -1;
    }

    return element->private_value_double;

}

CHash * newCHashDouble(double value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_DOUBLE;
    self->private_value_double = value;
    return self;
}





bool CHash_toBool(CHash *element){
    if(element->private_type != CHASH_BOOL){
        return false;
    }
    return element->private_value_bool;
}

CHash * newCHashBool(bool value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_BOOL;
    self->private_value_bool = value;
    return self;
}









char * CHash_toString(CHashArray *element){
    if(CHash_ensure_string(element)){
        return NULL;
    }

    return element->private_value_stack->rendered_text;
}

CTextStack  *CHash_toStackSttring(CHash *element){
    if(CHash_ensure_string(element)){
        return NULL;
    }
    if(element->private_type != CHASH_STRING){
        return NULL;
    }
    return element->private_value_stack;
}

CHash * newCHashStackString(CTextStack *element){

    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_STRING;
    self->private_value_stack = element;
    return self;
}

CHash * newCHashString(const char *value){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_STRING;
    self->private_value_stack = newCTextStack_string(value);
    return self;
}


void privateCHashArray_append_once(CHashArray *self, CHash *element){
    if(Chash_errors(self)){return;}

    self->private_sub_elements = (CHash**) realloc(
            self->private_sub_elements,
            (self->private_size + 1) * sizeof(CHash**)
    );
    element->private_reference_type = PRIVATE_CHASH_ARRAY_ITEM;
    element->private_father = self;
    element->private_index = self->private_size;
    self->private_sub_elements[self->private_size]= element;
    self->private_size+=1;


}

CHashArray * privatenewCHashArray(void *sentinel,...){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_ARRAY;
    self->private_sub_elements = (CHash**)malloc(0);
    self->private_size = 0;

    va_list args;
    va_start(args, sentinel);

    while(true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }

        CHash * current_element = (CHash*)current;
        privateCHashArray_append_once(self, current_element);
    }
    va_end(args);
    return self;
}


void privateCHashArray_append(CHashArray *self, CHashArray *element, ...){
    if(Chash_errors(self)){return;}

    privateCHashArray_append_once(self, element);

    va_list args;
    va_start(args, NULL);

    while(true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }
        CHash * current_element = (CHash*)current;
        privateCHashArray_append_once(self, current_element);
    }
    va_end(args);

}
void CHashArray_delete(CHashArray *self, long index){
    if(Chash_errors(self)){return;}

    CHash  *current = CHashArray_get(self,index);
    CHash_free(current);
    self->private_size-=1;

    for(int i = 0; i <  self->private_size;i++){
        self->private_sub_elements[i] = self->private_sub_elements[i + 1];

    }
}
CHash * CHashArray_get(CHashArray *self, long index){
    if(Chash_errors(self)){
        return NULL;
    }

    return self->private_sub_elements[index];
}



CHashObject* privatenewCHashObject(void * sentinel, ...){
    CHash * self =  privatenewChash_raw();
    self->private_type = CHASH_OBJECT;
    self->private_sub_elements = (CHash**)malloc(0);
    self->private_size = 0;

    va_list args;
    va_start(args, sentinel);

    const int GETTING_KEY = 0;
    const int GETTING_VALUE = 1;

    int state = GETTING_KEY;

    char *key;

    while (true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }

        if(state == GETTING_KEY){
            key = (char*)current;
            state = GETTING_VALUE;
            continue;
        }

        if(state == GETTING_VALUE){
            privateCHashObject_set_once(self, key, (CHash *) current);
            state = GETTING_KEY;
        }

    }

    return self;
}

CHash * privateCHashObject_get_by_key(CHashObject * self, const char *key){
    if(Chash_errors(self)){
        return NULL;
    }
    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        if(strcmp(current->private_key, key) == 0){
            return current;
        }
    }
    return NULL;
}

CHash * CHashObject_get_by_index(CHashObject * self, long index){
    if(Chash_errors(self)){
        return NULL;
    }
    return self->private_sub_elements[index];
}

CHash * CHash_get_any_by_key(CHashObject * self, const char *key){
    if(Chash_errors(self)){
        return NULL;
    }

    CHash *element = privateCHashObject_get_by_key(self,key);

    if(element){
        return  element;
    }

    CHash_raise_error(element, CHASH_ELEMENT_NOT_EXIST, "element at #path# not exist", NULL);

    return  NULL;
}

void  CHash_delete_by_key(CHashObject *self, const char *key){
    if(Chash_errors(self)){return;}

    bool found = false;

    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        if(strcmp(current->private_key, key) == 0){
            CHash_free(current);
            found = true;
            self->private_size-=1;
        }

        if(found){
            self->private_sub_elements[i] = self->private_sub_elements[i + 1];
        }

    }
    
}
void  privateCHashObject_set_once(CHashObject * self, const char *key, CHash *element){
    if(Chash_errors(self)){return;}

    CHash_delete_by_key(self, key);

    self->private_sub_elements = (CHash**) realloc(
            self->private_sub_elements,
            (self->private_size + 1) * sizeof(CHash**)
    );

    element->private_reference_type = PRIVATE_CHASH_KEYVAL;
    element->private_father = self;
    element->private_key = strdup(key);
    self->private_sub_elements[self->private_size]= element;
    self->private_size+=1;
}


CHashArray  * CHash_get_keys_of_object(CHashObject *self){
    if(Chash_errors(self)){
        return NULL;
    }

    CHashArray * keys = newCHashArray(NULL);
    for(int i =0;i < self->private_size; i ++){
        CHash * current = self->private_sub_elements[i];
        CHashArray_append(keys, newCHashString(current->private_key));
    }
    return keys;
}

char * CHash_get_key_of_element(CHash *element){
    if(Chash_errors(element)){
        return  NULL;
    }

    return element->private_key;
}

void  privateCHashObject_set(CHashObject *self ,...){
    if(Chash_errors(self)){return;}

    va_list args;

    va_start(args, NULL);

    const int GETTING_KEY = 0;
    const int GETTING_VALUE = 1;

    int state = GETTING_KEY;

    char *key;

    while (true){
        void * current = va_arg(args,void*);
        if(!current){
            break;
        }

        if(state == GETTING_KEY){
            key = (char*)current;
            state = GETTING_VALUE;
            continue;
        }

        if(state == GETTING_VALUE){
            privateCHashObject_set_once(self, key, (CHash *) current);
         
            state = GETTING_KEY;
        }

    }
    va_end(args);
    
}





long CHash_get_type(CHash *self){
    if(Chash_errors(self)){
        return -1;
    }
    return self->private_type;
}

const char  *private_Chash_convert_type(long type){

    if(type == CHASH_NULL){
        return "null";
    }

    if(type == CHASH_ARRAY){
        return "array";
    }

    if(type == CHASH_OBJECT){
        return "object";
    }

    if(type == CHASH_LONG){
        return "long";
    }

    if(type == CHASH_DOUBLE){
        return "double";
    }

    if(type == CHASH_BOOL){
        return "bool";
    }

    return "not exist";
}




cJSON * privateCHash_dumps_json_object(CHashObject * object){
    long size = object->private_size;
    cJSON * element = cJSON_CreateObject();
    for(int i = 0; i < size; i++){
        CHashArray *current  = CHashObject_get_by_index(object, i);
        cJSON *current_json = CHash_dump_to_cJSON(current);
        cJSON_AddItemToObject(element, current->private_key, current_json);
    }
    return element;
}

cJSON * privateCHash_dumps_json_array(CHashArray * array){
    long size = array->private_size;
    cJSON *element = cJSON_CreateArray();
    for(int i = 0; i < size; i++){
        CHashArray *current  = CHashArray_get(array, i);
        cJSON *current_json = CHash_dump_to_cJSON(current);
        cJSON_AddItemToArray(element,current_json);
    }
    return element;
}


cJSON * CHash_dump_to_cJSON(CHash *element){
    int type = element->private_type;
    if(type == CHASH_OBJECT){
        return privateCHash_dumps_json_object(element);
    }
    if(type == CHASH_ARRAY){
        return privateCHash_dumps_json_array(element);
    }
    if(type == CHASH_STRING){
        char *value  = CHash_toString(element);
        return cJSON_CreateString(value);
    }
    if(type == CHASH_DOUBLE){
        return cJSON_CreateNumber(CHash_toDouble(element));
    }

    if(type == CHASH_BOOL){
        return cJSON_CreateBool(CHash_toBool(element));
    }

    if(type == CHASH_LONG){
        long value  = CHash_toLong(element);
        return cJSON_CreateNumber((double)value);
    }


    return cJSON_CreateNull();

}

char * CHash_dump_to_json_string(CHash * element){
    cJSON * created = CHash_dump_to_cJSON(element);
    char * result  = cJSON_Print(created);
    cJSON_Delete(created);
    return result;
}

int  CHash_dumps_to_json_file(CHash *element,const char *filename){
    char *content = CHash_dump_to_json_string(element);
    if(!content){
        return 1;
    }
    privateCHash_write_file(filename,content);
    free(content);
    return 0;

}
CHashArray * privateCHash_load_json_object(cJSON *element){
    int size = cJSON_GetArraySize(element);
    CHashObject *equivalent = newCHashObject(NULL);

    for(int i = 0; i < size; i++){
        cJSON *current = cJSON_GetArrayItem(element,i);
        char *key = current->string;
        CHash * value = CHash_load_from_cJSON(current);
        CHashObject_set(equivalent, key,value);
    }

    return equivalent;

}

CHash  * privateCHash_load_json_array(cJSON *element){
    int size = cJSON_GetArraySize(element);
    CHashObject *equivalent = newCHashArray(NULL);
    for(int i = 0; i < size; i++){
        cJSON *current = cJSON_GetArrayItem(element,i);
        CHash * value = CHash_load_from_cJSON(current);
        CHashArray_append(equivalent,value);
    }
    return equivalent;
}


CHash * CHash_load_from_cJSON(cJSON *element){

    if(!element){
        return newCHashNULL();
    }

    if(element->type == cJSON_Object){
        return privateCHash_load_json_object(element);
    }

    if(element->type == cJSON_Array){
        return privateCHash_load_json_array(element);
    }
    if(cJSON_IsBool(element)){
        bool value = element->valueint;
        return newCHashBool(value);
    }
    if(element->type == cJSON_String){
        return newCHashString(element->valuestring);
    }

    if(element->type == cJSON_Number){
        double value = element->valuedouble;
        long value_long = (long)value;
        double  rest = value - (double)value_long;
        if(rest == 0){
            return newCHashLong(value_long);
        }
        return newCHashDouble(value);
    }
        return newCHashNULL();



}

CHash * CHash_load_from_json_strimg(const char *content){
    cJSON *parsed = cJSON_Parse(content);
    CHash *result =CHash_load_from_cJSON(parsed);
    cJSON_Delete(parsed);
    return result;
}

CHash * CHash_load_from_json_file(const char *filename){
    char *content = privateCHash_read_file(filename);

    CHash *result =  CHash_load_from_json_strimg(content);
    free(content);
    return result;
}








privateCHashError * privatenewCHashError(CHashObject *args, int error_code, const char *error_menssage){
    privateCHashError  *self = (privateCHashError*) malloc(sizeof (privateCHashError));
    self->args = args;
    self->error_code = error_code;

    self->error_mensage =  newCTextStack_string(error_menssage);

    long args_size = CHash_get_size(self->args);
    for(int i = 0; i < args_size; i++){
        CHash *current = CHashObject_get_by_index(self->args,i);
        char *key = CHash_get_key_of_element(current);
        char *value = CHash_dump_to_json_string(current);
        CTextStack * formated_key = newCTextStack_string_empty();
        CTextStack_format(formated_key,"#%s#",key);
        CTextStack_self_replace(self->error_mensage,formated_key->rendered_text,value);
        CTextStack_free(formated_key);
        free(value);
    }

    return self;
}




privateCHashError * privateCHashError_get_error(CHash *self){

    CHash  *first =  privateCHash_get_first_object(self);
    if(first->private_error){
        return (privateCHashError*)first->private_error;
    }
    return NULL;
}


bool Chash_errors(CHash *self){
    
    if(!self){
        return true;
    }

    privateCHashError *error  = privateCHashError_get_error(self);
    if(error){
        return true;
    }
    return false;
}


void CHash_raise_error(CHash *self,int error_code,const char *error_menssage, CHash *args){
    if(Chash_errors(self)){return;}
    CHashArray  *path = CHash_get_path(self);
    
    CHash *formated_args = args;

    if(!args){
        formated_args = newCHashObject(NULL);
    }
    CHashObject_set(formated_args,
         "path",path,
         "value",CHash_copy(self)
    );

    privateCHashError *created = privatenewCHashError(
            formated_args,
            error_code,
            error_menssage
    );
    CHash *first = privateCHash_get_first_object(self);
    first->private_error = (void*)created;

    
}

void privateCHashError_free(privateCHashError *self){
    CTextStack_free(self->error_mensage);
    CHash_free(self->args);
    free(self);
}

char * CHash_get_error_menssage(CHash *self){
    if(!self){
        return NULL;
    }
    if(!Chash_errors(self)){
        return NULL;
    }

    privateCHashError  *error = privateCHashError_get_error(self);

    return error->error_mensage->rendered_text;
}

int CHash_get_error_code(CHash *self){
    if(!Chash_errors(self)){
        return 0;
    }
    privateCHashError  *error = privateCHashError_get_error(self);
    return error->error_code;
}

CHash * CHash_get_error_args(CHash *self){
    if(!Chash_errors(self)){
        return NULL;
    }
    privateCHashError  *error = privateCHashError_get_error(self);
    return error->args;
}


int private_chash_check_type(CHash *element, unsigned short  expected_type,char *expected_type_str){
    if(Chash_errors(element)){
        return 1;
    }

    if(element->private_type != expected_type){
        CHash_raise_error(element,
                          CHASH_WRONG_TYPE,
                          "value: #value# of at #path# its not #type# ",
                          newCHashObject("type", newCHashString(expected_type_str))
                          );
        return 1;
    }
    return 0;
}

int CHash_ensure_double(CHash *element){
    return private_chash_check_type(element,CHASH_DOUBLE,"double");
}

int CHash_ensure_string(CHash *element){
    return private_chash_check_type(element,CHASH_STRING,"string");
}






#endif //LibName




