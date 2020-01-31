/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar
*/

#include "../include/my.h"

int my_putchar(unsigned char c)
{
    write(1, &c, 1);
    return (0);
}
