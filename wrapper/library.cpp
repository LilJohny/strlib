#include "library.h"

#include <iostream>

class MyString {
private:
    my_str my_string;
    size_t capacity;

    void update_sizes() {
        this->size = my_string.size_m;
        this->capacity = my_string.capacity_m;
    }

public:
    size_t size;

    explicit MyString(size_t size) {
        my_str_create(&my_string, size);
        this->update_sizes();
    }

    char operator[](size_t i) {
        return (char) my_str_getc(&my_string, i);
    }

    int shrink_to_fit() {
        int result = my_str_shrink_to_fit(&my_string);
        this->update_sizes();
        return result;
    }

    size_t find_character(char character, size_t from) {
        size_t result = my_str_find_c(&my_string, character, from);
        return result;
    }

    int empty() {
        int result = my_str_empty(&my_string);
        this->update_sizes();
        return result;
    }

    size_t get_capacity() {
        return this->capacity;
    }

    size_t get_size() {
        return this->size;
    }

    int push_back(char character) {
        int result = my_str_pushback(&my_string, character);
        update_sizes();
        return result;
    }

    void free() {
        my_str_free(&my_string);
    }

    int pop_back() {
        int result = my_str_popback(&my_string);
        update_sizes();
        return result;
    }

    int copy(MyString another) {
        int result = my_str_copy(&my_string, &another.my_string, 0);
        if (result) {
            another.size = this->size;
        }
        return result;
    }

    void clear() {
        my_str_clear(&my_string);
        update_sizes();
    }

    int write_to_file(FILE *file) {
        int result = my_str_write_file(&my_string, file);
        return result;
    }

    int write() {
        int result = my_str_write(&my_string, stdin);
        return result;
    }

    int resize(size_t new_size, char character) {
        int result = my_str_resize(&my_string, new_size, character);
        update_sizes();
        return result;
    }

    int append_cstr(const char *str) {
        int result = my_str_append_cstr(&my_string, str);
        update_sizes();
        return result;
    }

    int reserve(size_t buf_size) {
        int result = my_str_reserve(&my_string, buf_size);
        update_sizes();
        return result;
    }

    int insert_character(char character, size_t pos) {
        int result = my_str_insert_c(&my_string, character, pos);
        update_sizes();
        return result;
    }

    int substring(MyString to, size_t beg, size_t end) {
        int result = my_str_substr(&my_string, &to.my_string, beg, end);
        if (result) {
            to.size = end - beg;
        }
        return result;
    }

    int read() {
        int result = my_str_read(&my_string);
        update_sizes();
        return result;
    }

    int read_file_delim(FILE *file, char delim) {
        int result = my_str_read_file_delim(&my_string, file, delim);
        if (result) {
            update_sizes();
        }
        return result;
    }

    int read_file(FILE *file) {
        int result = my_str_read_file(&my_string, file);
        return result;
    }

    explicit operator const char *() {
        const char *str = my_str_get_cstr(&my_string);
        return str;
    }

    int append(MyString from) {
        int result = my_str_append(&my_string, &(from.my_string));
        if (result) {
            update_sizes();
        }
        return result;
    }

    int substr_cstr(char *to, size_t beg, size_t end) {
        int result = my_str_substr_cstr(&my_string, to, beg, end);
        return result;
    }
    size_t find( MyString tofind, size_t from) {
        return my_str_find(&my_string, &tofind.my_string, from);
    }
    bool operator==(MyString str2){
        return my_str_cmp(&my_string, &str2.my_string) == 0;
    }
    bool operator>(MyString str2){
        return my_str_cmp(&my_string, &str2.my_string) == 1;
    }
    bool operator<(MyString str2){
        return my_str_cmp(&my_string, &str2.my_string) == -1;
    }
    bool operator==(const char* str2){
        return my_str_cmp_cstr(&my_string, str2) == 0;
    }
    bool operator>(const char * str2){
        return my_str_cmp_cstr(&my_string, str2) == 1;
    }
    bool operator<(char * str2){
        return my_str_cmp_cstr(&my_string, str2) == -1;
    }

};

