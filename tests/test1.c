/*
** EPITECH PROJECT, 2019
** uni_tests
** File description:
** first_uni_test
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"

first_test(main, first)
{
    char const *filepath = "maps-intermediate/mouli_maps/intermediate_map_200_200";
    char const *result = "maps-intermediate/mouli_maps_solved/intermediate_map_200_200";
    int fd = open(filepath, O_RDONLY);
    read_file(fd, filepath);
    cr_assert(filepath);
}