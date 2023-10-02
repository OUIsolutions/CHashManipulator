

CHashArrayModule newCHashArrayModule(){
    CHashArrayModule self = {0};
    self.newArrayEmpty = newCHashArrayEmpty;
    self.append_once = CHashArray_append_once;
    self.set = CHashArray_set;
    self.remove = CHashArray_remove;
    self.get = CHashArray_get;

    self.get_type = CHashArray_get_type;
    self.getArray = CHashArray_getArray;
    self.getObject = CHashArray_getObject;
    self.getString = CHashArray_getString;
    self.getDouble = CHashArray_getDouble;
    self.getLong = CHashArray_getLong;
    self.getBool = CHashArray_getBool;
    return self;
}