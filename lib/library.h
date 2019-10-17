#ifndef STRLIB_LIBRARY_H
#define STRLIB_LIBRARY_H
#include <stddef.h>
#include <bits/types/FILE.h>
typedef struct
{
    size_t capacity_m; // Розмір блока
    size_t size_m;	   // Фактичний розмір стрічки
    char*  data;	   // Вказівник на блок пам'яті
} my_str;
//int my_str_read_file_delim(my_str* str, FILE* file, char delimiter);
//int my_str_write(const my_str* str, FILE* file);
//int my_str_write_file(const my_str* str, FILE* file);
//int my_str_read(my_str* str);
//int my_str_read_file(my_str* str, FILE* file);
//size_t my_str_find_if(const my_str* str, int (*predicat)(int));
size_t my_str_find_c(const my_str* str, char tofind, size_t from);
//int my_str_cmp_cstr(const my_str* str1, const char* cstr2);
//int my_str_cmp(const my_str* str1, const my_str* str2);
//size_t my_str_find(const my_str* str, const my_str* tofind, size_t from);
int my_str_resize(my_str* str, size_t new_size, char sym); // Done
//int my_str_shrink_to_fit(my_str* str);
//int my_str_reserve(my_str* str, size_t buf_size);
//int my_str_substr_cstr(const my_str* from, char* to, size_t beg, size_t end);
//int my_str_substr(const my_str* from, my_str* to, size_t beg, size_t end);
//int my_str_append_cstr(my_str* str, const char* from);
//int my_str_append(my_str* str, const my_str* from);
//int my_str_insert_cstr(my_str* str, const char* from, size_t pos);
//int my_str_insert(my_str* str, const my_str* from, size_t pos);
//int my_str_insert_c(my_str* str, char c, size_t pos);
//void my_str_clear(my_str* str);
//int my_str_copy(const my_str* from,  my_str* to, int reserve);
//int my_str_popback(my_str* str);
//int my_str_pushback(my_str* str, char c);
//const char* my_str_get_cstr(my_str* str);
//int my_str_putc(my_str* str, size_t index, char c);
int my_str_getc(const my_str* str, size_t index); // Done
//int my_str_empty(const my_str* str); // Done
//size_t my_str_capacity(const my_str* str); // Done
//size_t my_str_size(const my_str* str); // Done
//void my_str_free(my_str* str);
//int my_str_from_cstr(my_str* str, const char* cstr, size_t buf_size);
int my_str_create(my_str* str, size_t buf_size); // Done
#endif //STRLIB_LIBRARY_H