/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char	*str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
    {
        len = len + 1;
    }
    return (len);
}
