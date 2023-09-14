
typedef CHashAny CHashArrayItem;

typedef struct privateCHashArrayItem{
    long position;
    CHashAny *value;

}privateCHashArrayItem;

privateCHashArrayItem * privateCHashArrayItem_new(long position);
