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
    str->data = (char *) malloc(buf_size*2);
    if (str->data)
        return 0;
    else
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

