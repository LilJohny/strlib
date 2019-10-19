#include <check.h>
#include <stdlib.h>
#include <assert.h>
#include "library.h"

my_str myfailString;
my_str myEmptyString;
my_str myString;
my_str myResizeString;
my_str myConvertString;
my_str mainString;
my_str subString;

void setup(void) {
    my_str_create(&myConvertString, 7);
    my_str_create(&myResizeString, 0);
    my_str_create(&myEmptyString, 0);
    my_str_create(&myString, 10);
    my_str_create(&mainString, 10);
    my_str_create(&mainString, 3);
    my_str_create(&myfailString, 3);
    my_str_create(&subString, 3);

    my_str_from_cstr(&myConvertString, "convert", 7);
    my_str_from_cstr(&myString, "characters", 10);
    my_str_from_cstr(&mainString, "characters", 10);
    my_str_from_cstr(&subString, "act", 3);
    my_str_from_cstr(&myfailString, "pdf", 3);
}

void teardown() {
    my_str_free(&myEmptyString);
    my_str_free(&myResizeString);
    my_str_free(&myConvertString);
    my_str_free(&myString);
}

void size() {
    my_str_resize(&myResizeString, 66, '0');
    assert(my_str_size(&myResizeString) == 66);
}


void capacity() {
    my_str_resize(&myResizeString, 66, '0');
    assert(my_str_capacity(&myResizeString) == 132);
}


void empty_True() {
    assert(my_str_empty(&myEmptyString) == 1);
}


void empty_False() {
    assert(my_str_empty(&myString) == 0);
}


void empty_Resized() {
    assert(my_str_empty(&myResizeString) == 1);
}


void getch() {
    assert(my_str_getc(&myString, 3) == (int) 'r');
}


void getc_OutOfString() {
    assert(my_str_getc(&myEmptyString, 3) == -1);
}


void getc_ZeroIndex() {
    assert(my_str_getc(&myEmptyString, 0) == -1);
}


void getc_ZeroChar() {
    assert(my_str_getc(&myString, 10) == -1);
}


void putc_Success() {
    assert(my_str_getc(&myString, 1) == (int) 'h');

    int outcome = my_str_putc(&myString, 1, 'H');

    assert(outcome == 0);
    assert(my_str_getc(&myString, 1) == (int) 'H');
}


void putc_Failure() {
    int outcome = my_str_putc(&myString, 15, 'H');

    assert(outcome == -1);
}


void get_cstr() {
    const char *compstr = "convert";
    assert(strcmp(my_str_get_cstr(&myConvertString), compstr) == 0);
}


void get_cstr_Empty() {
    assert(strcmp(my_str_get_cstr(&myEmptyString), "") == 0);
}


void pushback_Success() {
    int outcome = my_str_pushback(&myString, 's');

    assert(outcome == 0);
    assert(my_str_getc(&myString, myString.size_m - 1) == (int) 's');
}


void pushback_NullPointer() {
    my_str *myNullString;
    myNullString = NULL;
    int outcome = my_str_pushback(myNullString, 's');

    assert(outcome == -1);
}


void popback_Success() {
    int outcome = my_str_popback(&myConvertString);

    assert(outcome == (int) 't');
    assert(strcmp(my_str_get_cstr(&myConvertString), "conver") == 0);
}


void popback_NullPointer() {
    my_str *myNullString = NULL;
    int outcome = my_str_popback(myNullString);
    assert(outcome == -1);
}


void popback_Empty() {
    int outcome = my_str_popback(&myEmptyString);

    assert(outcome == -2);
}


void clear() {
    assert(my_str_empty(&myConvertString) == 0);
    my_str_clear(&myConvertString);
    assert(my_str_empty(&myConvertString) == 1);
}

void reserve() {
    my_str myReserveString;
    my_str_create(&myReserveString, 5);
    my_str_from_cstr(&myReserveString, "apple", 5);

    assert(myReserveString.capacity_m == 10);
    my_str_reserve(&myReserveString, 10);
    assert(myReserveString.capacity_m == 10);
    assert(strcmp(my_str_get_cstr(&myReserveString), "apple") == 0);
}


void resize() {
    char sym = '0';
    int length = 12;
    assert(my_str_resize(&myString, length, sym) == 0);
    for (size_t i = 10; i < length; i++) {
        assert(my_str_getc(&myString, i) == '0');
    }
}

void find_Success() {
    size_t expected = 4;
    size_t outcome = my_str_find(&mainString, &subString, 0);
    assert(outcome == expected);
}


void find_Failure() {
    size_t expected = -1;
    size_t outcome = my_str_find(&mainString, &myfailString, 0);
    assert(outcome == expected);
}


void find_TooBig() {
    size_t expected = -1;
    size_t outcome = my_str_find(&subString, &myfailString, 0);
    assert(outcome == expected);
}


void cmp_cstr_Equal() {
    my_str compStr1;
    my_str_create(&compStr1, 5);
    my_str_from_cstr(&compStr1, "Hello", 5);

    int res = my_str_cmp_cstr(&compStr1, "Hello");
    assert(res == 0);
}

void cmp_cstr_Greater() {
    my_str compStr1;
    my_str_create(&compStr1, 5);
    my_str_from_cstr(&compStr1, "Hello", 5);

    int res = my_str_cmp_cstr(&compStr1, "hello");
    assert(res == -1);
}

void cmp_cstr_Less() {
    my_str compStr1;
    my_str_create(&compStr1, 5);
    my_str_from_cstr(&compStr1, "Hello", 5);

    int res = my_str_cmp_cstr(&compStr1, "hello");
    assert(res == -1);
}

void cmp_cstr_LongBigger() {
    my_str compStr1;
    my_str_create(&compStr1, 5);
    my_str_from_cstr(&compStr1, "Hello", 5);

    int res = my_str_cmp_cstr(&compStr1, "He");
    assert(res == 1);
}


void cmp_cstr_ShortBigger() {
    my_str compStr1;
    my_str_create(&compStr1, 5);
    my_str_from_cstr(&compStr1, "Hello", 5);

    int res = my_str_cmp_cstr(&compStr1, "he");
    assert(res == -1);
}

void find_c_Success() {
    int res = my_str_find_c(&myString, 'a', 0);
    assert(res == 2);
}

void find_c_Failure() {
    size_t res = my_str_find_c(&myString, 'q', 0);
    assert(res == (size_t) -1);
}

void find_c_NotStartSuccess() {
    int res = my_str_find_c(&myString, 'a', 3);
    assert(res == 4);
}

void find_c_NotStartFailure() {
    int res = my_str_find_c(&myString, 'w', 3);
    assert(res == -1);
}

int testPredicate(int value) {
    if (value >= (int) 'Q') {
        return 1;
    } else {
        return 0;
    }
}

void find_if_Success() {
    my_str testString;
    my_str_create(&testString, 5);
    my_str_from_cstr(&testString, "HEllo", 5);

    size_t res = my_str_find_if(&testString, testPredicate);
    assert(res == (size_t) 2);
}

void find_if_FirstSuccess() {
    my_str testString;
    my_str_create(&testString, 5);
    my_str_from_cstr(&testString, "hello", 5);

    size_t res = my_str_find_if(&testString, testPredicate);
    assert(res == (size_t) 0);
}

void find_if_Failure() {
    my_str testString;
    my_str_create(&testString, 5);
    my_str_from_cstr(&testString, "HELLO", 5);

    size_t res = my_str_find_if(&testString, testPredicate);
    assert(res == (size_t) -1);
}

void shrink_to_fit() {
    my_str shrinkString;
    my_str_create(&shrinkString, 5);
    my_str_from_cstr(&shrinkString, "Hello", 5);

    assert(shrinkString.capacity_m == 10);

    int res = my_str_shrink_to_fit(&shrinkString);

    assert(shrinkString.capacity_m == shrinkString.size_m);
    assert(res == 0);
}

void substr_Success() {
    my_str resString;
    my_str_create(&resString, 3);
    int res = my_str_substr(&mainString, &resString, 4, 7);
    assert(res == 0);
    assert(strcmp(my_str_get_cstr(&resString),"act")==0);
}

void substr_EndOutOFStr() {
    my_str resString;
    my_str_create(&resString, 3);
    int res = my_str_substr(&mainString, &resString, 4, 33);
    assert(res == 0);
    assert(strcmp(my_str_get_cstr(&resString), "acters") == 0);
}

void substr_BegOutOFStr() {
    my_str resString;
    my_str_create(&resString, 3);
    int res = my_str_substr(&mainString, &resString, 20, 7);
    assert(res == -1);
}

void substr_ExpandBuffer() {
    my_str resString;
    my_str_create(&resString, 1);
    int res = my_str_substr(&mainString, &resString, 4, 7);
    assert(res == 0);
    assert(strcmp(my_str_get_cstr(&resString), "act") == 0);
    assert(resString.capacity_m == 6);
    assert(resString.size_m == 3);
}

int main() {
    void (*test_arr[])() = {size, capacity, empty_True, empty_False, empty_Resized, get_cstr, get_cstr_Empty,
                            getc_OutOfString, getc_ZeroChar, getc_ZeroIndex, getch, cmp_cstr_ShortBigger,
                            cmp_cstr_LongBigger, cmp_cstr_Less, cmp_cstr_Greater, cmp_cstr_Equal, find_TooBig,
                            find_Failure, find_Success, resize, reserve, clear, popback_Empty, popback_NullPointer,
                            popback_Success, pushback_NullPointer, pushback_Success, putc_Failure, putc_Success,
                            find_c_NotStartFailure, find_c_NotStartSuccess, find_c_Failure, find_c_Success,
                            find_if_Failure, find_if_FirstSuccess, find_if_Success, shrink_to_fit, substr_ExpandBuffer,
                            substr_BegOutOFStr, substr_EndOutOFStr, substr_Success};
    for (int i = 0; i < 41; ++i) {
        setup();
        (*test_arr[i])();
        teardown();
    }


    return 0;
}