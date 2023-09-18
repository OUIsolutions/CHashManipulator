
cJSON * privateCHash_dumps_json_object(CHashObject *object);

cJSON * privateCHash_dumps_json_array(CHashArray *object);

cJSON * CHash_dump_to_cJSON(CHash *element);


char * CHash_dump_to_json_string(CHash * element);

int  CHash_dump_to_json_file(CHash *element,const char *filename);

CHash * CHash_load_from_cJSON(cJSON *element);

CHash * CHash_load_from_json_strimg(cJSON *element);

CHash * CHash_load_from_json_file(cJSON *element,const char *filename);




