#include "library.h"
#include <stdio.h>
#include <stdlib.h>

struct my_str{
    size_t capacity_m;
    size_t size_m;
    char* data;
};

int my_str_create(my_str* str, size_t buf_size){
    str->data = (char *) malloc(buf_size);
    if (str->data)
        return 0;
    else
        return -2;
}

void hello(void) {
    printf("Hello, World!\n");
}