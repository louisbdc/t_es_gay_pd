/*
** EPITECH PROJECT, 2021
** solo
** File description:
** stumper
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct sokoban
{
    int x;
    int y;
    int n;
} t_soko;

struct Object
{
    int xPosition;
    int yPosition;
    unsigned char zn;
    chtype ozn;
};

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *str);
int	my_put_nbr(int nb);

void levList(int *h, int *w, int *array, t_soko soko);
void palette(void);
void Level(int n);
void Play(int input);
int  describe(void);
void Play_2(char *str);

#endif
