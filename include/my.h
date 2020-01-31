/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H
#include <stdlib.h>
#include <unistd.h>

void error(char const *msg, int len_msg);
int *str_first_line(int *str, int nb_carac, char *file_str);
int **file_to_word_array(int nb_lines, int nb_carac, char *file_str);
int my_fill_carac(int **str, int i, int j);
int **print_square(char *file_str);
void read_file(int fd, char const *filepath);
int find_my_biggest(int **str);
int get_nb_carac(char *file_str);
int read_nb_lines(char *file_str);
int get_to_start(char *file_str);
int my_putchar(unsigned char c);
unsigned char remake(int c);
void print_final_square(char *file_str);

#endif
