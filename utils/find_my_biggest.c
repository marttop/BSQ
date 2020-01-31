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

int find_my_biggest(int **str)
{
    int biggest = 0;

    for (int i = 0; str[i] != NULL; i++) {
        for (int j = 0; str[i][j] != -1; j++) {
            biggest = (str[i][j] > biggest && str[i][j] != 0) ?
            (str[i][j]) : biggest;
        }
    }
    return (biggest);
}