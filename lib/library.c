#include "library.h"
#include <stdio.h>
#include <stdlib.h>

struct my_str{
    size_t capacity_m;
    size_t size_m;
    char* data;
};

int my_str_create(my_str* str, size_t buf_size) {
    str->capacity_m = buf_size * 2;
    str->size_m = buf_size;
    str->data = (char *) malloc(buf_size * 2 + 1);
    if (str->data)
        return 0;
    else
        return -2;
}

int my_str_getc(const my_str* str, size_t index){
    return *(str->data+index);
}

int my_str_resize(my_str* str, size_t new_size, char sym) {
    char *newMemory = realloc(str->data, new_size);

    if (newMemory) {
        str->data = newMemory;
        for (int i = str->capacity_m; i < new_size; i++) {
            *(str->data + i) = sym;
        }
        str->capacity_m = new_size;
        return 0;
    } else {
        return -2;
    }
}

size_t my_str_find_c(const my_str* str, char tofind, size_t from){
    if(from >= str->size_m) {
        for (size_t i = from; i < str->size_m; i++) {
            if (str->data[i] == tofind) {
                return i;
            }
        }
    }
    return (size_t)(-1);
}

void hello(void) {
    printf("Hello, World!\n");
}