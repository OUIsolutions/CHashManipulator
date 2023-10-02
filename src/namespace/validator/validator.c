

CHashValidatorModule newCHashValidatorModule(){
    CHashValidatorModule self = {0};
    self.raise_error = CHash_raise_error;

    self.ensure_Array = CHash_ensure_Array;
    self.ensure_Object = CHash_ensure_Object;
    self.ensure_Bool = CHash_ensure_Bool;
    self.ensure_Long = CHash_ensure_Long;
    self.ensure_Double = CHash_ensure_Double;
    self.ensure_String = CHash_ensure_String;
    return self;
}