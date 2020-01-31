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

int get_nb_carac(char *file_str)
{
    int counter = 0, i = 0;
    for (; file_str[i] != '\n'; i++);
    i++;
    for (; file_str[i] != '\n'; counter++, i++);
    return (counter);
}