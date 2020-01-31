/*
** EPITECH PROJECT, 2019
** fs_open_file
** File description:
** get nbr of lines
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int read_nb_lines(char *file_str)
{
    int x = 0, i = 0;
    int count = 0;
    for (; file_str[i] != '\n'; i++) {
        if (file_str[i] > '9' || file_str[i] < '0') {
            error("Wrong size of nb_lines\n", 24);
        }
        x = x * 10 + (file_str[i] - 48);
    }
    i++;
    for (; file_str[i] != '\0'; i++) {
        if (file_str[i] == '\n')
            count++;
    }
    if (count != x)
        error("Missing \\n\n", 12);
    return (x);
}