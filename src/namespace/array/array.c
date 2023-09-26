

CHashArrayModule newCHashArrayModule(){
    CHashArrayModule self = {0};
    self.newArrayEmpty = newCHashArrayEmpty;
    self.append_once = CHashArray_append_once;
    self.delete = CHashArray_delete;
    self.get = CHashArray_get;
    return self;
}