/*
** EPITECH PROJECT, 2019
** fs_open_file
** File description:
** open_file
*/

#include "../include/my.h"

void error(char const *msg, int len_msg)
{
    write(2, msg, len_msg);
    exit(84);
}