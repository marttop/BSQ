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

int *str_first_line(int *str, int nb_carac, char *file_str)
{
    int i = 0, k = 0;
    str = malloc(sizeof(int) * (nb_carac + 1));
    for (; file_str[i] != '\n'; i++);
    i++;
    for (; file_str[i] != '\n' && file_str[i] != '\0'; i++, k++) {
        if (file_str[i] != '.' && file_str[i] != 'o')
            error("wrong caracter\n", 15);
        str[k] = file_str[i] == '.' ? 1 : 0;
    }
    str[k] = -1;
    if (file_str[i] != '\n')
        error("wrong caracter\n", 15);
    return (str);
}

int **file_to_word_array(int nb_lines, int nb_carac, char *file_str)
{
    int j = 0, i = 1, k = get_to_start(file_str);
    int **str = malloc(sizeof(int *) * (nb_lines + 1) + 1);
    str[0] = str_first_line(str[0], nb_carac, file_str);
    for (; i < nb_lines; i++) {
        str[i] = malloc(sizeof(int) * (nb_carac + 1));
        j = 0;
        str[i][j++] = file_str[k++] == '.' ? 1 : 0;
        for (j = 1; file_str[k] != '\n'; j++, k++) {
            if (file_str[k] != '.' && file_str[k] != 'o')
                error("wrong caracter\n", 16);
            str[i][j] = file_str[k] == '.' ? my_fill_carac(str, i, j) : 0;
        }
        if (j != nb_carac) {
            error("Line lenght error\n", 19);
        }
        str[i][j] = -1, k++;
    }
    str[i] = NULL;
    return (str);
}

int my_fill_carac(int **str, int i, int j)
{
    if (str[i][j - 1] != 0 && str[i - 1][j] != 0 &&
    str[i - 1][j - 1] != 0) {
        if (str[i][j - 1] > str[i - 1][j])
            return (str[i - 1][j] + 1);
        else if (str[i][j - 1] < str[i - 1][j])
            return (str[i][j - 1] + 1);
        else {
            return (str[i - 1][j - 1] < str[i][j - 1] ?
            (str[i - 1][j - 1] + 1) : (str[i][j - 1] + 1));
        }
    }
    else
        return (1);
}

int **print_square(char *file_str)
{
    int nb_lines = read_nb_lines(file_str), nb_carac = get_nb_carac(file_str);
    int **str = file_to_word_array(nb_lines, nb_carac, file_str);
    int biggest = find_my_biggest(str);
    int i = 0, j = 0, x = 0, y = 0, temp = 0;
    for (; (str[i] != NULL); i++) {
        if (i > 0 && str[i - 1][j] == biggest)
            break;
        for (j = 0; (str[i][j] != -1) && (str[i][j] != biggest); j++);
    }
    x = j - biggest, y = (i - 1) - biggest, temp = (i - 1);
    for (; x < j; j--)
        for (i = temp; y < i; i--)
            str[i][j] = -2;
    return (str);
}

void read_file(int fd, char const *filepath)
{
    struct stat sb;
    stat(filepath, &sb);
    long file_size = sb.st_size;
    char *file_str = malloc(file_size + 1);
    read(fd, file_str, file_size);
    file_str[file_size] = '\0';
    close(fd);
    print_final_square(file_str);
    free(file_str);
}