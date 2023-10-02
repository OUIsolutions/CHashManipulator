
int private_chash_check_type(CHash *element, unsigned short  expected_type);

int CHash_ensure_Double(CHash *element);

int CHash_ensure_Long(CHash *element);
int CHash_ensure_Bool(CHash *element);

int CHash_ensure_String(CHash *element);

int CHash_ensure_Object(CHash *element);

int CHash_ensure_Array(CHash *element);

int privateCHash_ensureArrayOrObject(CHash *element);
