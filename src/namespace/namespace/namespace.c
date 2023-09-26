

CHashNamespace newCHashNamespace(){
    CHashNamespace self = {0};

    self.newBool = newCHashBool;
    self.toBool = CHash_toBool;

    self.newDouble = newCHashDouble;
    self.toDouble = CHash_toDouble;

    self.newLong = newCHashLong;
    self.toLong = CHash_toLong;

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
    self.raise_error = CHash_raise_error;
    
    self.free = CHash_free;

    self.object = newCHashObjectModule();
    self.array = newCHashArrayModule();
    return self;
}