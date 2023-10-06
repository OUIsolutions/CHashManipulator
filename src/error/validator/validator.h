
int private_chash_check_type(CHash *element, unsigned short  expected_type);

int CHash_ensure_Double(CHash *element);
int CHash_ensure_Double_by_key(CHash *object,const char *key);
int CHash_ensure_Double_by_index(CHash *array,long index);

int CHash_ensure_minDouble(CHash *element,double  min);
int CHash_ensure_minDouble_by_key(CHash *object,const char *key,double min );
int CHash_ensure_minDouble_by_index(CHash *array,long index,double max);


int CHash_ensure_maxDouble(CHash *element,double  max);
int CHash_ensure_maxDouble_by_key(CHash *object,const char *key, double  max);
int CHash_ensure_maxDouble_by_index(CHash *array,long index,double  max);


int CHash_ensure_Long(CHash *element);
int CHash_ensure_long_by_key(CHash *object , const char *key);
int CHash_ensure_long_by_index(CHash *array , long index);

int CHash_ensure_minLong(CHash *element,long min);
int CHash_ensure_minLong_by_key(CHash *object,const char *key, long min);
int CHash_ensure_minLong_by_index(CHash *array,long  index, long min);



int CHash_ensure_Bool(CHash *element);
int CHash_ensure_Bool_by_key(CHash *object , const char *key);
int CHash_ensure_Bool_by_index(CHash *array , long index);

int CHash_ensure_String(CHash *element);
int CHash_ensure_String_by_key(CHash *object , const char *key);
int CHash_ensure_String_by_index(CHash *array , long index);

int CHash_ensure_Object(CHash *element);
int CHash_ensure_Object_by_key(CHash *object , const char *key);
int CHash_ensure_Object_by_index(CHash *array , long index);

int CHash_ensure_Array(CHash *element);
int CHash_ensure_Array_by_key(CHash *object , const char *key);
int CHash_ensure_Array_by_index(CHash *array , long index);

int privateCHash_ensureArrayOrObject(CHash *element);
