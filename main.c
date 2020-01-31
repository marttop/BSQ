/*
** EPITECH PROJECT, 2019
** fs_open_file
** File description:
** open_file
*/

#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    if (ac == 2) {
        if (fd >= 0) {
            read_file(fd, av[1]);
        }
        else
            error("Wrong file name\n", 17);
    }
    else
        error("too much arguments\n", 19);
    return (0);
}
