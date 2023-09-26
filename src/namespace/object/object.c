

CHashObjectModule newCHashObjectModule(){
    CHashObjectModule self = {0};
    self.newObjectEmpty = newCHashObjectEmpty;
    self.set_once = CHashObject_set_once;
    self.delete= CHashObject_delete;

    self.get_keys = CHashObject_get_keys;
    self.get_by_index  = CHashObject_get_by_index;
    self.get_key_of_element = CHashObject_get_key_of_element;
    self.get = CHashObject_get;
    return self;
}