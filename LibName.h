/*
MIT License

Copyright (c) 2023 LibName

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef LibName
#define LibName

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>




double add(double a, double b);

double sub(double a, double b);

double mull(double a, double b);

double div_number(double a, double b);



bool are_strings_equal(const char *a, const char *b);


char * join_strings(const char *a, const char *b);





void write_file(const char *path, const char *content);

char *read_file(const char *fileName);






double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

double mull(double a, double b){
    return a *b;
}

double div_number(double a, double b){
    return a /b;
}






bool are_strings_equal(const char *a, const char *b){
    return strcmp(a,b) == 0;
}


char * join_strings(const char *a, const char *b){
    long new_size  = strlen(a) + strlen(b) +1;
    char *result = calloc( sizeof(char),new_size);
    sprintf(result,"%s%s",a,b);
    return result;
}





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


#endif //LibName




