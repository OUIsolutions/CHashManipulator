
cJSON * privateCHash_dumps_json_object(CHashObject *object);

cJSON * privateCHash_dumps_json_array(CHashArray *object);

cJSON * CHash_dumps_to_cJSON(CHash *element);


char * CHash_dumps_to_json_string(CHash * element);

int  CHash_dumps_to_json_file(CHash *element,const char *filename);

