/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** my_getnbr
*/

#include <unistd.h>

int		my_getnbr(char *str)
{
    int		i;
    int		n;

    i = 0;
    n = 0;
    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0')
    {
        if ((str[i] < '0' || str[i] > '9'))
            write(2, "There must be only numbers in the string\n", 41);
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}
