#include "library.h"
#include <stdio.h>


typedef struct
{
    size_t capacity_m; // Розмір блока
    size_t size_m;	   // Фактичний розмір стрічки
    char*  data;	   // Вказівник на блок пам'яті
} string;

void hello(void) {
    printf("Hello, World!\n");
}