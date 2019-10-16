#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct my_str {
    size_t capacity_m;
    size_t size_m;
    char *data;
};

int my_str_create(my_str *str, size_t buf_size) {
    str->capacity_m = buf_size * 2;
    str->size_m = buf_size;
    char *memory = (char *) malloc(buf_size * 2);
    if (memory) {
        str->data = memory;
        return 0;
    } else
        return -2;
}

void my_str_clear(my_str *str) {
    str->size_m = 0;
}

void my_str_free(my_str *str) {
    str->size_m = 0;
    str->capacity_m = 0;
    free(str->data);
}

int my_str_shrink_to_fit(my_str *str) {
    char *memory = realloc(str->data, str->size_m);
    if (memory) {
        str->data = memory;
        str->capacity_m = str->size_m;
        return 0;
    } else {
        return -2;
    }
}

int my_str_write_file(const my_str *str, FILE *file) {
    for (int i = 0; i < str->size_m; ++i) {
        int result = fprintf(file, (const char *) (str->data + i));
        if (result != 1) {
            return result;
        }
    }
    return 0;
}

int my_str_copy(const my_str *from, my_str *to, int reserve) {
    if (from == NULL) {
        return -1;
    }
    if (my_str_empty(from)) {
        return -2;
    }
    size_t from_len = from->size_m;
    if (reserve) {
        my_str_create(to, from_len);
    } else {
        my_str_create(to, from_len / 2);
    }
    for (size_t i = 0; i < from_len; i++) {
        *(to->data + i) = *(from->data + i);
    }
    return 0;
}


int my_str_write(const my_str *str, FILE *file) {
    for (int i = 0; i < str->size_m; ++i) {
        int result = printf((const char *) (str->data + i));
        if (result != 1) {
            return result;
        }
    }
    return 0;
}

void *my_realloc(void *ptr, size_t oldLength, size_t newLength){
    if (newLength == 0){
        free(ptr);
        return NULL;
    } else if (! ptr){
        return malloc(newLength);
    } else if (newLength > oldLength ){
        void * ptrNew = malloc(newLength);
        if (ptrNew){
            memcpy(ptrNew, ptr, oldLength);
            free(ptr);
        }
        return ptrNew;
    } else{
        return ptr;
    }
}



int my_str_resize(my_str* str, size_t new_size, char sym) {
    char *newMemory = my_realloc(str->data, str->capacity_m, new_size);

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

int my_str_substr(const my_str *from, my_str *to, size_t beg, size_t end) {
    if (beg > from->size_m) {
        return -1;
    }
    if (end > from->size_m) {
        end = from->size_m;
    }
    
    int j = 0;
    for (size_t i = 0; i < end; ++i) {
        *(to->data + j) = *(from->data + i);
        j += 1;
    }
    return 0;
}