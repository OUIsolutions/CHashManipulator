
typedef CHashAny CHashArrayItem;

typedef struct privateCHashArrayItem{

    void *father;
    long position;
    CHashAny *value;

}privateCHashArrayItem;

