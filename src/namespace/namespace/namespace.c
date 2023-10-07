

CHashNamespace newCHashNamespace(){
    CHashNamespace self = {0};

    self.load_from_cJSON = CHash_load_from_cJSON;
    self.load_from_json_strimg  = CHash_load_from_json_strimg;
    self.load_from_json_file = CHash_load_from_json_file;

    self.dump_to_cJSON = CHash_dump_to_cJSON;
    self.dump_to_json_string = CHash_dump_to_json_string;
    self.dump_to_json_file = CHash_dump_to_json_file;
    
    self.newBool = newCHashBool;
    self.toBool = CHash_toBool;

    self.newNumber = newCHashNumber;
    self.toNumber = CHash_toNumber;

    self.newStackString = newCHashStackString;
    self.toStack = CHashtoStack;

    self.newString = newCHashString;
    self.toString = CHash_toString;
    self.newNULL = newCHashNULL;

    self.print = CHash_print;
    self.get_path = CHash_get_path;
    self.copy = CHash_copy;
    self.equals  = CHash_equals;
    self.get_size = CHash_get_size;


    self.errors = Chash_errors;
    self.get_error_code = CHash_get_error_code;
    self.get_error_args = CHash_get_error_args;
    self.get_error_menssage= CHash_get_error_menssage;

    self.get_type = CHash_get_type;

    self.free = CHash_free;

    self.object = newCHashObjectModule();
    self.array = newCHashArrayModule();
    self.validator = newCHashValidatorModule();
    return self;
}