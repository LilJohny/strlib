#include "check.h"
#include "library.c"

my_str myString;

void setup(void) {
    my_str_create(&myString, 0);
}

void teardown(void) {
    my_str_free(&myString);
}

START_TEST (size) {

}

START_TEST (capacity) {

}

START_TEST (empty) {

}

START_TEST (getc) {

}

START_TEST (putc) {

}

START_TEST (get_cstr) {

}

START_TEST (pushback) {

}

START_TEST ([popback]) {

}

START_TEST (copy) {

}

START_TEST (clear) {

}

START_TEST (insert_c) {

}

START_TEST (insert) {

}

START_TEST (insert_cstr) {

}

START_TEST (append) {

}

START_TEST (append_cstr) {

}

START_TEST (substr) {

}

START_TEST (substr_cstr) {

}

START_TEST (reserve) {

}

START_TEST (shrink_to_fit) {

}

START_TEST (resize) {

}

START_TEST (find) {

}

START_TEST (cmp) {

}

START_TEST (cmp_cstr) {

}

START_TEST (find_c) {

}

START_TEST (find_if) {

}

START_TEST (read_file) {

}

START_TEST (read) {

}

START_TEST (write_file) {

}

START_TEST (write) {

}

START_TEST (delim) {

}


int main(void) {
    return 0;
}