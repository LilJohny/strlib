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

int my_str_empty(const my_str* str){
    return str->size_m == 0;
}

size_t my_str_capacity(const my_str* str){
    return str->capacity_m;
}

size_t my_str_size(const my_str* str){
    return str->size_m;
}

int my_str_putc(my_str* str, size_t index, char c){
    if (str->size_m >= index){
        return -1;
    } else{
        str->*(data + index) = c;
        return 0;
    }
}

int my_str_pushback(my_str* str, char c){
    if (str == NULL){
        return -1;
    }
    if (str->capacity_m == str->size_m){
        return -2;
    }
    str->*(data + str->size_m) = c;
    return 0;
}

void hello(void) {
    printf("Hello, World!\n");
}