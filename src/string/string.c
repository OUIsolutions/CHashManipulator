



bool are_strings_equal(const char *a, const char *b){
    return strcmp(a,b) == 0;
}


char * join_strings(const char *a, const char *b){
    long new_size  = strlen(a) + strlen(b) +1;
    char *result = calloc( sizeof(char),new_size);
    sprintf(result,"%s%s",a,b);
    return result;
}

