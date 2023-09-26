

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

    self.object = newCHashObjectModule();
    self.array = newCHashArrayModule();
    return self;
}