

CHashObjectModule newCHashObjectModule(){
    CHashObjectModule self = {0};
    self.newObjectEmpty = newCHashObjectEmpty;
    self.set_once = CHashObject_set_once;
    self.set_default = CHashObject_set_default;
    self.remove= CHashObject_remove;

    self.get_key_by_index = CHashObject_get_key_by_index;
    self.get_key_of_element = CHashObject_get_key_of_element;
    self.exist = CHashObject_exist;
    self.get_type = CHashObject_get_type;
    self.get = CHashObject_get;
    self.getArray = CHashObject_getArray;
    self.getObject = CHashObject_getObject;
    self.getBool = CHashObject_getBool;
    self.getBool_converting = CHashObject_getBool_converting;
    self.getNumber = CHashObject_getNumber;
    self.getNumber_converting = CHashObject_getNumber_converting;
    self.getString = CHashObject_getString;
    self.getStack = CHashObject_getStack;

    return self;
}