#include "library.h"
#include <stdio.h>
#include <stdlib.h>

struct my_str{
    size_t capacity_m;
    size_t size_m;
    char* data;
};
/* added */
int my_str_getc(const my_str* str, size_t index){
    return *(str->data+index);
}

/* added */
int my_str_resize(my_str* str, size_t new_size, char sym){
    char* newMemory = realloc(str->data, new_size);

    if (newMemory) {
        str->data = newMemory;
        for (int i = str->capacity_m; i < new_size; i++){
            *(str->data+i) = sym;
        }
        str->capacity_m = new_size;
        return 0;
    }
    else {
        return -2;
    }
}