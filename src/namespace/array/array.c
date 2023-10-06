

CHashArrayModule newCHashArrayModule(){
    CHashArrayModule self = {0};
    self.newArrayEmpty = newCHashArrayEmpty;
    self.append_once = CHashArray_append_once;
    self.set = CHashArray_set;
    self.remove = CHashArray_remove;
    self.get = CHashArray_get;
    self.find = CHashArray_find;
    self.find_cleanning_element =CHashArray_find_cleanning_element;
    
    self.get_type = CHashArray_get_type;
    self.getArray = CHashArray_getArray;
    self.getObject = CHashArray_getObject;
    self.getString = CHashArray_getString;
    self.getNumber = CHashArray_getNumber;
    self.getBool = CHashArray_getBool;
    return self;
}