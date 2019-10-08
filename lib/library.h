#ifndef STRLIB_LIBRARY_H
#define STRLIB_LIBRARY_H
#include <stddef.h>
#include <bits/types/FILE.h>
typedef struct
{
    size_t capacity_m; // Розмір блока
    size_t size_m;	   // Фактичний розмір стрічки
    char*  data;	   // Вказівник на блок пам'яті
} string;
int my_str_read_file_delim(string* str, FILE* file, char delimiter);
int my_str_write(const string* str, FILE* file);
int my_str_write_file(const string* str, FILE* file);
int my_str_read(string* str);
int my_str_read_file(string* str, FILE* file);
size_t my_str_find_if(const string* str, int (*predicat)(int));
size_t my_str_find_c(const string* str, char tofind, size_t from);
int my_str_cmp_cstr(const string* str1, const char* cstr2);
int my_str_cmp(const string* str1, const string* str2);
size_t my_str_find(const string* str, const string* tofind, size_t from);
int my_str_resize(string* str, size_t new_size, char sym);
int my_str_shrink_to_fit(string* str);
int my_str_reserve(string* str, size_t buf_size);
int my_str_substr_cstr(const string* from, char* to, size_t beg, size_t end);
int my_str_substr(const string* from, string* to, size_t beg, size_t end);
int my_str_append_cstr(string* str, const char* from);
int my_str_append(string* str, const string* from);
int my_str_insert_cstr(string* str, const char* from, size_t pos);
int my_str_insert(string* str, const string* from, size_t pos);
int my_str_insert_c(string* str, char c, size_t pos);
void my_str_clear(string* str);
int my_str_copy(const string* from,  string* to, int reserve);
int my_str_popback(string* str);
int my_str_pushback(string* str, char c);
const char* my_str_get_cstr(string* str);
int my_str_putc(string* str, size_t index, char c);
int my_str_getc(const string* str, size_t index);
int my_str_empty(const string* str);
size_t my_str_capacity(const string* str);
size_t my_str_size(const string* str);
void my_str_free(string* str);
int my_str_from_cstr(string* str, const char* cstr, size_t buf_size);
void my_str_free(string* str);
int my_str_create(string* str, size_t buf_size);



#endif //STRLIB_LIBRARY_H