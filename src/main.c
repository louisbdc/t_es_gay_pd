/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    int ch;
    int lev = 0;

    /*if (av[1][0] == '-' && av[1][1] == 'h') {
        describe();
    }*/
    initscr();
    keypad(stdscr, TRUE);
    if (!has_colors()) {
        endwin();
        write(2, "Error initialising colors\n", 26);
        exit(1);
    }
    start_color();
    palette();
    Level(lev);
    while ((ch = getch()) != ' ') {
        Play(ch);
    }
    endwin();
    return 0;
}

int describe(void)
{
    my_putstr("USAGE\n");
    my_putstr("         ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("         map  file representing the warehouse map, containing ‘#’ for walls,\n");
    my_putstr("             ‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.\n");
    return 0;
}