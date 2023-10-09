

CHashArrayModule newCHashArrayModule(){
    CHashArrayModule self = {0};
    self.newArrayEmpty = newCHashArrayEmpty;
    self.append_once = CHashArray_append_once;
    self.set = CHashArray_set;
    self.remove = CHashArray_remove;
    self.get = CHashArray_get;
    self.foreach = CHashArray_foreach;
    self.foreach_with_args = CHashArray_foreach_with_args;

    //self.map = CHashArray_map;
    //self.map_with_args = CHashArray_map_with_args;

    self.find = CHashArray_find;
    self.find_Number =CHashArray_find_Number;
    self.find_Bool = CHashArray_find_Bool;
    self.find_String = CHashArray_find_String;

    self.get_type = CHashArray_get_type;
    self.getArray = CHashArray_getArray;
    self.getObject = CHashArray_getObject;
    self.getString = CHashArray_getString;
    self.getStack  = CHashArray_getStack;
    self.getNumber = CHashArray_getNumber;
    self.getBool = CHashArray_getBool;
    return self;
}