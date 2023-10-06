
int private_chash_check_type(CHash *element, unsigned short  expected_type);

int CHash_ensure_Number(CHash *element);
int CHash_ensure_Number_by_key(CHash *object, const char *key);
int CHash_ensure_Number_by_index(CHash *array, long index);

int CHash_ensure_min(CHash *element, double  min);
int CHash_ensure_min_by_key(CHash *object, const char *key, double min );
int CHash_ensure_min_by_index(CHash *array, long index, double min);


int CHash_ensure_max(CHash *element, double  max);
int CHash_ensure_max_by_key(CHash *object, const char *key, double  max);
int CHash_ensure_max_by_index(CHash *array, long index, double  max);




int CHash_ensure_Bool(CHash *element);
int CHash_ensure_Bool_by_key(CHash *object , const char *key);
int CHash_ensure_Bool_by_index(CHash *array , long index);

int CHash_ensure_String(CHash *element);
int CHash_ensure_String_by_key(CHash *object , const char *key);
int CHash_ensure_String_by_index(CHash *array , long index);

int CHash_ensure_Object(CHash *element);
int CHash_ensure_Object_by_key(CHash *object , const char *key);
int CHash_ensure_Object_by_index(CHash *array , long index);

int CHash_ensure_only_keys(CHashObject *object, CHashStringArray *keys);
int CHash_ensure_only_keys_cleaning_args(CHashObject *object, CHashStringArray *keys);


int CHash_ensure_Array(CHash *element);
int CHash_ensure_Array_by_key(CHash *object , const char *key);
int CHash_ensure_Array_by_index(CHash *array , long index);



int privateCHash_ensureArrayOrObject(CHash *element);
