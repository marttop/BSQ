/*
** EPITECH PROJECT, 2019
** fs_open_file
** File description:
** open_file
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


unsigned char remake(int c)
{
    if (c != -2 && c != 0)
        return ('.');
    if (c == 0)
        return ('o');
    if (c == -2)
        return ('x');
    return ('.');
}

void print_final_square(char *file_str)
{
    int **str = print_square(file_str);
    int nb_carac = get_nb_carac(file_str);
    unsigned char *new_str = malloc(sizeof(unsigned char) * (nb_carac + 1));
    int i = 0, j = 0;
    for (; str[i] != NULL; i++) {
        for (j = 0; str[i][j] != -1; j++) {
            new_str[j] = remake(str[i][j]);
        }
        new_str[j] = '\0';
        write(1, new_str, nb_carac);
        my_putchar('\n');
        free(str[i]);
    }
    free(new_str);
    free(str);
}