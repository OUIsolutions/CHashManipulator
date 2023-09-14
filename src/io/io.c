

void write_file(const char *path, const char *content){

        FILE *file = fopen(path, "w");
        if(!file){
            return;
        }
        fprintf(file,"%s",content);
        fclose(file);
}

char *read_file(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    
    if (file == NULL) {
        perror("Error opening the file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *content = (char *)malloc(size + 1);
    if (content == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return NULL;
    }
    
    size_t bytesRead = fread(content, 1, size, file);
    if (bytesRead != size) {
        perror("Error reading the file");
        free(content);
        fclose(file);
        return NULL;
    }
    
    content[size] = '\0'; // Add null terminator
    
    fclose(file);
    return content;
}