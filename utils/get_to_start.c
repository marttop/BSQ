/*
** EPITECH PROJECT, 2019
** fs_open_file
** File description:
** get to start of a file
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_to_start(char *file_str)
{
    int k = 0;
    for (; file_str[k] != '\n'; k++);
    k++;
    for (; file_str[k] != '\n'; k++);
    k++;
    return (k);
}