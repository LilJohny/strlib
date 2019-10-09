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
    if(str->size_m == 0)
        return 1;
    return 0;
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

void my_str_free(my_str* str){
    str->size_m = 0;
    str->capacity_m = 0;
    free(str->data);
}

int my_str_popback(my_str* str){
    if (str == NULL){
        return -1;
    }
    if (str->capacity_m == 0){
        return -2;
    }
    return *(str->data+str->size_m-1)
}

//int my_str_copy(const my_str* from,  my_str* to, int reserve){
//    if (from == NULL){
//        return -1;
//    }
//    if my_str_empty(from){
//        return -2;
//    }
//
//}

void hello(void) {
    printf("Hello, World!\n");
}