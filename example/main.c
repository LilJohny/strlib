#include <stdio.h>
#include <stdlib.h>
#include "library.h"

size_t fsize(FILE *fp){
    size_t prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    size_t sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}


int main(int argc, char* argv[]) {
    my_str words;
    my_str sentences;
    FILE* sentences_file = fopen(argv[1], "r");
    FILE* words_file = fopen(argv[2], "r");
    FILE* result_file = fopen(argv[3], "w");
    my_str_create(&sentences, fsize(sentences_file));
    my_str_create(&words, fsize(words_file));
    my_str_read_file(&sentences, sentences_file);
    my_str_read_file(&words, words_file);
    int i = 0;
    size_t beg = 0;
    size_t end = 1;
    while (i!= sentences.size_m-1){
        if(sentences.data[i] == '.' || sentences.data[i] == '!' || sentences.data[i] == '?'){
            end = i;
            my_str sentence;
            my_str_create(&sentence, end - beg);
            my_str_substr(&sentences, &sentence,beg, end );
            int ending_start = end;
            int flag = 0;
            int word_start = 0;
            int word_end = 0;
            int j = 0;
            while (j!=words.size_m-1){
                if (words.data[j] == ' '){
                    word_end = j;
                    my_str word;
                    my_str_create(&word, 50);
                    my_str_substr(&words,&word, word_start, word_end);
                    word_start = word_end+1;
                    if (my_str_find(&sentence, &word, 0)!=(size_t)-1){
                        flag = 1;
                        break;
                    }
                }
                j++;
            }
                int ending_end = ending_start;
                while (sentences.data[ending_end]=='.'||sentences.data[ending_end]=='!'||sentences.data[ending_end]=='?'){
                    ending_end++;
                }
                my_str ending;
                my_str_create(&ending, ending_end - ending_start);
                my_str_substr(&sentences, &ending, (size_t) ending_start, (size_t) ending_end);
                i+=ending.size_m;
                my_str_append(&sentence, &ending);
                beg = end+ending.size_m;
                if (flag){
                    my_str_write_file(&sentence, result_file);
                }

        }
        i++;
    }
    return 0;
}