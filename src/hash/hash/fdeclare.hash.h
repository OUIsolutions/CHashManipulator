//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesH.h"
//silver_chain_scope_end


CHash * privatenewChash_raw();



void CHash_print(CHash *self);

CHashArray * CHash_get_path(CHash *self);


CHash * CHash_copy(CHash *self);

CHash * privateCHash_copy_if_its_an_reference(CHash *self);

void CHash_free(CHash *self);

void CHash_set(CHash *self,CHash *element);

void privateCHash_free_values(CHash *self);

bool CHash_equals(CHash *element1, CHash *element2);

long CHash_get_size(CHash *self);


CHash * privateCHash_get_first_object(CHash *self);

CHash * newCHashNULL();