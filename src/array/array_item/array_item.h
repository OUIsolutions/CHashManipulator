
typedef CHashAny CHashArrayItem;

typedef struct privateCHashArrayItem{
    long position;
    char *key;
    CHashAny *value;

}privateCHashArrayItem;

privateCHashArrayItem * privateCHashArrayItem_new(long position);

