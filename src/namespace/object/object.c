

CHashObjectModule newCHashObjectModule(){
    CHashObjectModule self = {0};
    self.newObjectEmpty = newCHashObjectEmpty;
    self.set_once = CHashObject_set_once;
    self.delete= CHashObject_delete;

    self.get_keys = CHashObject_get_keys;
    self.get_by_index  = CHashObject_get_by_index;
    self.get_key_of_element = CHashObject_get_key_of_element;

    self.get_type = CHashObject_get_type;
    self.get = CHashObject_get;
    self.getArray = CHashObject_getArray;
    self.getObject = CHashObject_getObject;
    self.getLong = CHashObject_getLong;
    self.getBool = CHashObject_getBool;
    self.getDouble = CHashObject_getDouble;
    self.getString = CHashObject_getString;

    return self;
}