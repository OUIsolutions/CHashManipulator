//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.typesH.h"
//silver_chain_scope_end


char * CHash_toString(CHashArray *element);

CTextStack  *CHashtoStack(CHash *element);

CHash * newCHashStackString(CTextStack *element);

CHash * newCHashString(const char *value);

void CHash_set_String(CHash *self, const char *value);

void CHash_set_Stack(CHash *self,CTextStack *element);


