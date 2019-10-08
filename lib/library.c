#include "library.h"
#include <stdio.h>
#include <stdlib.h>

struct string{
    size_t capacity_m;
    size_t size_m;
    char* data;
};

int my_str_create(string* str, size_t buf_size){
    str->data = (char *) malloc(15);
    return 0;
}

void hello(void) {
    printf("Hello, World!\n");
}