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

        if (*(str->data+strIndx) == *(tofind->data+tofindIndx)) {
            if (*(str->data+strIndx) == *(tofind->data+0)) {
                startIndx = strIndx;
            }
            foundChars++;
            tofindIndx++;
            strIndx++;
        }

        else {
            startIndx = -1;
            strIndx++;
            foundChars = 0;
            tofindIndx = 0;
        }
    }
    return startIndx;
}
//! Порівняти стрічки, повернути 0, якщо рівні (за вмістом!)
//! -1 (або інше від'ємне значення), якщо перша менша,
//! 1 (або інше додатне значення) -- якщо друга.
//! Поведінка має бути такою ж, як в strcmp.
int my_str_cmp(const my_str* str1, const my_str* str2) {

    size_t indx = 0;
    size_t smallerLen;

    if (str1->size_m < str2->size_m) { smallerLen = str1->size_m; }
    else { smallerLen = str2->size_m; }

    while (indx < smallerLen) {
        if (*(str1->data+indx) < *(str2->data+indx)) { return -1; }
        else if (*(str1->data+indx) > *(str2->data+indx)) { return 1; }
        else { indx++; }
    }

    if (str1->size_m < str2->size_m) { return -1;}
    else if (str1->size_m > str2->size_m) { return 1; }
    else { return 0; }
}