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

size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from){
    int foundChars = 0;
    size_t strIndx = 0;
    size_t tofindIndx = 0;
    size_t startIndx = -1;

    while (foundChars != tofind->size_m || strIndx == str->size_m) {

        if (str->data[strIndx] == tofind->data[tofindIndx]) {
            if (str->data[strIndx] == tofind->data[0]) {
                startIndx = strIndx;
            }
            foundChars++;
            tofindIndx++;
            strIndx++;
        }

        else {
            startIndx = -1
            strIndx++;
            foundChars = 0;
            tofindIndx = 0;
        }
    }
}