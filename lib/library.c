#include "library.h"
#include <stdio.h>
#include <stdlib.h>

struct my_str{
    size_t capacity_m;
    size_t size_m;
    char* data;
};

int my_str_create(my_str* str, size_t buf_size){
    str->capacity_m = buf_size * 2;
    str->size_m = buf_size;
    char* memory = (char *) malloc(buf_size*2);
    if (memory){
        str->data = memory;
        return 0;
    } else
        return -2;
}
void my_str_clear(my_str* str){
    str->size_m = 0;
}

void my_str_free(my_str* str){
    str->size_m = 0;
    str->capacity_m = 0;
    free(str->data);
}

int my_str_shrink_to_fit(my_str* str){
    char * memory = realloc(str->data, str->size_m);
    if (memory){
        str->data = memory;
        str->capacity_m = str->size_m;
        return 0;
    } else {
        return -2;
    }
}
int my_str_write_file(const my_str* str, FILE* file){
    for (int i = 0; i < str->size_m; ++i) {
        int result = fprintf(file, (const char *) (str->data + i));
        if(result!=1){
            return result;
        }
    }
    return 0;

int my_str_copy(const my_str* from,  my_str* to, int reserve){
    if (from == NULL){
        return -1;
    }
    if (my_str_empty(from)){
        return -2;
    }
    size_t from_len = from->size_m;
    if (reserve){
        my_str_create(to, from_len, from_len*2);
    } else{
        my_str_create(to, from_len, from_len);
    }
    for(int i = 0; i < from_len; i++){
        to->*(data + i) = from->*(data + i);
    }
    return 0;
}

void hello(void) {
    printf("Hello, World!\n");
}
int my_str_write(const my_str* str, FILE* file){
    for (int i = 0; i < str->size_m; ++i) {
        int result = printf( (const char *) (str->data + i));
        if(result!=1){
            return result;
        }
    }
    return 0;
}