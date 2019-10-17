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
    char *memory = (char *) malloc(buf_size * 2 + 1);
    if (memory) {
        str->data = memory;
        return 0;
    } else
        return -2;
}

int my_str_getc(const my_str* str, size_t index){
    return *(str->data[index]);
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

size_t my_str_find_c(const my_str* str, char tofind, size_t from) {
    if (from >= str->size_m) {
        for (size_t i = from; i < str->size_m; i++) {
            if (str->data[i] == tofind) {
                return i;
            }
        }
    }
    return (size_t)(-1);
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
        *(str->data + index) = c;
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
    *(str->data + str->size_m) = c;
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
    return *(str->data + str->size_m - 1);
}

int my_str_copy(const my_str* from,  my_str* to, int reserve) {
    if (from == NULL) {
        return -1;
    }
    if (my_str_empty(from)) {
        return -2;
    }
    size_t from_len = from->size_m;
    my_str_create(to, from_len);
    if (!reserve) {
        my_str_shrink_to_fit(to);
    }
    for (int i = 0; i < from_len; i++) {
        *(to->data + i) = *(from->data + i);
    }
    return 0;
}

void my_str_clear(my_str *str) {
    str->size_m = 0;
}

int my_str_write_file(const my_str *str, FILE *file) {
    for (int i = 0; i < str->size_m; ++i) {
        int result = fprintf(file,"%c", str->data[i]);
        if (result != 1) {
            return result;
        }
    }
    return 0;
}

int my_str_write(const my_str *str, FILE *file) {
    for (int i = 0; i < str->size_m; ++i) {
        int result = printf("%c", (str->data[i]));
        if (result != 1) {
            return result;
        }
    }
    return 0;
}

void *my_realloc(void *ptr, size_t oldLength, size_t newLength) {
    if (newLength == 0) {
        free(ptr);
        return NULL;
    } else if (!ptr) {
        return malloc(newLength);
    } else if (newLength > oldLength) {
        void *ptrNew = malloc(newLength);
        if (ptrNew) {
            memcpy(ptrNew, ptr, oldLength);
            free(ptr);
        }
        return ptrNew;
    } else {
        return ptr;
    }
}

int my_str_resize(my_str *str, size_t new_size, char sym) {//TODO check exceptions
    char *newMemory = my_realloc(str->data, str->capacity_m, new_size);

    if (newMemory) {
        str->data = newMemory;
        for (size_t i = str->capacity_m; i < new_size; i++) {
            *(str->data + i) = sym;
        }
        str->capacity_m = new_size;
        return 0;
    } else {
        return -2;
    }
}

int my_str_append_cstr(my_str *str, const char *from) {
    int fromLength = sizeof(from) / sizeof(*from);
    int startPoint = str->size_m;
    if (str->size_m + fromLength >= str->capacity_m) {
        int result = my_str_resize(str, str->size_m + fromLength, ' ');
        if (result != 0) {
            return result;
        }
    }
    int j = 0;
    for (size_t i = startPoint; i < str->size_m + fromLength; ++i) {
        str->data[j] = from[j];
        j++;
    }
    return 0;

}

int my_str_insert_c(my_str* str, char c, size_t pos){
    size_t needed_capacity = str->size_m > pos ? str->size_m : pos;
    if (pos <= str->size_m) {
        my_str_reserve(str, needed_capacity * 2);
    } else {
        my_str_resize(str, needed_capacity * 2, c);
        return 0;
    }
    while (pos <= str->size_m) {
        if (pos <= str->size_m ){
            char next = *(str->data + pos);
        }
        *(str->data + pos) = c;
        c = next;
        pos++;
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

int my_str_read(my_str *str) {
    char sym = '\0';
    int i = 0;
    while (sym != '\n') {
        sym = (char) getchar();
        if (str->size_m == str->capacity_m) {
            my_str_resize(str, str->capacity_m * 2, '\0');
        }
        str->data[i] = sym;
        i++;
    }
    return 0;
}

int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size){
    size_t cstr_len = sizeof(cstr);
    if (buf_size == 0) {
        int created = my_str_reserve(str, buf_size);
        if (created == -2) {
            return -2;
        }
    }
    if (0 < buf_size && buf_size < cstr_len) {
        return -1;
    }
    for (int i = 0; i < cstr_len; i++) {
        str->data[i] = cstr[i];
    }
    return 0;
}

//int my_str_append(my_str* str, const my_str* from){
//    if (my_str_capacity(str) >= my_str_size(from) + my_str_size(str)){
//        for(int i = 0; i < my_str_size(from); i++){
//            *(str->data + my_str_size(str) + i) = *(from->data + i);
//        }
//    } else{
//        return -1;
//    }
//}
int my_str_read_file(my_str* str, FILE* file){
    char sym = '\0';
    int i = 0;
    while (sym != '\n') {
        sym = (char)fgetc(file);
        if (str->size_m == str->capacity_m) {
            my_str_resize(str, str->capacity_m * 2, '\0');
        }
        str->data[i] = sym;
        i++;
    }
    if(!ferror(file)) {
        return 0;
    } else {
        return -1;
    }
}

const char* my_str_get_cstr(my_str* str) {
    char *c_str = str->data;
    return c_str;
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