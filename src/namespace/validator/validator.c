

CHashValidatorModule newCHashValidatorModule(){
    CHashValidatorModule self = {0};
    self.raise_error = CHash_raise_error;


    self.ensure_Number = CHash_ensure_Number;
    self.ensure_Number_by_key = CHash_ensure_Number_by_key;
    self.ensure_Number_by_index = CHash_ensure_Number_by_index;

    self.ensure_min = CHash_ensure_min;
    self.ensure_min_by_key = CHash_ensure_min_by_key;
    self.ensure_min_by_index = CHash_ensure_min_by_index;

    self.ensure_max = CHash_ensure_max;
    self.ensure_max_by_key =CHash_ensure_max_by_key;
    self.ensure_min_by_index =CHash_ensure_max_by_index;



    self.ensure_Bool = CHash_ensure_Bool;
    self.ensure_Bool_by_key = CHash_ensure_Bool_by_key;
    self.ensure_Bool_by_index = CHash_ensure_Bool_by_index;

    self.ensure_String = CHash_ensure_String;
    self.ensure_String_by_key = CHash_ensure_String_by_key;
    self.ensure_String_by_index = CHash_ensure_String_by_index;

    self.ensure_Object = CHash_ensure_Object;
    self.ensure_Object_by_key = CHash_ensure_Object_by_key;
    self.ensure_Object_by_index = CHash_ensure_Object_by_index;

    self.ensure_Array = CHash_ensure_Array;
    self.ensure_Array_by_key = CHash_ensure_Array_by_key;
    self.ensure_Array_by_index = CHash_ensure_Array_by_index;

    return self;
}